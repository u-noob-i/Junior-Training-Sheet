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

using namespace std;

long long modu = 1000000007;

long long moduloMultiplication(long long a, long long b, long long mod)
{
    long long res = 0;
    a %= mod;
    while (b)
    {
        if (b & 1)
            res = (res + a) % mod;
        a = (2 * a) % mod;
        b >>= 1;
    }
    return res;
}

long long int gcdExtended(long long int a, long long int b, long long int *x, long long int *y);

long long int modInverse(long long int b, long long int m)
{
    long long int x, y;
    long long int g = gcdExtended(b, m, &x, &y);
    if (g != 1)
        return -1;
    return (x % m + m) % m;
}

long long int gcdExtended(long long int a, long long int b, long long int *x, long long int *y)
{
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
    long long int x1, y1;
    long long int gcd = gcdExtended(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}

long long int modDivide(long long int a, long long int b, long long int m)
{
    a = a % m;
    long long int inv = modInverse(b, m);
    if (inv == -1)
        return 0;
    else
        return (inv * a) % m;
}

long long nCr(long long n, long long r, long long p)
{
    if (r > n)
        return 0;
    if (r > n - r)
        r = n - r;
    long long int x = 1;
    for (int i = 1; i <= r; i++)
    {
        x = moduloMultiplication(x, (n + 1 - i), p);
        x = modDivide(x, i, p);
    }
    return x;
}

void solve(int T)
{
    long long int a, b;
    cin >> a >> b;
    for (int i = 0; i < a - 1; i++)
    {
        int x;
        cin >> x;
    }
    long long int ans = b;
    for (long long int i = 0; i < a - 1; i++)
        ans = (ans * (b - 1)) % modu;
    for (long long int x = 2; x < b; x++)
    {
        long long temp = x;
        for (int i = 0; i < a - 1; i++)
            temp = (temp * (x - 1)) % modu;
        temp = (temp * nCr(b, x, modu)) % modu;
        ans -= temp;
        ans %= modu;
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