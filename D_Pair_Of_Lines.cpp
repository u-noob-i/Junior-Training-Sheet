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

using namespace std;

int n, m, i, j, k;
string s, p;
long long M = 1000000007;

bool checkCol(pair<long long, long long> &x, pair<long long, long long> &y, pair<long long, long long> &z)
{
    long long val = (x.first * (y.second - z.second)) + (y.first * (z.second - x.second)) + (z.first * (x.second - y.second));
    if (!val)
        return 1;
    return 0;
}

bool check(vector<pair<long long, long long>> &a, int f, int s)
{
    vector<pair<long long, long long>> b;
    for (i = 0; i < n; i++)
    {
        if (i == f || i == s)
            continue;
        if (!checkCol(a[f], a[s], a[i]))
            b.push_back(a[i]);
    }
    for (i = 2; i < b.size(); i++)
        if (!checkCol(b[0], b[1], b[i]))
            return 0;
    return 1;
}

void solve(int T)
{
    cin >> n;
    vector<pair<long long, long long>> a(n);
    for (i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    if (n <= 4)
    {
        cout << "YES";
        return;
    }
    if (check(a, 0, 1) || check(a, 0, 2) || check(a, 1, 2))
        cout << "YES";
    else
        cout << "NO";
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