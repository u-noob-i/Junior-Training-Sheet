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

int n, m, i, j;
string s, p;
long long M = 1000000007;

void solve(int T)
{
    cin >> n;
    int l = 1, r = n, mid, ans = -1;
    while (l < r)
    {
        mid = (l + r) / 2;
        cout << "? " << l << " " << r << "\n";
        cout.flush();
        cin >> m;
        if (r == l + 1)
        {
            if (m == r)
                ans = l;
            else
                ans = r;
            break;
        }
        if (m < mid)
        {
            if (l == mid - 1)
            {
                l = mid;
                continue;
            }
            cout << "? " << l << " " << mid - 1 << "\n";
            cout.flush();
            cin >> i;
            if (i == m)
                r = mid - 1;
            else
                l = mid;
        }
        else
        {
            cout << "? " << mid << " " << r << "\n";
            cout.flush();
            cin >> i;
            if (i == m)
                l = mid;
            else
                r = mid - 1;
        }
    }
    if (ans == -1)
        ans = l;
    cout << "! " << ans << "\n";
    cout.flush();
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