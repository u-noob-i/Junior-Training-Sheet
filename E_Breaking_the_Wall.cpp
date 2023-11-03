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
#include <stack>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define ll long long
#define rep(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define irep(a, b, c) for (int(a) = (b); (a) >= (c); --(a))

ll M = 998244353;

void solve(int T)
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    int ans = INT_MAX;
    vector<int> val(n);
    rep(i, 0, n) val[i] = (a[i] + 1) / 2;
    sort(val.begin(), val.end());
    ans = val[0] + val[1];
    rep(i, 0, n - 1)
    {
        if (i)
            ans = min(ans, (a[i - 1] + a[i + 1] + 1) / 2);
        int x = max(a[i], a[i + 1]), y = min(a[i], a[i + 1]);
        if (x - y >= y)
            ans = min(ans, (x + 1) / 2);
        else
        {
            int temp = x - y;
            y -= temp;
            x -= 2 * temp;
            ans = min(ans, temp + (x + y + 2) / 3);
        }
    }
    cout << ans;
}

int main()
{
    cin.sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    t = 1;
    for (int T = 1; T <= t; T++)
    {
        solve(T);
        cout << "\n";
    }
}