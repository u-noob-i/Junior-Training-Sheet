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
    vector<int> ans;
    if (n % 2)
    {
        for (int i = n - n / 2; i <= n + n / 2; i++)
            ans.push_back(i + 2);
        ans[0]--;
        ans[n - 1]++;
        ans[n - 2]++;
    }
    else
    {
        for (int i = n / 2; i <= 3 * n / 2; i++)
            if (i != n)
                ans.push_back(i);
    }
    rep(i, 0, n) cout << ans[i] << " ";
}

int main()
{
    cin.sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int T = 1; T <= t; T++)
    {
        solve(T);
        cout << "\n";
    }
}