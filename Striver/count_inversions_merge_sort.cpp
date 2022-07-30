#include <bits/stdc++.h>
using namespace std;
struct exercise
{
    int energy;
    int times;
};
bool compare(exercise &a, exercise &b)
{
    return a.energy > b.energy;
}
int main()
{
    int n, energy;
    cin >> energy >> n;
    vector<int> energies;
    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;
        energies.push_back(c);
    }
    vector<exercise> k;
    for (int i = 0; i < n; i++)
    {
        struct exercise a;
        a.energy = energies[i];
        a.times = 2;
        k.push_back(a);
    }
    sort(k.begin(), k.end(), compare);
    int i = 0;
    int currentEnergy = 0;
    int count = 0;
    while (i < n)
    {
        if (currentEnergy + k[i].energy <= energy && k[i].times != 0)
        {
            currentEnergy += k[i].energy;
            k[i].times--;
            count++;
        }
        else
        {
            i++;
        }
    }
    if (currentEnergy < energy)
    {
        cout << -1;
    }
    else
    {
        cout << count;
    }

    return 0;
}