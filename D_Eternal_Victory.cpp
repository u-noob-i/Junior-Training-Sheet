#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <numeric>
#include <queue>
#include <climits>
#include <cfloat>
#include <sstream>

using namespace std;

int n, m, i, j, k;
string s, p;
long long M = 1000000007;

void shortestPath(vector<vector<pair<int, long long>>> &adjlist)
{
    long long ans = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    vector<long long> dist(n + 1, 4ll * INT_MAX);
    vector<long long> last(n + 1, 0);
    pq.push(make_pair(0, 1));
    dist[1] = 0;
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        for (i = 0; i < adjlist[u].size(); i++)
        {
            pair<int, int> x = adjlist[u][i];
            int v = x.first;
            long long weight = x.second;
            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                ans -= 2ll * last[v];
                last[v] = weight;
                ans += 2ll * last[v];
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    int ind = 1;
    for (i = 2; i <= n; i++)
        if (dist[ind] < dist[i])
            ind = i;
    cout << ans - dist[ind];
}

void solve(int T)
{
    cin >> n;
    vector<vector<pair<int, long long>>> adjlist(n + 1);
    for (i = 0; i < n - 1; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        adjlist[x].push_back({y, z});
        adjlist[y].push_back({x, z});
    }
    shortestPath(adjlist);
    return;
}

int main()
{
    cin.sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    t = 1;
    for (int i = 1; i <= t; i++)
    {
        solve(t);
        cout << "\n";
    }
}