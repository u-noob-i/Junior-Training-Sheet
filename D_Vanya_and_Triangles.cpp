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

int n, m, i, j, k, q;
string s, p;
long long M = 1000000007;

void solve(int T)
{
    cin >> n;
    vector<pair<double, double>> a(n);
    for (i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    long long ans = 0;
    for (i = 0; i < n; i++)
    {
        map<pair<double, double>, long long> count;
        for (j = i + 1; j < n; j++)
        {
            double slope, c;
            if (a[i].first == a[j].first)
                slope = INT_MAX;
            else
                slope = (a[i].second - a[j].second) / (a[i].first - a[j].first);
            c = a[i].second - a[i].first * slope;
            count[{slope, c}]++;
        }
        long long tot = n - i - 1;
        tot = tot * (tot - 1) / 2;
        for (auto itr = count.begin(); itr != count.end(); itr++)
        {
            long long x = itr->second;
            tot -= x * (x - 1) / 2;
        }
        ans += tot;
    }
    cout << ans;
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