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

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int n, m, i, j, k;
string s;
ll M = 1000000007;

vector<ll> dp(2000001, 0);

void solve(int T)
{
    cin >> n;
    cout << dp[n];
}

int main()
{
    cin.sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // for (i = 3; i <= 2000000; i++)
    // {
    //     dp[i] = (dp[i - 1] + 2 * dp[i - 2] + (i % 3 == 0 ? 4 : 0)) % M;
    // }

    dp[3] = 4;
    for (i = 4; i <= 2000000; i++)
        dp[i] = max((dp[i - 1] + 2 * dp[i - 2]) % M, (dp[i - 2] + 4 * dp[i - 3] + 4 * dp[i - 4] + 4) % M);

    int t;
    cin >> t;
    for (int T = 1; T <= t; T++)
    {
        solve(T);
        cout << "\n";
    }
}