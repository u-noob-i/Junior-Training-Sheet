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

vector<vpi> adjlist;
map<int, vi> lvl;
vi e, d;
vector<string> ans;
int n, m, k;
string s;

void solve()
{
    cin >> n >> m >> k;
    adjlist.resize(n);
    e.resize(n);
    d.resize(n, INF);
    rep(i, 0, m - 1)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adjlist[u].push_back({v, i});
        adjlist[v].push_back({u, i});
    }
    s = string(m, '0');
    queue<int> q;
    d[0] = 0;
    q.push(0);
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (auto v : adjlist[u])
            if (d[v.first] > d[u] + 1)
            {
                d[v.first] = d[u] + 1;
                lvl[d[v.first]].push_back(v.first);
                q.push(v.first);
                s[v.second] = '1';
                e[v.first] = v.second;
            }
    }
    ans.push_back(s);
    int l = 2;
    while (lvl[l].size())
    {
        if (ans.size() == k)
            break;
        for (auto v : lvl[l])
        {
            int x = ans.size();
            for (auto u : adjlist[v])
                if (d[u.first] == l - 1 && e[v] != u.second)
                {
                    int i = 0;
                    while (i < x && ans.size() < k)
                    {
                        s = ans[i];
                        s[e[v]] = '0';
                        s[u.second] = '1';
                        ans.push_back(s);
                        i++;
                    }
                    if (ans.size() == k)
                        break;
                }
            if (ans.size() == k)
                break;
        }
        l++;
    }
    cout << ans.size();
    rep(i, 0, ans.size() - 1) cout << "\n"
                                   << ans[i];
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