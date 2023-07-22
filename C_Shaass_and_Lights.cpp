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

long long n, m, i, j;
string s;
long long modu = 1000000007;

void solve(int T)
{
    cin >> n >> m;
    vector<int> a(m);
    for (i = 0; i < m; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    vector<vector<long long>> nCr(1001, vector<long long>(1001));
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= i; j++)
        {
            if (j == 0 || j == i)
                nCr[i][j] = 1;
            else
                nCr[i][j] = (nCr[i - 1][j - 1] + nCr[i - 1][j]) % modu;
        }
    }
    long long pow[1001];
    pow[0] = 1;
    pow[1] = 1;
    for (i = 2; i <= n; i++)
        pow[i] = (pow[i - 1] * 2) % modu;
    int count = 0;
    long long ans = 1;
    for (i = 0; i < m; i++)
    {
        long long x;
        if (i == 0)
            x = a[i] - 1;
        else
        {
            x = a[i] - a[i - 1] - 1;
            ans = (ans * pow[x]) % modu;
        }
        count += x;
        ans = (ans * nCr[count][x]) % modu;
    }
    count += n - a[m - 1];
    ans = (ans * nCr[count][n - a[m - 1]]) % modu;
    cout << ans;
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