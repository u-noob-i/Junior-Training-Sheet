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

bool check(vector<vector<int>> &a, int cur)
{
    for (i = 0; i < n; i += 2 * cur)
    {
        int p = i;
        j = (2 * cur) - 1;
        while (p < j)
        {
            for (int q = 0; q < m; q++)
                if (a[p][q] != a[j][q])
                    return 0;
            p++;
            j--;
        }
    }
    return 1;
}

void solve(int T)
{
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            cin >> a[i][j];
    int ans = n, cur = n;
    while (1)
    {
        if (cur % 2)
            break;
        if (check(a, cur / 2))
        {
            ans = cur / 2;
            cur /= 2;
        }
        else
            break;
    }
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