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

using namespace std;

int n, m, i, j;
string s;
long long modu = 1000000007;

void solve(int T)
{
    long long x1, x2, y1, y2, x, y;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    vector<pair<long long, long long>> a(n);
    for (i = 0; i < n; i++)
    {
        cin >> x >> y;
        a[i].first = ((x - x1) * (x - x1)) + ((y - y1) * (y - y1));
        a[i].second = ((x - x2) * (x - x2)) + ((y - y2) * (y - y2));
    }
    a.push_back({0, 0});
    long long ans = LLONG_MAX, r1, r2;
    for (i = 0; i <= n; i++)
    {
        r1 = a[i].first;
        r2 = 0;
        for (j = 0; j <= n; j++)
            if (a[j].first > r1)
                r2 = max(r2, a[j].second);
        ans = min(ans, r1 + r2);
    }
    cout << ans;
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