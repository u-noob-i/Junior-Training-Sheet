#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <utility>

using namespace std;

int n, m, i, j;

void solve(int T)
{
    cin >> n >> m;
    vector<long long> a(n);
    for (i = 0; i < n; i++)
        cin >> a[i];
    int x = 0;
    for (i = 1; i < n; i++)
        if (a[i] < a[x])
            x = i;
    long long temp = 0, val = a[x];
    for (i = 0; i < n; i++)
    {
        a[i] -= val - 1;
        temp += val - 1;
    }
    for (i = m - 1;; i--)
    {
        if (i < 0)
            i = n - 1;
        if (!a[i])
        {
            a[i] = temp;
            break;
        }
        a[i]--;
        temp++;
    }
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
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