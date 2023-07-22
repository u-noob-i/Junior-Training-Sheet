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
#include <queue>
#include <climits>
#include <cfloat>
#include <sstream>

using namespace std;

int n, m, i, j, k;
string s, p;
long long M = 1000000007;

void solve(int T)
{
    cin >> n;
    vector<long long> a(n + 1, 0), pref(n + 1, 0);
    for (i = 1; i <= n; i++)
    {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }
    for (i = 1; i <= n; i++)
    {
        int l = 1, r = n, mid;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            long long x = pref[mid - 1], y = pref[n] - pref[mid - 1];
            if (i < mid)
                x -= a[i];
            else
                y -= a[i];
            if (x + a[i] == y)
            {
                cout << "YES";
                return;
            }
            if (x + a[i] >= y)
                r = mid - 1;
            else
                l = mid + 1;
        }
        l = 2, r = n, mid;
        while (l <= r)
        {
            mid = (r + l) / 2;
            long long x = pref[mid - 1], y = pref[n] - pref[mid - 1];
            if (i < mid)
                x -= a[i];
            else
                y -= a[i];
            if (x == y + a[i])
            {
                cout << "YES";
                return;
            }
            if (x >= y + a[i])
                r = mid - 1;
            else
                l = mid + 1;
        }
    }
    cout << "NO";
    return;
}

int main()
{
    cin.sync_with_stdio(false);
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