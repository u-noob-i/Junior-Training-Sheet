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

using namespace std;

int n, m, i, j;

double dfs(vector<vector<int>> &adjlist, vector<bool> &visited, int ind)
{
    visited[ind] = 1;
    double dun = 0;
    double x = 0;
    for (int k = 0; k < adjlist[ind].size(); k++)
    {
        if (!visited[adjlist[ind][k]])
        {
            dun++;
            x += dfs(adjlist, visited, adjlist[ind][k]);
        }
    }
    if (!dun)
        return 0;
    return (x / dun) + 1.0;
}

void solve(int T)
{
    int x, y;
    cin >> n;
    vector<vector<int>> adjlist(n + 1);
    vector<bool> visited(n + 1, 0);
    for (i = 0; i < n - 1; i++)
    {
        cin >> x >> y;
        adjlist[x].push_back(y);
        adjlist[y].push_back(x);
    }
    if (n == 1 || n == 2)
    {
        cout << fixed << setprecision(6) << (double)(n - 1);
        return;
    }
    double ans = dfs(adjlist, visited, 1);
    cout << fixed << setprecision(6) << ans;
}

int main()
{
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