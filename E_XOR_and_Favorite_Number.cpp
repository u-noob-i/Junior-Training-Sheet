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

using namespace std;

#define ll long long
#define rep(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define irep(a, b, c) for (int(a) = (b); (a) >= (c); --(a))

int n, m, i, j, k;
string s;
ll M = 1000000007;

struct Query
{
    int l, r, ind;
    bool operator<(const Query a) const
    {
        return r < a.r;
    }
};

const int block_size = 356;

void solve(int T)
{
    cin >> n >> m >> k;
    vector<int> pref(n + 1, 0);
    rep(i, 0, n)
    {
        cin >> pref[i + 1];
        pref[i + 1] ^= pref[i];
    }
    vector<vector<Query>> q(n / block_size + 2);
    rep(i, 0, m)
    {
        int l, r;
        cin >> l >> r;
        q[l / block_size].push_back({l - 1, r + 1, i});
    }
    rep(i, 0, q.size()) sort(q[i].begin(), q[i].end());
    ll result = 0;
    vector<ll> ans(m);
    vector<int> count(1 << 20, 0);
    rep(i, 0, q.size())
    {
        int left = i * block_size, right = left;
        rep(j, 0, q[i].size())
        {
            while (right < q[i][j].r)
            {
                result += count[k ^ pref[right]];
                count[pref[right]]++;
                right++;
            }
            while (left < q[i][j].l)
            {
                count[pref[left]]--;
                result -= count[k ^ pref[left]];
                left++;
            }
            while (left > q[i][j].l)
            {
                left--;
                result += count[k ^ pref[left]];
                count[pref[left]]++;
            }
            ans[q[i][j].ind] = result;
        }
        while (left < right)
        {
            count[pref[left]]--;
            result -= count[k ^ pref[left]];
            left++;
        }
    }
    rep(i, 0, m) cout << ans[i] << "\n";
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
        // cout << "\n";
    }
}