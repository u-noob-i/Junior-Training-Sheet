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
long long modu = 1000000009;

void solve(int T)
{
    cin >> n;
    vector<pair<int, int>> a(n);
    for (i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a.begin(), a.end());
    int count = 3;
    vector<vector<int>> ans(3, vector<int>(n));
    for (i = 0; i < n; i++)
    {
        if (count == 3 && i < n - 2 && a[i].first == a[i + 1].first && a[i].first == a[i + 2].first)
        {
            count = 0;
            ans[2][i] = a[i + 2].second;
            ans[2][i + 1] = a[i].second;
            ans[2][i + 2] = a[i + 1].second;
            ans[0][i] = ans[1][i] = a[i].second;
            ans[1][i + 1] = ans[0][i + 2] = a[i + 1].second;
            ans[1][i + 2] = ans[0][i + 1] = a[i + 2].second;
            i += 2;
        }
        else if (count == 3 && i < n - 1 && a[i].first == a[i + 1].first)
        {
            count -= 2;
            ans[0][i] = ans[1][i + 1] = ans[2][i] = a[i].second;
            ans[1][i] = ans[0][i + 1] = ans[2][i + 1] = a[i + 1].second;
            i++;
        }
        else if (count == 1 && i < n - 1 && a[i].first == a[i + 1].first)
        {
            count = 0;
            ans[0][i] = ans[1][i] = ans[2][i + 1] = a[i].second;
            ans[0][i + 1] = ans[1][i + 1] = ans[2][i] = a[i + 1].second;
            i++;
        }
        else
            ans[0][i] = ans[1][i] = ans[2][i] = a[i].second;
    }
    if (count)
    {
        cout << "NO";
        return;
    }
    cout << "YES\n";
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < n; j++)
            cout << ans[i][j] << " ";
        cout << "\n";
    }
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