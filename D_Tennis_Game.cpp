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
    int n, last;
    cin >> n;
    vi b(n + 1);
    vvi a(2, vi(n + 1, 0));
    rep(i, 1, n)
    {
        cin >> b[i];
        a[0][i] = a[0][i - 1];
        a[1][i] = a[1][i - 1];
        if (b[i] == 1)
            a[0][i]++;
        else
            a[1][i]++;
    }
    if (b[n] == 2)
        swap(a[0], a[1]);
    int x = 0, y = 0;
    set<pi> ans;
    irep(i, n, 1)
    {
        if (b[i] == b[n])
            x++;
        else
            y++;
        if (x > y)
        {
            int sx = 0, sy = 0, t = x;
            int j = 1;
            while (j <= n)
            {
                int l = j, r = n, mid, vx = n + 1, vy = n + 2;
                while (l <= r)
                {
                    mid = (l + r) >> 1;
                    if (a[0][mid] - a[0][j - 1] >= t)
                    {
                        vx = mid;
                        r = mid - 1;
                    }
                    else
                        l = mid + 1;
                }
                l = j, r = n;
                while (l <= r)
                {
                    mid = (l + r) >> 1;
                    if (a[1][mid] - a[1][j - 1] >= t)
                    {
                        vy = mid;
                        r = mid - 1;
                    }
                    else
                        l = mid + 1;
                }
                if (vx == vy && vx == n + 2)
                    break;
                if (vx < vy)
                {
                    sx++;
                    j = vx + 1;
                }
                else
                {
                    sy++;
                    j = vy + 1;
                }
            }
            if (j == n + 1 && sx > sy)
                ans.insert({sx, t});
        }
    }
    cout << ans.size();
    for (auto i : ans)
        cout << "\n"
             << i.first << " " << i.second;
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
