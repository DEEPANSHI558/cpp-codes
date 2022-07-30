#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int helper(int n, int e, vector<int> &a)
{
    int keep = n;
    int ans = 0;
    sort(a.begin(), a.end());
    for (int i = 0; i < e; i++)
    {
        int min2 = 0;
        while (n > 0 && min2 < 2)
        {
            ans += a[i];
            min2++;
            n -= a[i];
        }
    }
    if (ans > n && n != 0)
    {
        return -1;
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    int e;
    cin >> e;
    vector<int> a(e, 0);
    for (int i = 0; i < e; i++)
    {
        cin >> a[i];
    }
    cout << helper(n, e, a);
    return 0;
}