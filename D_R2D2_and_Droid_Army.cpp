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
    int cost;
    cin >> n >> m >> cost;
    vector<vector<int>> a(n, vector<int>(m));
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            cin >> a[i][j];
    vector<map<int, int>> ct(m);
    int fin = 0, sum;
    vector<int> ans(m);
    i = 0, j = 0;
    while (j < n)
    {
        for (k = 0; k < m; k++)
            ct[k][a[j][k]]++;
        sum = 0;
        for (k = 0; k < m; k++)
            sum += (ct[k].rbegin()->first);
        if (sum <= cost)
        {
            if (j - i + 1 > fin)
            {
                fin = j - i + 1;
                for (k = 0; k < m; k++)
                    ans[k] = ct[k].rbegin()->first;
            }
        }
        else
        {
            while (i <= j)
            {
                for (k = 0; k < m; k++)
                {
                    ct[k][a[i][k]]--;
                    if (!ct[k][a[i][k]])
                        ct[k].erase(a[i][k]);
                }
                i++;
                if (i > j)
                    break;
                sum = 0;
                for (k = 0; k < m; k++)
                    sum += (ct[k].rbegin()->first);
                if (sum <= cost)
                    break;
            }
        }
        // cout << i << " " << j << " " << sum << "\n";
        // cout << fin << "\n---------------\n";
        j++;
    }
    for (i = 0; i < m; i++)
        cout << ans[i] << " ";
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