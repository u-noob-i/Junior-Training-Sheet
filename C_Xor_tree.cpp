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

int n, m, i, j;
string s;

int ans = 0;

void dfs(vector<vector<int>> &adjlist, vector<int> &ini, vector<int> &tar, vector<bool> &visited, vector<int> &pt,
         int cur, int pare, int paro, int turn)
{
    visited[cur] = 1;
    for (int ind = 0; ind < adjlist[cur].size(); ind++)
    {
        int x = adjlist[cur][ind];
        if (visited[x])
            continue;
        if (turn % 2)
            ini[x] += paro;
        else
            ini[x] += pare;
        ini[x] %= 2;
        if (ini[x] == tar[x])
            dfs(adjlist, ini, tar, visited, pt, x, pare, paro, turn + 1);
        else
        {
            ans++;
            pt.push_back(x + 1);
            if (turn % 2)
                dfs(adjlist, ini, tar, visited, pt, x, pare, paro + 1, turn + 1);
            else
                dfs(adjlist, ini, tar, visited, pt, x, pare + 1, paro, turn + 1);
        }
    }
}

void solve(int T)
{
    cin >> n;
    vector<vector<int>> adjlist(n);
    vector<int> ini(n), fin(n);
    for (i = 0; i < n - 1; i++)
    {
        cin >> m >> j;
        adjlist[m - 1].push_back(j - 1);
        adjlist[j - 1].push_back(m - 1);
    }
    for (i = 0; i < n; i++)
        cin >> ini[i];
    for (i = 0; i < n; i++)
        cin >> fin[i];
    vector<bool> visited(n, 0);
    vector<int> pt;
    if (ini[0] == fin[0])
        dfs(adjlist, ini, fin, visited, pt, 0, 0, 0, 1);
    else
    {
        ans++;
        pt.push_back(1);
        dfs(adjlist, ini, fin, visited, pt, 0, 1, 0, 1);
    }
    cout << ans << "\n";
    for (i = 0; i < pt.size(); i++)
        cout << pt[i] << "\n";
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
    for (int q = 1; q <= t; q++)
    {
        solve(t);
    }
}