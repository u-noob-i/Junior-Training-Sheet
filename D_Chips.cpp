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

int n, m, i, j, k;
string s, p;
long long M = 1000000007;

void solve(int T)
{
    cin >> n >> m;
    vector<pair<int, int>> a(m);
    for (i = 0; i < m; i++)
        cin >> a[i].first >> a[i].second;
    set<int> x, y;
    for (i = 2; i < n; i++)
    {
        x.insert(i);
        y.insert(i);
    }
    for (i = 0; i < m; i++)
    {
        x.erase(a[i].first);
        y.erase(a[i].second);
    }
    if (n % 2 && x.find((n + 1) / 2) != x.end() && y.find((n + 1) / 2) != y.end())
        x.erase((n + 1) / 2);
    cout << x.size() + y.size();
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