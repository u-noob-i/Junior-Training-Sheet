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
#define INF 1e9

ll M = 1000000007;

void solve()
{
    int n, m, w;
    cin >> n >> w >> m;
    w *= m;
    // cout << n * w / m << "\n";
    vector<int> cups(m, n * w / m), bottles(n, w), bcount(n, 0);
    vector<vector<int>> a(m);
    vector<set<int>> bb(n);
    int count = 0;
    rep(i, 0, m)
    {
        rep(j, 0, n)
        {
            if (!cups[i])
                break;
            if (!bottles[j] || bcount[j] == 2 || bb[j].find(i) != bb[j].end())
                continue;
            int have = min(bottles[j], cups[i]);
            a[i].push_back(j + 1);
            a[i].push_back(have);
            cups[i] -= have;
            bottles[j] -= have;
            bcount[j]++;
            bb[j].insert(i);
            // cout << i + 1 << " " << j + 1 << " : " << have << "\n";
        }
        if (!cups[i])
            count++;
    }
    if (count != m)
    {
        cout << "NO";
        return;
    }
    cout << "YES";
    rep(i, 0, m)
    {
        cout << "\n";
        for (int j = 0; j < a[i].size(); j += 2)
            cout << a[i][j] << " " << fixed << setprecision(6) << 1.0 * a[i][j + 1] / (1.0 * m) << " ";
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