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
#include <iomanip>

using namespace std;

int n, m, i, j;
string s;
long long modu = 100000000;

void solve(int T)
{
    cin >> n;
    vector<pair<int, string>> a(n);
    for (i = 0; i < n; i++)
        cin >> a[i].second >> a[i].first;
    sort(a.begin(), a.end());
    if (a[0].first)
    {
        cout << -1;
        return;
    }
    vector<pair<string, int>> ans;
    ans.push_back({a[0].second, 1});
    vector<pair<int, string>> temp = {{1, a[0].second}};
    for (i = 1; i < n; i++)
    {
        s = a[i].second;
        m = a[i].first;
        if (m > temp.size())
        {
            cout << -1;
            return;
        }
        int x;
        if (m == temp.size())
            x = 1;
        else if (!m)
            x = temp[temp.size() - 1].first + 1;
        else
            x = temp[temp.size() - m].first;
        for (j = 0; j < temp.size(); j++)
            if (temp[j].first >= x)
                temp[j].first++;
        temp.push_back({x, s});
        ans.push_back({s, x});
        sort(temp.begin(), temp.end());
    }
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (temp[i].second == ans[j].first)
            {
                ans[j].second = temp[i].first;
                break;
            }
    // cout << "================\n";
    for (i = 0; i < n; i++)
        cout << ans[i].first << " " << ans[i].second << "\n";
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