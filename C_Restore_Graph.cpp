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
long long M = 998244353;

void solve(int T)
{
    cin >> n >> k;
    vector<pair<int, int>> a(n);
    for (i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    if (a[0].first)
    {
        cout << -1;
        return;
    }
    vector<pair<int, int>> ans;
    queue<int> q;
    q.push(0);
    int d = 1;
    i = 1;
    while (i < n && q.size())
    {
        queue<int> q1;
        while (i < n && q.size())
        {
            int x = q.front(), temp = k;
            if (x)
                temp--;
            q.pop();
            while (i < n && a[i].first == d && temp)
            {
                q1.push(i);
                ans.push_back({a[x].second, a[i].second});
                temp--;
                i++;
            }
        }
        q = q1;
        d++;
    }
    if (i < n)
    {
        cout << -1;
        return;
    }
    cout << ans.size();
    for (i = 0; i < ans.size(); i++)
        cout << "\n"
             << ans[i].first + 1 << " " << ans[i].second + 1;
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