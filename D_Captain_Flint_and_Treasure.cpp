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

void solve(int T)
{
    int n;
    cin >> n;
    vector<ll> a(n), b(n), indegree(n, 0);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];
    vector<vector<int>> adjlist(n);
    rep(i, 0, n)
    {
        if (b[i] == -1)
            continue;
        b[i]--;
        adjlist[i].push_back(b[i]);
        indegree[b[i]]++;
    }
    vector<int> ans, negs;
    queue<int> q;
    ll sum = 0;

    rep(i, 0, n) if (!indegree[i]) q.push(i);
    while(q.size())
    {
        int u = q.front();
        q.pop();
        if (a[u] > 0)
        {
            ans.push_back(u + 1);
            sum += a[u];
            if (b[u] != -1)
                a[b[u]] += a[u];
        }
        else
            negs.push_back(u);
        rep(i, 0, adjlist[u].size())
        {
            int v = adjlist[u][i];
            indegree[v]--;
            if(!indegree[v])
                q.push(v);
        }
    }
    irep(i, negs.size() - 1, 0)
    {
        ans.push_back(negs[i] + 1);
        sum += a[negs[i]];
        if (b[negs[i]] != -1)
            a[b[negs[i]]] += a[negs[i]];
    }

    cout << sum << "\n";
    rep(i, 0, n) cout << ans[i] << " ";
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