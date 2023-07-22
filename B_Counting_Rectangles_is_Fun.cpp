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
#include <queue>
#include <climits>
#include <cfloat>

using namespace std;

int n, m, i, j, k, l;
string s, p;
long long M = 1000000007;

void solve(int T)
{
    int q;
    cin >> n >> m >> q;
    vector<string> a(n);
    for (i = 0; i < n; i++)
        cin >> a[i];
    int dp[41][41][41][41], sum[41][41][41][41];
    ;
    for (i = 0; i <= 40; i++)
        for (j = 0; j <= 40; j++)
            for (k = 0; k <= 40; k++)
                for (l = 0; l <= 40; l++)
                    dp[i][j][k][l] = sum[i][j][k][l] = 0;
    for (i = 1; i <= n; i++)
    {
        for (j = i; j <= n; j++)
        {
            for (k = 1; k <= m; k++)
            {
                for (l = k; l <= m; l++)
                {
                    if (i == j && k == l)
                    {
                        if (a[i - 1][k - 1] == '0')
                            dp[i][k][j][l] = 1;
                        continue;
                    }
                    bool x = 0, y = 0;
                    if (i == j || dp[i][k][j - 1][l])
                        x = 1;
                    if (k == l || dp[i][k][j][l - 1])
                        y = 1;
                    if (a[j - 1][l - 1] == '0' && x && y)
                        dp[i][k][j][l] = 1;
                }
            }
        }
    }
    for (i = n; i >= 1; i--)
    {
        for (j = m; j >= 1; j--)
        {
            for (k = i; k <= n; k++)
            {
                for (l = j; l <= m; l++)
                {
                    sum[i][j][k][l] = dp[i][j][k][l];
                    // adding single
                    sum[i][j][k][l] = sum[i][j][k][l] + sum[i + 1][j][k][l] + sum[i][j + 1][k][l] + sum[i][j][k - 1][l] + sum[i][j][k][l - 1];
                    // subtracting pairwise
                    sum[i][j][k][l] = sum[i][j][k][l] - sum[i + 1][j + 1][k][l] - sum[i + 1][j][k - 1][l] - sum[i + 1][j][k][l - 1] - sum[i][j + 1][k - 1][l] - sum[i][j + 1][k][l - 1] - sum[i][j][k - 1][l - 1];
                    // adding triplet
                    sum[i][j][k][l] = sum[i][j][k][l] + sum[i + 1][j + 1][k - 1][l] + sum[i + 1][j + 1][k][l - 1] + sum[i + 1][j][k - 1][l - 1] + sum[i][j + 1][k - 1][l - 1];
                    // subtracting quadruple
                    sum[i][j][k][l] = sum[i][j][k][l] - sum[i + 1][j + 1][k - 1][l - 1];
                }
            }
        }
    }
    while (q--)
    {
        int x, y, z, w;
        cin >> x >> y >> z >> w;
        cout << sum[x][y][z][w] << "\n";
    }
}

int main()
{
    cin.sync_with_stdio(false);
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