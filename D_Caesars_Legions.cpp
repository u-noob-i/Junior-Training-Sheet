#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <queue>
#include <climits>
#include <sstream>
#include <tuple>
#include <iomanip>

using namespace std;

int n, m, i, j;
string s;
long long modu = 100000000;
long long dp[101][101][11][11];

void solve(int T)
{
    int k1, k2;
    cin >> n >> m >> k1 >> k2;
    for (i = 0; i <= n; i++)
        for (j = 0; j <= m; j++)
            for (int k = 0; k <= k1; k++)
                for (int p = 0; p <= k2; p++)
                {
                    long long ans;
                    if (i + j == 0)
                        ans = 1;
                    else
                    {
                        ans = 0;
                        if (i && k)
                            ans = (ans + dp[i - 1][j][k - 1][k2]) % modu;
                        if (j && p)
                            ans = (ans + dp[i][j - 1][k1][p - 1]) % modu;
                    }
                    dp[i][j][k][p] = ans;
                }
    cout << dp[n][m][k1][k2];
}

int main()
{

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    t = 1;
    for (int q = 1; q <= t; q++)
    {
        solve(t);
    }
}