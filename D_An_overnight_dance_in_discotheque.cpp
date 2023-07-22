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

int n, m, i, j, k, q;
string s, p;
long long M = 1000000007;

void dfs(vector<vector<int>> &adjlist, map<int, vector<long long>> &a, vector<vector<vector<long long>>> &dp,
         vector<bool> &visited, int cur)
{
    visited[cur] = 1;
    long long arr[2][2];
    arr[0][0] = arr[0][1] = arr[1][0] = arr[1][1] = 0;
    for (int ind = 0; ind < adjlist[cur].size(); ind++)
    {
        if (visited[adjlist[cur][ind]])
            continue;
        dfs(adjlist, a, dp, visited, adjlist[cur][ind]);
        for (int x = 0; x < 2; x++)
            for (int y = 0; y < 2; y++)
                arr[x][y] += dp[adjlist[cur][ind]][x][y];
    }
    for (int x = 0; x < 2; x++)
        for (int y = 0; y < 2; y++)
            dp[cur][x][y] = max(arr[x][y ^ 1] + a[cur][2] * a[cur][2] * (y == 0 ? 1 : -1),
                                arr[x ^ 1][y] + a[cur][2] * a[cur][2] * (x == 0 ? 1 : -1));
    return;
}

void solve(int T)
{
    cin >> n;
    map<int, vector<long long>> a;
    for (i = 0; i < n; i++)
    {
        long long x, y, z;
        cin >> x >> y >> z;
        a[i] = {x, y, z};
    }
    vector<vector<int>> adjlist(n);
    set<int> roots;
    for (i = 0; i < n; i++)
        roots.insert(i);
    for (auto itr = a.begin(); itr != a.end(); itr++)
    {
        int par = -1;
        for (auto jtr = a.begin(); jtr != a.end(); jtr++)
        {
            if (itr == jtr)
                continue;
            long long x = itr->second[0] - jtr->second[0];
            long long y = itr->second[1] - jtr->second[1];
            if (jtr->second[2] > itr->second[2] &&
                x * x + y * y <= (jtr->second[2] - itr->second[2]) * (jtr->second[2] - itr->second[2]) &&
                (par == -1 || a[par][2] > jtr->second[2]))
                par = jtr->first;
        }
        if (par == -1)
            continue;
        adjlist[par].push_back(itr->first);
        if (roots.find(itr->first) != roots.end())
            roots.erase(itr->first);
    }
    double ans = 0;
    vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(2, vector<long long>(2)));
    vector<bool> visited(n, 0);
    for (auto itr = roots.begin(); itr != roots.end(); itr++)
    {
        dfs(adjlist, a, dp, visited, *itr);
        ans += dp[*itr][0][0];
    }
    double pi = acos(-1.0);
    cout << setprecision(18) << pi * ans;
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