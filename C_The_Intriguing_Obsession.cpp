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

int m, j;
string s;
long long M = 998244353;
long long fact[5001];

long long power(long long x, long long y, long long p)
{
    long long res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

long long modInverse(long long n, long long p)
{
    return power(n, p - 2, p);
}

long long nCrModPFermat(long long n, long long r, long long p)
{
    if (n < r)
        return 0;
    if (r == 0)
        return 1;
    return (fact[n] * modInverse(fact[r], p) % p * modInverse(fact[n - r], p) % p) % p;
}

long long ad(long long x, long long y)
{
    long long ans = 0;
    for (long long temp = 0; temp <= x; temp++)
    {
        long long l = nCrModPFermat(x, temp, M);
        long long r = nCrModPFermat(y, temp, M);
        l *= r;
        l %= M;
        l *= fact[temp];
        l %= M;
        ans += l;
        ans %= M;
    }
    return ans;
}

void solve(int T)
{
    long long a, b, c, ans = 0;
    cin >> a >> b >> c;
    fact[0] = 1;
    for (long long temp = 1; temp <= 5000; temp++)
        fact[temp] = (fact[temp - 1] * temp) % M;
    long long x = ad(min(a, b), max(a, b)), y = ad(min(a, c), max(a, c)), z = ad(min(b, c), max(b, c));
    ans = (x * y) % M;
    ans = (ans * z) % M;
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
        cout << "\n";
    }
}