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

void build(vector<int> &segtree, vector<int> &euler, vector<int> &height, int node, int l, int r)
{
    if(l > r)
        return;
    if(l == r)
    {
        segtree[node] = euler[l];
        return;
    }
    int mid = (l + r) / 2;
    build(segtree, euler, height, node * 2, l, mid);
    build(segtree, euler, height, node * 2 + 1, mid + 1, r);
    int a = segtree[node * 2], b = segtree[node * 2 + 1];
    if(height[a]<height[b])
        segtree[node] = a;
    else
        segtree[node] = b;
}

int query(vector<int> &segtree, vector<int> &height, int node, int tl, int tr, int l, int r)
{
    if(tl>r||tr<l)
        return -1;
    if(tl>=l&&tr<=r)
        return segtree[node];
    int mid = (tl + tr) / 2;
    int left = query(segtree, height, node * 2, tl, mid, l, r);
    int right = query(segtree, height, node * 2 + 1, mid + 1, tr, l, r);
    if(left==-1)
        return right;
    if(right==-1)
        return left;
    if(height[left]<height[right])
        return left;
    return right;
}

void dfs(vector<vector<vector<int>>> &adjlist,int u,int p,vector<int> &euler, vector<int> &first,vector<int> &height)
{
    euler.push_back(u);
    if(p!=-1)
        height[u] = height[p] + 1;
    first[u] = euler.size() - 1;
    for (int i = 0; i < adjlist[u].size(); i++)
    {
        int v = adjlist[u][i][0];
        if (v != p)
        {
            dfs(adjlist, v, u, euler, first, height);
            euler.push_back(u);
        }
    }
    return;
}

//0->1, 1->3, 1->4

int update(vector<vector<vector<int>>> &adjlist,vector<int> &count, vector<int> &ans, int u, int p)
{
    int ret = count[u];
    for (int i = 0; i < adjlist[u].size(); i++)
    {
        int v = adjlist[u][i][0], ind = adjlist[u][i][1];
        if(v == p)
            continue;
        int x = update(adjlist, count, ans, v, u);
        ans[ind] = x;
        ret += x;
    }
    return ret;
}

void solve(int T)
{
    int n, m, i, j, u, v;
    cin >> n;
    vector<vector<vector<int>>> adjlist(n);
    vector<int> ans(n - 1, 0), count(n, 0);
    rep(i, 0, n - 1)
    {
        cin >> u >> v;
        u--;
        v--;
        adjlist[u].push_back({v, i});
        adjlist[v].push_back({u, i});
    }
    vector<int> euler, first(n, -1), height(n, 0);
    dfs(adjlist, 0, -1, euler, first, height);
    m = euler.size();
    vector<int> segtree(4 * m + 1, -1);
    build(segtree, euler, height, 1, 0, m - 1);
    cin >> m;
    rep(i, 0, m)
    {
        cin >> u >> v;
        u--;
        v--;
        int left = first[u], right = first[v];
        if(left>right)
            swap(left, right);
        int lca = query(segtree, height, 1, 0, euler.size() - 1, left, right);
        count[u]++;
        count[v]++;
        count[lca] -= 2;
    }
    update(adjlist, count, ans, 0, -1);
    rep(i, 0, n - 1) cout << ans[i] << " ";
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