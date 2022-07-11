#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int v, h, nh;
    cin >> v >> h >> nh;
    vector<int> villian(v, 0);
    for (int i = 0; i < v; i++)
    {
        cin >> villian[i];
    }
    int ans = 0;
    vector<int> hero(h, nh);
    for (int i = 0; i < v; i++)
    {
        if ((float)(1.0) * villian[i] / hero[i] > 0.01)
        {
            cout << (float)(1.0) * villian[i] / hero[i];
            ans++;
        }
    }
    cout << ans;
    return 0;
}