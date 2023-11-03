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
#define INF 1e9
int M = 1e9 + 7;

void solve()
{
    int f, s, fs, sf;
    cin >> f >> s >> fs >> sf;
    string ans;
    if (abs(fs - sf) > 1)
    {
        cout << -1;
        return;
    }
    if (sf > fs)
    {
        ans = "7";
        s--;
        bool x = 1;
        while (sf || fs)
        {
            if (x)
            {
                ans += "4";
                sf--;
                f--;
            }
            else
            {
                ans += "7";
                fs--;
                s--;
            }
            x = !x;
        }
        if (f < 0 || s < 0)
        {
            cout << -1;
            return;
        }
        rep(i, 0, ans.length() - 1)
        {
            cout << ans[i];
            if (i == 1)
            {
                while (f)
                {
                    f--;
                    cout << "4";
                }
            }
            if (i == ans.length() - 2)
            {
                while (s)
                {
                    s--;
                    cout << "7";
                }
            }
        }
    }
    else if (fs > sf)
    {
        ans = "4";
        f--;
        bool x = 0;
        while (fs || sf)
        {
            if (x)
            {
                ans += "4";
                sf--;
                f--;
            }
            else
            {
                ans += "7";
                fs--;
                s--;
            }
            x = !x;
        }
        if (f < 0 || s < 0)
        {
            cout << -1;
            return;
        }
        while (f)
        {
            f--;
            cout << "4";
        }
        cout << ans;
        while (s)
        {
            s--;
            cout << "7";
        }
    }
    else if (f > fs)
    {
        ans = "4";
        f--;
        bool x = 0;
        while (sf || fs)
        {
            if (x)
            {
                ans += "4";
                sf--;
                f--;
            }
            else
            {
                ans += "7";
                fs--;
                s--;
            }
            x = !x;
        }
        if (f < 0 || s < 0)
        {
            cout << -1;
            return;
        }
        while (f)
        {
            f--;
            cout << "4";
        }
        rep(i, 0, ans.length() - 1)
        {
            cout << ans[i];
            if (i == ans.length() - 2)
            {
                while (s)
                {
                    s--;
                    cout << "7";
                }
            }
        }
    }
    else
    {
        ans = "7";
        s--;
        bool x = 1;
        while (sf || fs)
        {
            if (x)
            {
                ans += "4";
                sf--;
                f--;
            }
            else
            {
                ans += "7";
                fs--;
                s--;
            }
            x = !x;
        }
        if (f < 0 || s < 0)
        {
            cout << -1;
            return;
        }
        rep(i, 0, ans.length() - 1)
        {
            cout << ans[i];
            if (i == 1)
            {
                while (f)
                {
                    f--;
                    cout << "4";
                }
            }
        }
        while (s)
        {
            s--;
            cout << "7";
        }
    }
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
