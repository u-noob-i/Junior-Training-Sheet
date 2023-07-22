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

void solve(int T)
{
    cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    sort(a.begin(), a.end());
    a.resize(distance(a.begin(), unique(a.begin(), a.end())));
    n = a.size();
    int ans = 0;
    rep(i, 0, n)
    {
        if (a[i] == 1)
            continue;
        int left = i + 1, val = a[i] + a[i];
        while (left < n)
        {
            int ind = -1, l = left, r = n - 1, mid;
            while (l <= r)
            {
                mid = (l + r) / 2;
                if (a[mid] < val)
                {
                    ind = mid;
                    l = mid + 1;
                }
                else
                    r = mid - 1;
            }
            if (ind == -1)
            {
                val += a[i];
                continue;
            }
            ans = max(ans, a[ind] % a[i]);
            left = ind + 1;
        }
    }
    cout << ans;
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