#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <iomanip>
#include <numeric>
#include <queue>
#include <climits>
#include <cfloat>
#include <sstream>

using namespace std;

int n, m, i, j, k;
string s;
long long M = 1000000007;

void solve(int T)
{
    cin >> n >> m;
    long long ans = 0, l = 2, r = m, mid, ind = -1;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (mid * (mid - 1) + mid - 1 <= n)
        {
            ind = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    if (ind == -1)
    {
        cout << 0;
        return;
    }
    ans = ind * (ind - 1) / 2;
    // cout << ans << " ";
    ind++;
    while (ind <= m)
    {
        long long x = -1, y = -1;
        l = 0, r = ind;
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (ind * mid + mid <= n)
            {
                x = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        l = ind, r = m;
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (mid * x + x <= n)
            {
                y = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        ans += (y - ind + 1) * x;
        ind = y + 1;
    }
    cout << ans;
}

int main()
{
    cin.sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve(t);
        cout << "\n";
    }
}