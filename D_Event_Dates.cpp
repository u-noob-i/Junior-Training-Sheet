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

void solve(int T)
{
    cin >> n;
    vector<pair<pair<int, int>, int>> a(n);
    for (i = 0; i < n; i++)
    {
        cin >> a[i].first.second >> a[i].first.first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    vector<bool> vis(10000001, 0);
    vector<int> ans(n, -1);
    for (i = 0; i < n; i++)
    {
        while (vis[a[i].first.second])
            a[i].first.second++;
        ans[a[i].second] = a[i].first.second;
        vis[a[i].first.second] = 1;
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
        cout << "\n";
    }
}