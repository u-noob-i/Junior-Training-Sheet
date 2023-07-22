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

using namespace std;

int n, m, i, j, k;
string s, p;
long long M = 1000000007;

void solve(int T)
{
    cin >> n >> m;
    vector<pair<int, int>> a(m);
    for (i = 0; i < m; i++)
        cin >> a[i].second >> a[i].first;
    sort(a.begin(), a.end());
    vector<long long> dp(m, 0);
    set<pair<long long, int>> x;
    for (i = m - 1; i >= 0; i--)
    {
        if (a[i].first == n)
            dp[i] = 1;
        else
            for (auto itr = x.begin(); itr != x.end() && itr->first <= a[i].first; itr++)
                if (a[itr->second].first > a[i].first)
                    dp[i] = (dp[i] + dp[itr->second]) % M;
        x.insert({a[i].second, i});
    }
    long long ans = 0;
    for (i = 0; i < m; i++)
        if (a[i].second == 0)
            ans = (ans + dp[i]) % M;
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