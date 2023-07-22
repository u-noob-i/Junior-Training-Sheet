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

using namespace std;

int n, m, i, j;
string s;

void solve(int T)
{
    int x, y;
    long long k;
    cin >> n >> m >> k >> x >> y;
    if (n == 1)
    {
        long long a = 0, b = 0, c = 0;
        a = b = c = k / m;
        if (k % m)
            a++;
        if (k % m >= y)
            c++;
        cout << a << " " << b << " " << c;
        return;
    }
    vector<vector<long long>> a(n, vector<long long>(m));
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            a[i][j] = 0;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (k >= (i * m) + j + 1)
                a[i][j] = 1;
            if (k > n * m)
            {
                long long temp = (k - (n * m)) / (2 * (n - 1) * m);
                if (i == 0 || i == n - 1)
                    a[i][j] += temp;
                else
                    a[i][j] += 2 * temp;
            }
        }
    }
    k = max(0ll, k - (n * m));
    k = k % (2 * (n - 1) * m);
    i = n - 2;
    j = 0;
    while (i >= 0 && k > 0)
    {
        a[i][j]++;
        k--;
        j++;
        if (j == m)
        {
            j = 0;
            i--;
        }
    }
    i = 1;
    j = 0;
    while (i < n && k > 0)
    {
        a[i][j]++;
        k--;
        j++;
        if (j == m)
        {
            j = 0;
            i++;
        }
    }
    long long d = LLONG_MIN, b = LLONG_MAX, c = a[x - 1][y - 1];
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
        {
            d = max(d, a[i][j]);
            b = min(b, a[i][j]);
        }
    cout << d << " " << b << " " << c;
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