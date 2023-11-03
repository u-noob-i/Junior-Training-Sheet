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
    int n, k, p;
    cin >> n >> k >> p;
    vector<int> odd, even;
    rep(i, 0, n)
    {
        int x;
        cin >> x;
        if (x % 2)
            odd.push_back(x);
        else
            even.push_back(x);
    }
    if (odd.size() < k - p || (odd.size() - k + p) % 2)
    {
        cout << "NO";
        return;
    }
    vector<vector<int>> parts(k);
    int j = 0, l = 0;
    rep(i, 0, k - p) parts[i].push_back(odd[j++]);
    rep(i, k - p, k)
    {
        if (j < odd.size())
        {
            parts[i].push_back(odd[j]);
            parts[i].push_back(odd[j + 1]);
            j += 2;
        }
        else if (l < even.size())
            parts[i].push_back(even[l++]);
    }
    while (j < odd.size())
    {
        parts[k - 1].push_back(odd[j]);
        parts[k - 1].push_back(odd[j + 1]);
        j += 2;
    }
    while (l < even.size())
        parts[k - 1].push_back(even[l++]);
    if (!parts[k - 1].size())
    {
        cout << "NO";
        return;
    }
    cout << "YES\n";
    rep(i, 0, k)
    {
        cout << parts[i].size() << " ";
        for (auto x : parts[i])
            cout << x << " ";
        cout << "\n";
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