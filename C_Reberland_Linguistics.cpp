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
    string s;
    cin >> s;
    int n = s.length();
    set<string> ans;
    vector<vector<bool>> dp(n, vector<bool>(4, 0));
    irep(i, n - 2, 5)
    {
        string temp = "";
        temp += s[i];
        temp += s[i + 1];
        if (i == n - 2 || dp[i + 2][3] || (i < n - 3 && dp[i + 2][2] && (s[i] != s[i + 2] || s[i + 1] != s[i + 3])))
        {
            ans.insert(temp);
            dp[i][2] = 1;
        }
        if (i < n - 2)
        {
            temp += s[i + 2];
            if (i == n - 3 || dp[i + 3][2] == 1 || (i < n - 5 && dp[i + 3][3] && (s[i] != s[i + 3] || s[i + 1] != s[i + 4] || s[i + 2] != s[i + 5])))
            {
                ans.insert(temp);
                dp[i][3] = 1;
            }
        }
    }
    cout << ans.size();
    for (auto i : ans)
        cout << "\n"
             << i;
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