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

class Compare
{
public:
    bool operator()(vector<ll> a, vector<ll> b)
    {
        return (a[0] < b[0]);
    }
};

void solve(int T)
{
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    priority_queue<vector<ll>, vector<vector<ll>>, Compare> pq;
    ll sum = 0;
    rep(i, 0, n) sum += a[i];
    pq.push({sum, 0, n - 1});
    int i, j;
    set<pair<int, int>> s;
    while (k)
    {
        k--;
        sum = pq.top()[0];
        i = pq.top()[1];
        j = pq.top()[2];
        pq.pop();
        cout << sum << " ";
        if (i == j)
            continue;
        if (s.find({i + 1, j}) == s.end())
        {
            s.insert({i + 1, j});
            pq.push({sum - a[i], i + 1, j});
        }
        if (s.find({i, j - 1}) == s.end())
        {
            s.insert({i, j - 1});
            pq.push({sum - a[j], i, j - 1});
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
        solve(T);
        cout << "\n";
    }
}