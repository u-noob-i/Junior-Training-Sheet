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

void solve(int T)
{
    int k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n, vector<int>(m));
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            cin >> a[i][j];
    long long x = m;
    cout << x * (x - 1) / 2 << "\n";
    if (!k)
        for (i = 1; i < m; i++)
            for (j = i + 1; j <= m; j++)
                cout << i << " " << j << "\n";
    else
        for (i = m; i > 1; i--)
            for (j = i - 1; j >= 1; j--)
                cout << i << " " << j << "\n";
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