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

ll M = 1000000007;

bool ispos(vector<int> &a, int n, int k, int x)
{
    vector<int> arr(n + 1, 0);
    rep(i, 0, n)
    {
        if (a[i] >= x)
            arr[i + 1] = 1;
        else
            arr[i + 1] = -1;
        arr[i + 1] += arr[i];
    }
    int y = 0;
    rep(i, k, n + 1)
    {
        if (y < arr[i])
            return 1;
        y = min(y, arr[i - k + 1]);
    }
    return 0;
}

void solve(int T)
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    int ans = -1, l = 1, r = INT_MAX, mid;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (ispos(a, n, k, mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
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