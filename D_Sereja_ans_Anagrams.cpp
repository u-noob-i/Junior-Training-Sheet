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
#include <bitset>
#include <random>
#include <chrono>

using namespace std;

#define rep(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define irep(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define vpl vector<pair<long long, long long>>
#define pl pair<long long, long long>
#define vl vector<long long>
#define vpi vector<pair<int, int>>
#define pi pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define ll long long
#define INF 1e9
ll M = 1e9 + 7;

void solve()
{
    ll n, m, p;
    cin >> n >> m >> p;
    vi a(n + 1), b(m + 1);
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, m) cin >> b[i];
    map<int, int> bc;
    rep(i, 1, m) bc[b[i]]++;
    int same, tot = bc.size();
    vi ans;
    for (ll i = 1; i <= min(n, p); i++)
    {
        map<int, int> ac;
        same = 0;
        for (ll j = i; j <= n; j += p)
        {
            ll k = j - m * p;
            if (k >= i)
            {
                if (ac[a[k]] == bc[a[k]] && bc[a[k]])
                    same--;
                else if (ac[a[k]] - 1 == bc[a[k]] && bc[a[k]])
                    same++;
                ac[a[k]]--;
            }
            if (ac[a[j]] == bc[a[j]] && bc[a[j]])
                same--;
            else if (ac[a[j]] + 1 == bc[a[j]] && bc[a[j]])
                same++;
            ac[a[j]]++;
            // cout << i << " " << j << " : " << same << "\n";
            if (same == tot)
                ans.push_back(max(i, k + p));
        }
    }
    cout << ans.size() << "\n";
    if (ans.size())
    {
        sort(ans.begin(), ans.end());
        rep(i, 0, ans.size() - 1) cout << ans[i] << " ";
    }
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
        solve();
        cout << "\n";
    }
}