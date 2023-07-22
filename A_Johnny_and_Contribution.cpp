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

void solve(int T)
{
    cin >> n >> m;
    vector<int> a(n);
    vector<vector<int>> adjlist(n);
    int u, v;
    for (i = 0; i < m; i++)
    {
        cin >> u >> v;
        u--;
        v--;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    map<int, vector<int>> arr;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        arr[a[i]].push_back(i);
    }
    int cur = 1;
    vector<int> ans;
    for (auto itr = arr.begin(); itr != arr.end(); itr++, cur++)
    {
        if (itr->first != cur)
        {
            cout << -1;
            return;
        }
        vector<int> temp = itr->second;
        for (i = 0; i < temp.size(); i++)
        {
            int u = temp[i];
            ans.push_back(u + 1);
            vector<bool> x(cur, 0);
            int count = 0;
            for (j = 0; j < adjlist[u].size(); j++)
            {
                int v = adjlist[u][j];
                if (a[v] == cur)
                {
                    cout << -1;
                    return;
                }
                if (cur != 1 && a[v] < cur && !x[a[v]])
                {
                    x[a[v]] = 1;
                    count++;
                }
            }
            if (cur != 1 && count != cur - 1)
            {
                cout << -1;
                return;
            }
        }
    }
    for (i = 0; i < n; i++)
        cout << ans[i] << " ";
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
    }
}