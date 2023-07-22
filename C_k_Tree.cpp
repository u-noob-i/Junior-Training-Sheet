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
long long modu = 1000000007, f = 10000000000007;

void solve(int T)
{
    long long k, d;
    cin >> n >> k >> d;
    vector<long long> dp(n + 1, 0), dpn(n + 1, 0);
    dp[1] = dpn[1] = 1;
    if (d == 1)
        dpn[1] = 0;
    for (i = 2; i <= n; i++)
    {
        if (i <= k)
            dp[i]++;
        for (j = i - 1; j > 0; j--)
        {
            if (i - j > k)
                break;
            dp[i] += dp[j];
            dp[i] %= modu;
        }
        if (i < d)
            dpn[i]++;
        for (j = i - 1; j > 0; j--)
        {
            if (i - j >= d)
                break;
            dpn[i] += dpn[j];
            dpn[i] %= modu;
        }
        // cout << dp[i] << " " << dpn[i] << "\n";
    }
    long long ans = (dp[n] - dpn[n]) % modu;
    if (ans < 0)
        ans += modu;
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