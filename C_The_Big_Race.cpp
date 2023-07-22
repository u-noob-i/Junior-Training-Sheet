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

int n, m, i, j;
// string s;
long long modu = 1000000007;

long long gcd(long long a, long long b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void solve(int T)
{
    long long d, a, b;
    cin >> d >> a >> b;
    long long x = gcd(a, b), y;
    double temp = (double)a * b;
    x = (long long)(temp / x);
    y = d / x;
    long long ans = y * min(a, b);
    ans += min((d % x) + 1, min(a, b)) - 1;
    x = gcd(ans, d);
    cout << ans / x << "/" << d / x;
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