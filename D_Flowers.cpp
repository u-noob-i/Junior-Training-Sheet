#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <numeric>

using namespace std;

int n, m, i, j;
long long M = 1000000007;

void solve(int T)
{
    int x, y, k;
    cin >> n >> k;
    long long dp[100001];
    for (i = 0; i < k; i++)
        dp[i] = 1;
    for (i = k; i <= 100000; i++)
        dp[i] = (dp[i - 1] + dp[i - k]) % M;
    dp[0] = 0;
    for (i = 2; i <= 100000; i++)
        dp[i] = (dp[i] + dp[i - 1]) % M;
    for (i = 0; i < n; i++)
    {
        cin >> x >> y;
        long long ans = (dp[y] - dp[x - 1]) % M;
        if (ans < 0)
            ans += M;
        cout << ans << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    for (int i = 1; i <= t; i++)
    {
        solve(t);
        cout << "\n";
    }
}