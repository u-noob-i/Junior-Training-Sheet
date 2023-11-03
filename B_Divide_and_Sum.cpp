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

ll factorialNumInverse[300001];
ll naturalNumInverse[300001];
ll fact[300001];

void InverseofNumber()
{
    naturalNumInverse[0] = naturalNumInverse[1] = 1;
    for (int i = 2; i <= 300000; i++)
        naturalNumInverse[i] = naturalNumInverse[M % i] * (M - M / i) % M;
}

void InverseofFactorial()
{
    factorialNumInverse[0] = factorialNumInverse[1] = 1;
    for (int i = 2; i <= 300000; i++)
        factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % M;
}

void factorial()
{
    fact[0] = 1;
    for (int i = 1; i <= 300000; i++)
        fact[i] = (fact[i - 1] * i) % M;
}

ll Binomial(ll N, ll R)
{
    ll ans = ((fact[N] * factorialNumInverse[R]) % M * factorialNumInverse[N - R]) % M;
    return ans;
}

void solve(int T)
{
    int n;
    cin >> n;
    vector<ll> a(2 * n);
    rep(i, 0, 2 * n) cin >> a[i];
    sort(a.begin(), a.end());
    ll ans = 0;
    rep(i, n, 2 * n) ans += a[i] - a[i - n];
    ans %= M;
    cout << (ans * Binomial(2 * n, n)) % M;
}

int main()
{
    cin.sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    InverseofNumber();
    InverseofFactorial();
    factorial();

    int t;
    t = 1;
    for (int T = 1; T <= t; T++)
    {
        solve(T);
        cout << "\n";
    }
}