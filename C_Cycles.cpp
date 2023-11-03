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
    vector<vector<int>> ans(101, vector<int>(101, 0));
    rep(i, 2, 101)
    {
        rep(j, 1, i)
        {
            if (!n)
                break;
            int count = 0;
            rep(k, 1, 101) if (k != i && k != j && ans[i][k] && ans[k][j]) count++;
            if (count > n)
                continue;
            n -= count;
            ans[i][j] = ans[j][i] = 1;
        }
    }
    cout << 100 << "\n";
    rep(i, 1, 101)
    {
        rep(j, 1, 101) cout << ans[i][j];
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
        solve(T);
        cout << "\n";
    }
}