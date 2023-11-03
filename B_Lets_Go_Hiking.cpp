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

ll M = 998244353;

void solve(int T)
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    int ans = 0;
    vector<int> lh(n, 1), rh(n, 1);
    int mval = 1;
    rep(i, 1, n)
    {
        if (a[i] > a[i - 1])
            lh[i] = lh[i - 1] + 1;
        else
            lh[i] = 1;
        mval = max(mval, lh[i]);
    }
    irep(i, n - 2, 0)
    {
        if (a[i] > a[i + 1])
            rh[i] = rh[i + 1] + 1;
        else
            rh[i] = 1;
        mval = max(mval, rh[i]);
    }
    int count = 0;
    rep(i, 0, n)
    {
        // cout << lh[i] << " " << rh[i] << "\n";
        if (lh[i] == mval)
            count++;
        if (rh[i] == mval)
            count++;
    }
    if (count != 2)
    {
        cout << 0;
        return;
    }
    bool f = 0;
    rep(i, 0, n) if (lh[i] == mval && rh[i] == mval) f = 1;
    if (!f)
    {
        cout << 0;
        return;
    }
    if (mval % 2)
        cout << 1;
    else
        cout << 0;
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