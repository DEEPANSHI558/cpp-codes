class Solution
{
public:
    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board);
    }
    bool solve(vector<vector<char>> &board)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == '.')
                {
                    for (char c = '1'; c <= '9'; c++)
                    {
                        if (isPossible(c, i, j, board))
                        {
                            board[i][j] = c;
                            if (solve(board) == true)
                                return true; // if it returns true means on of the numbers can be filled in the emptcolumn
                            board[i][j] = '.';
                        }
                    }
                    return false; // return false means no number can be filled in the empty colum then return to where you started and then jahan se chorh tha wahan se fill firse
                }
            }
        }
        return true; // koi khali nahi mila means it is filled and return true
    }
    bool isPossible(char c, int row, int col, vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            //              checking for column
            if (board[row][i] == c)
                return false;
            if (board[i][col] == c)
                return false;
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
                return false;
        }
        return true;
    }
};