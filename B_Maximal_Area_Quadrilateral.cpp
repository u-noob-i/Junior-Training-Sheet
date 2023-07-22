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

using namespace std;

int n, m, i, j;

void solve(int T)
{
    cin >> n;
    vector<pair<double, double>> a(n);
    for (i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    double ans = 0;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            double x = 0, y = 0;
            for (int k = 0; k < n; k++)
            {
                if (k == i || k == j)
                    continue;
                double area = a[i].first * (a[j].second - a[k].second) + a[j].first * (a[k].second - a[i].second) +
                              a[k].first * (a[i].second - a[j].second);
                area = abs(area) / 2.0;
                double d = (a[k].first - a[i].first) * (a[j].second - a[i].second) -
                           (a[k].second - a[i].second) * (a[j].first - a[i].first);
                // cout << i << " " << j << " " << k << " " << area << " " << d << "\n";
                if (d < 0)
                    x = max(x, area);
                else
                    y = max(y, area);
            }
            if (x && y)
                ans = max(ans, x + y);
        }
    }
    cout << setprecision(9) << ans;
}

int main()
{
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