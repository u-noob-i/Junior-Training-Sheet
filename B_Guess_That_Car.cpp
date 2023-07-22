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
#include <sstream>

using namespace std;

int n, m, i, j, k, l;
string s, p;
long long M = 1000000007;

void solve(int T)
{
    cin >> n >> m;
    vector<vector<long long>> a(n, vector<long long>(m));
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            cin >> a[i][j];
    vector<long long> row(n), col(m);
    for (i = 0; i < n; i++)
    {
        row[i] = 0;
        for (j = 0; j < m; j++)
            row[i] += a[i][j];
    }
    for (i = 0; i < m; i++)
    {
        col[i] = 0;
        for (j = 0; j < n; j++)
            col[i] += a[j][i];
    }
    long long ax = LLONG_MAX, ay = LLONG_MAX, x = 0, y = 0;
    for (i = 0; i <= 4 * n; i += 4)
    {
        long long cur = 0, temp;
        for (j = 2; j < 4 * n; j += 4)
        {
            temp = abs(j - i);
            temp *= temp;
            cur += temp * row[j / 4];
        }
        if (cur < ax)
        {
            x = i / 4;
            ax = cur;
        }
    }
    for (i = 0; i <= 4 * m; i += 4)
    {
        long long cur = 0, temp;
        for (j = 2; j < 4 * m; j += 4)
        {
            temp = abs(j - i);
            temp *= temp;
            cur += temp * col[j / 4];
        }
        if (cur < ay)
        {
            y = i / 4;
            ay = cur;
        }
    }
    cout << ax + ay << "\n"
         << x << " " << y;
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