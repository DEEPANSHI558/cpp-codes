class Solution
{
public:
    bool isSafe(int row, int col, vector<string> &board, int n)
    {
        //         check the row;
        for (int c = col; c >= 0; c--)
        {
            if (board[row][c] == 'Q')
            {
                return false;
            }
        }
        //      we dont have to check the column
        //      we dont have to check the r>row
        //      checking upper diagonal
        int dupcol = col;
        int duprow = row;
        while (row >= 0 && col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            row--;
            col--;
        }
        //         lower diagonal
        row = duprow;
        col = dupcol;
        while (row < n && col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            row++;
            col--;
        }
        return true;
    }
    void helper(vector<vector<string>> &output, vector<string> &board, int n, int col)
    {
        if (col == n)
        {
            output.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++)
        {
            if (isSafe(row, col, board, n))
            {
                board[row][col] = 'Q';
                helper(output, board, n, col + 1);
                board[row][col] = '.'; // so that dusra combination try ker sakein hum
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> output;
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++)
        {
            board[i] = s;
        }
        helper(output, board, n, 0);
        return output;
    }
};