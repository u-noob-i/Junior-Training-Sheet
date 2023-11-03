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
    string s;
    int n;
    ll a, b;
    cin >> a >> b >> s;
    n = s.length();
    ll xd = 0, yd = 0;
    rep(i, 0, n - 1)
    {
        if (s[i] == 'L')
            xd--;
        if (s[i] == 'R')
            xd++;
        if (s[i] == 'U')
            yd++;
        if (s[i] == 'D')
            yd--;
    }
    if (!a && !b)
    {
        cout << "Yes";
        return;
    }
    if (xd && a % xd == 0 && yd * a / xd == b && a / xd >= 0)
    {
        cout << "Yes";
        return;
    }
    if (yd && b % yd == 0 && xd * b / yd == a && b / yd >= 0)
    {
        cout << "Yes";
        return;
    }
    int x = 0, y = 0;
    rep(i, 0, n - 1)
    {
        if (s[i] == 'L')
            x--;
        if (s[i] == 'R')
            x++;
        if (s[i] == 'U')
            y++;
        if (s[i] == 'D')
            y--;
        int na = a - x, nb = b - y;
        if (!na && !nb)
        {
            cout << "Yes";
            return;
        }
        if (xd && na % xd == 0 && yd * na / xd == nb && na / xd >= 0)
        {
            cout << "Yes";
            return;
        }
        if (yd && nb % yd == 0 && xd * nb / yd == na && nb / yd >= 0)
        {
            cout << "Yes";
            return;
        }
    }
    cout << "No";
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
