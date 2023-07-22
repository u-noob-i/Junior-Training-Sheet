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
    if (n <= 5)
        cout << -1 << "\n";
    else
    {
        for (i = 2; i <= n - 2; i++)
            cout << 1 << " " << i << "\n";
        cout << 2 << " " << n - 1 << "\n"
             << 2 << " " << n << "\n";
    }
    for (i = 2; i <= n; i++)
        cout << 1 << " " << i << "\n";
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