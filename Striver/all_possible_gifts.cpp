#include <bits/stdc++.h>
using namespace std;
void helper(vector<int> &array, int k, int index, vector<int> ans, int n, vector<vector<int>> &output)
{
    if (k == 0)
    {
        output.push_back(ans);
        return;
    }
    if (index == n)
    {
        return;
    }
    // take
    ans.push_back(array[index]);
    helper(array, k - 1, index, ans, n, output);
    ans.pop_back();
    // not take
    helper(array, k, index + 1, ans, n, output);
}
int main()
{
    int n;
    int k;
    cin >> n >> k;
    vector<int> array;
    for (int i = 1; i <= n; i++)
    {
        array.push_back(i);
    }
    vector<int> ans;
    vector<vector<int>> output;
    int count = 0;
    helper(array, k, 0, ans, n, output);
    for (int i = 0; i < output.size(); i++)
    {
        int flag = true;
        for (int j = 1; j < output[i].size(); j++)
        {
            if (output[i][j] % output[i][j - 1] != 0)
            {
                flag = false;
            }
        }
        if (flag)
        {
            count++;
        }
    }
    cout << count;
    return 0;
}