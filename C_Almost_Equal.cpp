#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <set>

using namespace std;

int n, m, i, j;

void solve(int T)
{
    cin >> n;
    if (n % 2 == 0)
    {
        cout << "NO";
        return;
    }
    cout << "YES\n";
    int t = 0;
    vector<int> ans(2 * n);
    for (i = 0, j = 1; i < n; i++, j += 2)
    {
        if (!t)
        {
            ans[i] = j;
            ans[i + n] = j + 1;
            t = 1;
        }
        else
        {
            ans[i] = j + 1;
            ans[i + n] = j;
            t = 0;
        }
    }
    for (i = 0; i < 2 * n; i++)
        cout << ans[i] << " ";
}

int main()
{
    int t;
    t = 1;
    for (int p = 1; p <= t; p++)
    {
        solve(p);
        cout << "\n";
    }
}