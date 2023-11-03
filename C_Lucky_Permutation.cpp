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

void solve(int T)
{
    int n;
    cin >> n;
    if (n % 4 > 1)
    {
        cout << -1;
        return;
    }
    vector<int> ans(n + 1, -1);
    if (n % 2)
        ans[(n + 1) / 2] = (n + 1) / 2;
    int i = 1;
    while (i <= n && ans[i] == -1)
    {
        ans[i] = i + 1;
        ans[i + 1] = n - i + 1;
        ans[n - i + 1] = n - i;
        ans[n - i] = i;
        i += 2;
    }
    rep(i, 1, n + 1) cout << ans[i] << " ";
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