#include <vector>
bool helper(string pattern, string text, int n, int m)
{
    if (n == 0 && m == 0)
        return true;
    if (n == 0 && m > 0)
        return false; // means the pattern is exhausted remaining but the string is still not  empty
    if (m == 0 && n > 0)
    { // means the pattern has abhi bhi but the string is empty but it can be a case where al the pattern has *** means it can still match
        for (int k = 1; k <= n; k++)
        {
            if (pattern[k - 1] != '*')
                return false;
        }
        return true;
    }
    if (pattern[n - 1] == text[m - 1] || pattern[n - 1] == '?')
    {
        return helper(pattern, text, n - 1, m - 1);
    }
    if (pattern[n - 1] == '*')
    {
        return helper(pattern, text, n - 1, m) | helper(pattern, text, n, m - 1);
    }
    return false;
}
bool wildcardMatching(string pattern, string text)
{
    // Write your code here.
    int n = pattern.size();
    int m = text.size();
    //   return helper(pattern,text,pn,tm);

    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    dp[0][0] = true;
    for (int j = 1; j <= m; j++)
        dp[0][j] = false;
    for (int i = 1; i <= n; i++)
    {
        bool flag = true;
        for (int k = 1; k <= i; k++)
        {
            if (pattern[k - 1] != '*')
            {
                flag = false;
                break;
            }
        }
        dp[i][0] = flag;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (pattern[i - 1] == text[j - 1] || pattern[i - 1] == '?')
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            if (pattern[i - 1] == '*')
            {
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            }
        }
    }
    return dp[n][m];
}
