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
long long modu = 1000000007;

void solve(int T)
{
    cin >> n;
    vector<pair<pair<long long, long long>, int>> a(2 * n - 1);
    for (i = 0; i < 2 * n - 1; i++)
    {
        cin >> a[i].first.first >> a[i].first.second;
        a[i].second = i + 1;
    }
    sort(a.begin(), a.end());
    long long xt = 0;
    for (i = 0; i < 2 * n - 1; i++)
        xt += a[i].first.second;
    xt = (xt + 1) / 2;
    long long cur = 0, pur = a[2 * n - 2].first.second;
    for (i = 0; i < 2 * n - 1; i += 2)
        cur += a[i].first.second;
    for (i = 1; i < 2 * n - 1; i += 2)
        pur += a[i].first.second;
    if (cur >= xt)
    {
        cout << "YES\n";
        for (i = 0; i < 2 * n - 1; i += 2)
            cout << a[i].second << " ";
    }
    else if (pur >= xt)
    {
        cout << "YES\n";
        for (i = 1; i < 2 * n - 1; i += 2)
            cout << a[i].second << " ";
        cout << a[2 * n - 2].second;
    }
    else
        cout << "NO";
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
    cin >> t;
    for (int q = 1; q <= t; q++)
    {
        solve(t);
        cout << "\n";
    }
}