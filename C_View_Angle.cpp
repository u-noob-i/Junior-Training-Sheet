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
long long modu = 1000000007;

void solve(int T)
{
    cin >> n;
    vector<pair<int, int>> a(n);
    for (i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    vector<double> res(n);
    cout << setprecision(20);
    for (i = 0; i < n; i++)
    {
        res[i] = (atan2(a[i].second, a[i].first)) * 180.0 / 3.14159265358979323846;
        // cout << res[i] << " ";
        if (res[i] < 0)
            res[i] = 360.0 + res[i];
    }
    sort(res.begin(), res.end());
    double ans = res[n - 1] - res[0];
    for (i = 1; i < n; i++)
    {
        double temp = 360.0 - (res[i] - res[i - 1]);
        ans = min(ans, temp);
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