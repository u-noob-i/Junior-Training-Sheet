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

int i, j;
string s;
long long modu = 1000000009;

long long binpow(long long a, long long b)
{
    a %= modu;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % modu;
        a = a * a % modu;
        b >>= 1;
    }
    return res;
}

void solve(int T)
{
    long long n, m, k, ans = 0, cur = 0;
    cin >> n >> m >> k;
    if ((n / k) + m <= n)
    {
        cout << m;
        return;
    }
    long long x = n - m, y = (k - 1) * x;
    x = m - y;
    long long z = x / k, w = x % k;
    ans = (2 * k * (binpow(2, z) - 1)) % modu;
    ans = (ans + w + y) % modu;
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