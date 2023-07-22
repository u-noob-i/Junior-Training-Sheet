#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <numeric>

using namespace std;

int n, m, i, j;

void solve(int T)
{
    cin >> n;
    vector<int> a(n);
    for (i = 0; i < n; i++)
        cin >> a[i];
    bool f = 1;
    for (i = 0; i < n - 1; i++)
        if (a[i] > a[i + 1])
        {
            f = 0;
            break;
        }
    if (f)
    {
        cout << 0;
        return;
    }
    sort(a.begin(), a.end());
    double p = 1;
    for (double x = 1; x <= n; x++)
        p *= x;
    for (i = 0; i < n; i++)
    {
        double l = 1;
        while (i < n - 1 && a[i] == a[i + 1])
        {
            i++;
            l++;
        }
        for (double x = 1; x <= l; x++)
            p /= x;
    }
    cout << setprecision(15) << p;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    for (int i = 1; i <= t; i++)
    {
        solve(t);
        cout << "\n";
    }
}