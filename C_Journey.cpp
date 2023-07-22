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
#include <tuple>

using namespace std;

int n, m, i, j;
string s;
long long modu = 1000000007;

void dfs(vector<vector<pair<int, int>>> &adjlist, int cur, vector<int> d, vector<int> &md, int time, int curt)
{
    if (cur == n)
    {
        if (d.size() > md.size())
            md = d;
        return;
    }
    for (int ind = 0; ind < adjlist[cur].size(); ind++)
        if (adjlist[cur][ind].second + curt <= time)
        {
            d.push_back(adjlist[cur][ind].first);
            dfs(adjlist, adjlist[cur][ind].first, d, md, time, curt + adjlist[cur][ind].second);
            d.pop_back();
        }
    return;
}

void solve(int T)
{
    int time;
    cin >> n >> m >> time;
    vector<vector<pair<int, int>>> adjlist(n + 1);
    for (i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        adjlist[x].push_back({y, z});
    }
    vector<int> ans;
    dfs(adjlist, 1, {1}, ans, time, 0);
    cout << ans.size() << "\n";
    for (i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
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