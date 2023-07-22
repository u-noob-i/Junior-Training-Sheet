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

pair<int, int> rotateabout(pair<int, int> a, pair<int, int> b)
{
    return {b.first + b.second - a.second, a.first + b.second - b.first};
}

int distSq(pair<int, int> p, pair<int, int> q)
{
    return (p.first - q.first) * (p.first - q.first) + (p.second - q.second) * (p.second - q.second);
}

bool isSquare(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3, pair<int, int> p4)
{
    int d2 = distSq(p1, p2);
    int d3 = distSq(p1, p3);
    int d4 = distSq(p1, p4);
    if (d2 == 0 || d3 == 0 || d4 == 0)
        return 0;
    if (d2 == d3 && 2 * d2 == d4 && 2 * distSq(p2, p4) == distSq(p2, p3))
        return 1;
    if (d3 == d4 && 2 * d3 == d2 && 2 * distSq(p3, p2) == distSq(p3, p4))
        return 1;
    if (d2 == d4 && 2 * d2 == d3 && 2 * distSq(p2, p3) == distSq(p2, p4))
        return 1;
    return 0;
}

int getmin(vector<pair<pair<int, int>, pair<int, int>>> a)
{
    int ret = INT_MAX;
    for (int x = 0; x < 4; x++)
    {
        for (int y = 0; y < 4; y++)
        {
            for (int w = 0; w < 4; w++)
            {
                for (int z = 0; z < 4; z++)
                {
                    if (isSquare(a[0].first, a[1].first, a[2].first, a[3].first))
                        ret = min(ret, x + y + z + w);
                    a[3].first = rotateabout(a[3].first, a[3].second);
                }
                a[2].first = rotateabout(a[2].first, a[2].second);
            }
            a[1].first = rotateabout(a[1].first, a[1].second);
        }
        a[0].first = rotateabout(a[0].first, a[0].second);
    }
    return (ret == INT_MAX ? -1 : ret);
}

void solve(int T)
{
    cin >> n;
    vector<vector<pair<pair<int, int>, pair<int, int>>>> a(n, vector<pair<pair<int, int>, pair<int, int>>>(4));
    vector<int> ans(n);
    for (i = 0; i < n; i++)
        for (j = 0; j < 4; j++)
            cin >> a[i][j].first.first >> a[i][j].first.second >> a[i][j].second.first >> a[i][j].second.second;
    for (i = 0; i < n; i++)
        ans[i] = getmin(a[i]);
    for (i = 0; i < n; i++)
        cout << ans[i] << "\n";
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