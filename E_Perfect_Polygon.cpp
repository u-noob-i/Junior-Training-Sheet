#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <iomanip>
#include <numeric>
#include <queue>
#include <climits>
#include <cfloat>
#include <sstream>

using namespace std;

int n, m, i, j, k, q;
string s, p;
long long M = 1000000007;

void solve(int T)
{
    long long w, h;
    cin >> m >> w >> h >> n;
    vector<pair<double, double>> a(n);
    for (i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    double x = 0, y = 0;
    for (i = 0; i < n; i++)
    {
        x += a[i].first;
        y += a[i].second;
    }
    x /= n;
    y /= n;
    double angle = m;
    m *= 3.14159 / 180;
    double xmin = LLONG_MAX, xmax = LLONG_MIN, ymin = LLONG_MAX, ymax = LLONG_MIN;
    for (i = 0; i < n; i++)
    {
        a[i].first -= x;
        a[i].second -= y;
        double x1, y1;
        x1 = a[i].first * cos(angle) - a[i].second * sin(angle);
        y1 = a[i].second * cos(angle) + a[i].first * sin(angle);
        a[i].first = x1 + x;
        a[i].second = y1 + y;
        xmin = min(xmin, a[i].first);
        xmax = max(xmax, a[i].first);
        ymin = min(ymin, a[i].second);
        ymax = max(ymax, a[i].second);
    }
    double ratiox = w, ratioy = h;
    ratiox /= (xmax - xmin);
    ratioy /= (ymax - ymin);
    for (i = 0; i < n; i++)
    {
        a[i].first = ratiox * (a[i].first - xmin);
        a[i].second = ratioy * (a[i].second - ymin);
        cout << setprecision(6) << a[i].first << " " << a[i].second << "\n";
    }
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