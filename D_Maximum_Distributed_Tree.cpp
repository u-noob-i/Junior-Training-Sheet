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

using namespace std;

int n, m, i, j, k;
string s;
long long M = 1000000007;

int dfs(vector<vector<int>> &adjlist, vector<bool> &visited, vector<long long> &count, int cur)
{
    visited[cur] = 1;
    long long child = 1;
    for (int ind = 0; ind < adjlist[cur].size(); ind++)
    {
        if (!visited[adjlist[cur][ind]])
        {
            long long x = dfs(adjlist, visited, count, adjlist[cur][ind]);
            child += x;
            count.push_back(x * (n - x));
        }
    }
    return child;
}

void solve(int T)
{
    cin >> n;
    vector<vector<int>> adjlist(n);
    for (i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    cin >> m;
    vector<long long> div(m);
    for (i = 0; i < m; i++)
        cin >> div[i];
    while (div.size() < n - 1)
        div.push_back(1);
    vector<bool> visited(n, 0);
    vector<long long> count;
    dfs(adjlist, visited, count, 0);
    sort(count.begin(), count.end());
    sort(div.begin(), div.end());
    for (i = div.size() - 1; i > n - 2; i--)
        div[i - 1] = (div[i] * div[i - 1]) % M;
    long long ans = 0;
    for (i = 0; i < n - 1; i++)
        ans = (ans + ((count[i] * div[i]) % M)) % M;
    cout << ans;
}

int main()
{
    cin.sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve(t);
        cout << "\n";
    }
}