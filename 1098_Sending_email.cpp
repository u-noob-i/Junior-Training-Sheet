#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <climits>
#include <set>
#include <queue>
using namespace std;

int n, m, i, j;
string s;

void solve(int T)
{
    int a, b, x, y;
    long long cost = 0;
    cin >> n >> m >> a >> b;
    vector<vector<pair<int, long long>>> adjlist(n);
    for (i = 0; i < m; i++)
    {
        cin >> x >> y >> cost;
        adjlist[x].push_back({y, cost});
        adjlist[y].push_back({x, cost});
    }
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    vector<long long> c(n, LLONG_MAX);
    c[a] = 0;
    pq.push({0, a});
    while (!pq.empty())
    {
        pair<long long, int> f = pq.top();
        pq.pop();
        for (i = 0; i < adjlist[f.second].size(); i++)
        {
            if (f.first + adjlist[f.second][i].second < c[adjlist[f.second][i].first])
            {
                c[adjlist[f.second][i].first] = f.first + adjlist[f.second][i].second;
                pq.push({c[adjlist[f.second][i].first], adjlist[f.second][i].first});
            }
        }
    }
    cout << "Case #" << T << ": ";
    if (c[b] == LLONG_MAX)
        cout << "unreachable";
    else
        cout << c[b];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int p = 1; p <= t; p++)
    {
        solve(p);
        cout << "\n";
    }
}