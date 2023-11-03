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

ll M = 1000000000000000003;

ll gcd(ll a, ll b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
}

void solve(int T)
{
    ll a, b;
    cin >> a >> b;
    if (b > a)
        swap(a, b);
    ll x = a - b;
    ll mval = lcm(a, b), ans = 0;
    rep(i, 1, sqrt(x) + 1)
    {
        if (x % i)
            continue;
        if (b % i)
        {
            ll temp = i - b % i;
            if (lcm(a + temp, b + temp) < mval)
            {
                mval = lcm(a + temp, b + temp);
                ans = temp;
            }
        }
        ll j = x / i;
        if (b % j)
        {
            ll temp = j - b % j;
            if (lcm(a + temp, b + temp) < mval)
            {
                mval = lcm(a + temp, b + temp);
                ans = temp;
            }
        }
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
    for (int T = 1; T <= t; T++)
    {
        solve(T);
        cout << "\n";
    }
}