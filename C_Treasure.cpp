#include <iostream>
#include <cstring>
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
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <random>
#include <chrono>

using namespace std;

#define rep(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define irep(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define vpl vector<pair<long long, long long>>
#define pl pair<long long, long long>
#define vl vector<long long>
#define vvl vector<vector<long long>>
#define vpi vector<pair<int, int>>
#define pi pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define ll long long
#define INF 1e18
ll M = 1e9 + 7;

void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    int x = 0, last = -1;
    vi ans;
    rep(i, 0, n - 1)
    {
        if (s[i] == '(')
            x++;
        else if (s[i] == ')')
        {
            if (!x)
            {
                cout << -1;
                return;
            }
            x--;
        }
        else
        {
            if (!x)
            {
                cout << -1;
                return;
            }
            ans.push_back(1);
            x--;
            last = i;
        }
    }
    if (ans.size())
        ans[ans.size() - 1] += x;
    if (x && last == -1)
    {
        cout << -1;
        return;
    }
    string t = "";
    rep(i, 0, n - 1)
    {
        if (s[i] == '(' || s[i] == ')')
            t += s[i];
        else if (i != last)
            t += ")";
        else
            t += string(x + 1, ')');
    }
    x = 0;
    rep(i, 0, t.length() - 1)
    {
        if (t[i] == '(')
            x++;
        else if (!x)
        {
            cout << -1;
            return;
        }
        else
            x--;
    }
    for (auto v : ans)
        cout << v << "\n";
}

int main()
{
    cin.sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    t = 1;
    for (int T = 1; T <= t; T++)
    {
        solve();
        cout << "\n";
    }
}
