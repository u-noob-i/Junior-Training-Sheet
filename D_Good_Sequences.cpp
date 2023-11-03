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

ll M = 1000000007;

int spf[100001];

void sieve()
{
    rep(i, 0, 100001) spf[i] = i;
    for (int i = 2; i < 100001; i++)
        if (spf[i] == i)
            for (int j = i + i; j < 100001; j += i)
                if (spf[j] == j)
                    spf[j] = i;
    return;
}

vector<int> getfact(int x)
{
    vector<int> ret;
    while (x > 1)
    {
        int y = spf[x];
        ret.push_back(y);
        while (x % y == 0)
            x /= y;
    }
    return ret;
}

void solve(int T)
{
    sieve();
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    if (n == 1)
    {
        cout << 1;
        return;
    }
    vector<int> dp(100001, 0), ans(n, 0);
    rep(i, 0, n)
    {
        ans[i] = 1;
        vector<int> facts = getfact(a[i]);
        for (auto x : facts)
            ans[i] = max(ans[i], dp[x] + 1);
        for (auto x : facts)
            dp[x] = max(dp[x], ans[i]);
    }
    sort(ans.begin(), ans.end());
    cout << ans[n - 1];
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