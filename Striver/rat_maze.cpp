class Solution
{
public:
    void helper(vector<vector<int>> &m, string ans, vector<string> &output, int n, int row, int col, vector<vector<int>> &visited)
    {
        if (row == n - 1 && col == n - 1)
        {
            output.push_back(ans);
            return;
        }
        // directions it can move is 4
        // lexicographical order D-L-R-U

        // down we try

        if (row + 1 < n && !visited[row + 1][col] && m[row + 1][col] == 1)
        {
            visited[row][col] = 1;
            helper(m, ans + 'D', output, n, row + 1, col, visited);
            visited[row][col] = 0;
        }

        // left we try

        if (col - 1 >= 0 && !visited[row][col - 1] && m[row][col - 1] == 1)
        {
            visited[row][col] = 1;
            helper(m, ans + 'L', output, n, row, col - 1, visited);
            visited[row][col] = 0;
        }

        // right we try

        if (col + 1 < n && !visited[row][col + 1] && m[row][col + 1] == 1)
        {
            visited[row][col] = 1;
            helper(m, ans + 'R', output, n, row, col + 1, visited);
            visited[row][col] = 0;
        }

        // upwards we try

        if (row - 1 >= 0 && !visited[row - 1][col] && m[row - 1][col] == 1)
        {
            visited[row][col] = 1;
            helper(m, ans + 'U', output, n, row - 1, col, visited);
            visited[row][col] = 0;
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        // Your code goes here
        vector<string> output;

        vector<vector<int>> visited(n, vector<int>(n, 0));
        if (m[0][0] == 1)
            helper(m, "", output, n, 0, 0, visited);
        return output;
    }
};
