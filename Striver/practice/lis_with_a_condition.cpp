#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    vector<int> dp(n, 1);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i] && ((arr[j] & arr[i]) * 2 < (arr[j] | arr[i])))
            {
                dp[i] = max(1 + dp[j], dp[i]);
            }
        }
    }
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (maxi < dp[i])
        {
            maxi = dp[i];
        }
    }
    cout << maxi;
    return 0;
}