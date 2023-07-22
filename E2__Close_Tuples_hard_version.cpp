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
#define ll long long
const int N = 1000001;

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
    cin >> n >> m >> k;
    vector<int> a(n);
    for (i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    long long ans = 0;
    for (i = 0; i + m - 1 < n; i++)
    {
        if (m == 1)
        {
            ans++;
            continue;
        }
        long long l = i + 1, r = n - 1, mid, ind = -1;
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (a[mid] - a[i] > k)
                r = mid - 1;
            else
            {
                ind = mid;
                l = mid + 1;
            }
        }
        // cout << i << " " << ind << "\n";
        if (ind == -1 || ind - i < m - 1)
            continue;
        ind -= i;
        ans += Binomial(ind, m - 1, M);
        ans %= M;
    }
    cout << ans;
}

int main()
{
    cin.sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll p = 1000000007;
    InverseofNumber(p);
    InverseofFactorial(p);
    factorial(p);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve(t);
        cout << "\n";
    }
}