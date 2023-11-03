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

#define ll long long
#define rep(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define irep(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define INF 1e18

ll M = 1000000007;

void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    string dp[] = {"1869", "6198", "1896", "9186", "9168", "6189", "8691"};
    vector<int> a(10, 0);
    rep(i, 0, n) a[s[i] - '0']++;
    a[1]--;
    a[6]--;
    a[8]--;
    a[9]--;
    int rem = 0;
    rep(i, 1, 10)
    {
        while (a[i])
        {
            cout << i;
            a[i]--;
            rem = rem * 10 + i;
            rem %= 7;
        }
    }
    cout << dp[rem];
    while (a[0])
    {
        cout << 0;
        a[0]--;
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