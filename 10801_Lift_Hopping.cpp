#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <queue>
#include <climits>
#include <sstream>

using namespace std;

int n, m, i, j, k;
char c;
string s;

long long modu = 1000000007;

void solve(int T)
{
    while (cin >> n >> k)
    {
        vector<long long> a(n);
        for (i = 0; i < n; i++)
            cin >> a[i];
        vector<vector<int>> floors(n);
        for (i = 0; i < n; i++)
        {
            string line;
            getline(cin, line);
            istringstream iss(line);
            while (iss >> c)
            {
                floors[i].push_back(c);
            }
        }
        vector<vector<pair<long long, int>>> adjlist(100);
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < floors[i].size(); j++)
            {
                int x, y;
                x = floors[i][j];
                for (int p = 0; p < floors[i].size(); p++)
                {
                    if (p == j)
                        continue;
                    y = floors[i][p];
                    adjlist[x].push_back({abs(x - y) * a[i], y});
                    adjlist[y].push_back({abs(x - y) * a[i], x});
                }
            }
        }
        vector<long long> cost(100, LLONG_MAX);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        cost[0] = 0;
        pq.push({0, 0});
        while (!pq.empty())
        {
            pair<long long, int> p = pq.top();
            pq.pop();
            for (i = 0; i < adjlist[p.second].size(); i++)
            {
                if (cost[adjlist[p.second][i].second] > cost[p.second] + adjlist[p.second][i].first)
                {
                    cost[adjlist[p.second][i].second] = cost[p.second] + adjlist[p.second][i].first;
                    pq.push({cost[adjlist[p.second][i].second], adjlist[p.second][i].second});
                }
            }
        }
        if (cost[k] == LLONG_MAX)
            cout << "IMPOSSIBLE\n";
        else
            cout << cost[k] << "\n";
    }
}

int main()
{

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

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