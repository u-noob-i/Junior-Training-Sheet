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

bool ispos(vector<vector<int>> &edges, int n, int m)
{
    vector<vector<int>> adjlist(n);
    vector<int> degree(n, 0);
    rep(i, 0, m)
    {
        adjlist[edges[i][0] - 1].push_back(edges[i][1] - 1);
        degree[edges[i][1] - 1]++;
    }
    queue<int> q;
    rep(i, 0, n) if (!degree[i]) q.push(i);
    while (q.size())
    {
        if (q.size() > 1)
            return 0;
        int u = q.front();
        q.pop();
        for (auto v : adjlist[u])
        {
            degree[v]--;
            if (!degree[v])
                q.push(v);
        }
    }
    return 1;
}

void solve(int T)
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m, vector<int>(2));
    rep(i, 0, m) cin >> edges[i][0] >> edges[i][1];
    int l = 1, r = m, mid, ans = -1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (ispos(edges, n, mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
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