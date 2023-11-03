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
const int N = 200001;

ll factorialNumInverse[N + 1];
ll naturalNumInverse[N + 1];
ll fact[N + 1];

void InverseofNumber(ll p)
{
    naturalNumInverse[0] = naturalNumInverse[1] = 1;
    for (int i = 2; i <= N; i++)
        naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p;
}

void InverseofFactorial(ll p)
{
    factorialNumInverse[0] = factorialNumInverse[1] = 1;
    for (int i = 2; i <= N; i++)
        factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p;
}

void factorial(ll p)
{
    fact[0] = 1;
    for (int i = 1; i <= N; i++)
        fact[i] = (fact[i - 1] * i) % p;
}

ll Binomial(ll N, ll R, ll p)
{
    ll ans = ((fact[N] * factorialNumInverse[R]) % p * factorialNumInverse[N - R]) % p;
    return ans;
}

void solve(int T)
{
    factorial(M);
    InverseofNumber(M);
    InverseofFactorial(M);

    ll h, w;
    int n;
    cin >> h >> w >> n;
    vector<pair<int, int>> a(n);
    rep(i, 0, n) cin >> a[i].first >> a[i].second;
    a.push_back({h, w});
    n++;
    sort(a.begin(), a.end());
    vector<ll> dp(n + 1, 0);
    dp[0] = 0;
    rep(i, 1, n + 1)
    {
        dp[i] = Binomial(a[i - 1].first + a[i - 1].second - 2, a[i - 1].first - 1, M);
        rep(j, 1, i)
        {
            if (a[j - 1].first <= a[i - 1].first && a[j - 1].second <= a[i - 1].second)
            {
                ll x = (dp[j] * Binomial(a[i - 1].first + a[i - 1].second - a[j - 1].first - a[j - 1].second, a[i - 1].first - a[j - 1].first, M)) % M;
                dp[i] = ((dp[i] - x) % M + M) % M;
            }
        }
        // cout << dp[i] << " ";
    }
    cout << dp[n];
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