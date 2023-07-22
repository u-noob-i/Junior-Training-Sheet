#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <queue>
#include <climits>
#include <sstream>
#include <tuple>
#include <iomanip>

using namespace std;

int n, m, i, j;
string s;
long long modu = 100000000;

void solve(int T)
{
    cin >> n;
    vector<long long> a(n);
    for (i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    long long ans = a[n - 1], cur = 0;
    for (i = 0; i < n; i++)
        cur += a[n - 1] - a[i];
    long long x = ans - cur, y = n - 1;
    long long l = 0, r = 1000000000000, mid, ret = -1;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (mid * (n - 1) >= x)
        {
            ret = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << ans + max(0ll, ret);
}

int main()
{

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    t = 1;
    for (int q = 1; q <= t; q++)
    {
        solve(t);
    }
}