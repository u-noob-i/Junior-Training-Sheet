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

#define rep(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define irep(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define vpl vector<pair<long long, long long>>
#define pl pair<long long, long long>
#define vl vector<long long>
#define vpi vector<pair<int, int>>
#define pi pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define ll long long
#define INF 1e9

void solve()
{
    int n, k, x, y, z, sum = 0;
    cin >> n >> k;
    vi a;
    rep(i, 1, n)
    {
        cin >> x;
        sum += min(x, k);
        if (x > k)
            a.push_back(x - k);
    }
    sort(a.begin(), a.end());
    n = a.size();
    if (n == 1)
        sum += a[0];
    if (n >= 2)
    {
        x = a[n - 1];
        y = a[n - 2];
        z = 0;
        rep(i, 0, n - 3) z += a[i];
        if (z <= y)
            sum += x - (y - z);
        else if ((z - y) % 2)
            sum += x - 1;
        else
            sum += x;
    }
    cout << sum;
}

int main()
{
    cin.sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int T = 1; T <= t; T++)
    {
        solve();
        cout << "\n";
    }
}