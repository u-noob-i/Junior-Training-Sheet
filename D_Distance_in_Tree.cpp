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

int n, m, i, j, k, l;
string s, p;
long long M = 1000000007, ans = 0;

void dfs(vector<vector<int>> &adjlist, vector<vector<int>> &ct, vector<bool> &visited, int cur)
{
    visited[cur] = 1;
    ct[cur][0] = 1;
    vector<int> a;
    for (int ind = 0; ind < adjlist[cur].size(); ind++)
        if (!visited[adjlist[cur][ind]])
        {
            a.push_back(adjlist[cur][ind]);
            dfs(adjlist, ct, visited, adjlist[cur][ind]);
            for (int x = 1; x <= k; x++)
                ct[cur][x] += ct[adjlist[cur][ind]][x - 1];
        }
    // cout << cur + 1 << "\n";
    // for (int x = 0; x <= k; x++)
    //     cout << ct[cur][x] << " ";
    // cout << "\n";
    long long temp = 0;
    for (int ind = 0; ind < a.size(); ind++)
        for (int x = 1; x < k; x++)
            temp += ct[a[ind]][x - 1] * (ct[cur][k - x] - ct[a[ind]][k - x - 1]);
    temp /= 2;
    ans += temp + ct[cur][k];
    return;
}

void solve(int T)
{
    cin >> n >> k;
    vector<vector<int>> adjlist(n), ct(n, vector<int>(k + 1, 0));
    for (i = 0; i < n - 1; i++)
    {
        cin >> j >> l;
        adjlist[j - 1].push_back(l - 1);
        adjlist[l - 1].push_back(j - 1);
    }
    vector<bool> visited(n, 0);
    dfs(adjlist, ct, visited, 0);
    cout << ans;
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