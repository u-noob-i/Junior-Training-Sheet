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

using namespace std;

#define ll long long
#define rep(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define irep(a, b, c) for (int(a) = (b); (a) >= (c); --(a))

ll M = 1000000007;

vector<int> p, vis, cycles;
ll pows[200001];

int dfs2(int u)
{
    vis[u] = 3;
    int ret = 1;
    if (vis[p[u]] == 2)
        ret += dfs2(p[u]);
    return ret;
}

void dfs(int u)
{
    vis[u] = 2;
    if (!vis[p[u]])
        dfs(p[u]);
    else if (vis[p[u]] == 2)
        cycles.push_back(dfs2(u));
    vis[u] = 1;
    return;
}

void solve(int T)
{
    pows[0] = 1;
    rep(i, 1, 200001) pows[i] = (pows[i - 1] * 2ll) % M;

    int n;
    cin >> n;
    p.resize(n);
    vis.resize(n, 0);
    rep(i, 0, n)
    {
        cin >> p[i];
        p[i]--;
    }
    rep(i, 0, n) if (!vis[i]) dfs(i);

    ll ans = 1, ct = n;
    rep(i, 0, cycles.size())
    {
        ans = (ans * (pows[cycles[i]] - 2ll)) % M;
        ct -= cycles[i];
    }
    ans = (ans * pows[ct]) % M;

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