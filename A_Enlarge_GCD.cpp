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

vector<int> spf(20000001);

void sieve()
{
    spf[1] = 1;
    for (i = 2; i < spf.size(); i++)
        spf[i] = i;
    for (i = 4; i < spf.size(); i += 2)
        spf[i] = 2;
    for (int i = 3; i * i < spf.size(); i++)
        if (spf[i] == i)
            for (int j = i * i; j < spf.size(); j += i)
                if (spf[j] == j)
                    spf[j] = i;
}

vector<int> factorize(int x)
{
    vector<int> ans;
    while (x > 1)
    {
        ans.push_back(spf[x]);
        int y = spf[x];
        while (x % y == 0)
            x /= y;
    }
    return ans;
}

void solve(int T)
{
    cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    int g = a[0];
    rep(i, 1, n) g = gcd(g, a[i]);
    rep(i, 0, n) a[i] /= g;
    map<int, int> pc;
    int ans = n;
    rep(i, 0, n)
    {
        vector<int> temp = factorize(a[i]);
        rep(j, 0, temp.size()) ans = min(ans, n - ++pc[temp[j]]);
    }
    if (ans == n)
        ans = -1;
    cout << ans;
}

int main()
{
    cin.sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    int t;
    t = 1;
    for (int T = 1; T <= t; T++)
    {
        solve(T);
        cout << "\n";
    }
}