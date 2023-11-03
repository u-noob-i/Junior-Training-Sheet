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

int a[200001];
vi adjlist[100001];
vi v;
unordered_set<int> kp, p;
int n, m, k;

int l, r;

int dfs(int u)
{
    p.insert(u);
    a[r] = u;
    r++;
    if (r - l == k + 1)
    {
        kp.insert(a[l]);
        l++;
    }
    for (auto v : adjlist[u])
    {
        if (kp.size() && kp.find(v) != kp.end())
            return v;
        if (p.find(v) == p.end())
        {
            int x = dfs(v);
            if (x != -1)
                return x;
        }
    }
    return -1;
}

void solve()
{
    cin >> n >> m >> k;
    rep(i, 1, m)
    {
        int u, v;
        cin >> u >> v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    l = 0, r = 0;
    l = dfs(1);
    int i = 0;
    while (a[i] != l)
        i++;
    cout << r - i << "\n";
    while (i < r)
    {
        cout << a[i] << " ";
        i++;
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