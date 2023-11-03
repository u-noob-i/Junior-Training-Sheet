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
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <random>
#include <chrono>

using namespace std;

#define rep(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define irep(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define vpl vector<pair<long long, long long>>
#define pll pair<long long, long long>
#define vll vector<long long>
#define vpi vector<pair<int, int>>
#define pii pair<int, int>
#define vii vector<int>
#define ll long long
#define INF 1e18

void solve()
{
    int n, s;
    cin >> n >> s;
    if (n == 1 && !s)
    {
        cout << "0 0";
        return;
    }
    if (!s || s > 9 * n)
    {
        cout << "-1 -1";
        return;
    }
    string l(n, '.'), r(n, '.');
    int t = s;
    rep(i, 0, n)
    {
        int j = 0, rem = n - i - 1;
        if (!i)
            j++;
        rep(k, j, 10)
        {
            if (s - k <= rem * 9)
            {
                l[i] = '0' + k;
                s -= k;
                break;
            }
        }
        irep(k, 9, j)
        {
            if (t - k >= 0)
            {
                r[i] = '0' + k;
                t -= k;
                break;
            }
        }
    }
    cout << l << " " << r;
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