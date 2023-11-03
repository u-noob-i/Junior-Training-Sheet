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

int spf[1000001];

void sieve()
{
    spf[1] = 1;
    for (int i = 2; i < 1000001; i++)
        spf[i] = i;
    for (int i = 4; i < 1000001; i += 2)
        spf[i] = 2;
    for (int i = 3; i * i < 1000001; i++)
        if (spf[i] == i)
            for (int j = i * i; j < 1000001; j += i)
                if (spf[j] == j)
                    spf[j] = i;
}

void solve(int T)
{
    int n, m;
    cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    map<ll, vector<int>> arr;
    rep(i, 0, n)
    {
        ll x = 1, temp = a[i];
        while (temp > 1)
        {
            ll y = spf[temp], count = 0;
            while (temp % y == 0)
            {
                temp /= y;
                count++;
            }
            count %= 2;
            if (count)
                x *= y;
        }
        arr[x].push_back(a[i]);
    }
    vector<int> ans(2, -1);
    int ps = arr[1].size();
    for (auto itr = arr.begin(); itr != arr.end(); itr++)
    {
        int s = itr->second.size();
        ans[0] = max(ans[0], s);
        if (s % 2 == 0 && itr->first != 1)
            ps += s;
    }
    ans[1] = max(ps, ans[0]);
    cin >> m;
    while (m--)
    {
        ll x;
        cin >> x;
        x = min(1ll, x);
        cout << ans[x] << " ";
    }
}

int main()
{
    cin.sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    int t;
    cin >> t;
    for (int T = 1; T <= t; T++)
    {
        solve(T);
        cout << "\n";
    }
}