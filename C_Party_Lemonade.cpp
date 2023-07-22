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
    long long l;
    cin >> n >> l;
    map<long long, long long> dp;
    for (i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        if (!dp[1ll << i])
            dp[1ll << i] = x;
        else
            dp[1ll << i] = min(dp[1ll << i], x);
        for (j = i + 1; j <= 32; j++)
            if (!dp[1ll << j])
                dp[1ll << j] = dp[1ll << (j - 1)] * 2;
            else
                dp[1ll << j] = min(dp[1ll << j], dp[1ll << (j - 1)] * 2);
    }
    long long ans = 0;
    for (long long x = 1; x <= 1ll << 32; x *= 2ll)
    {
        if ((l & x) != 0)
            ans += dp[x];
        else if (dp[x] < ans)
            ans = dp[x];
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
    for (int i = 1; i <= t; i++)
    {
        solve(t);
    }
}