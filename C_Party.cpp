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

int getlevel(vector<int> &p, vector<int> &level, int i)
{
    if (level[i] != -1)
        return level[i];
    if (p[i] == -1)
        level[i] = 1;
    else
        level[i] = 1 + getlevel(p, level, p[i]);
    return level[i];
}

void solve(int T)
{
    int n;
    cin >> n;
    vector<int> p(n + 1), level(n + 1, -1);
    rep(i, 1, n + 1) cin >> p[i];
    int ans = 1;
    rep(i, 1, n + 1) ans = max(ans, getlevel(p, level, i));
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