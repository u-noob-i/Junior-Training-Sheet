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
#include <stack>

using namespace std;

int n, m, i, j, k;
string s;
long long M = 1000000007;

void solve(int T)
{
    cin >> n;
    vector<pair<long long, long long>> a(n);
    for (i = 0; i < n; i++)
        cin >> a[i].first;
    for (i = 0; i < n; i++)
        cin >> a[i].second;
    stack<pair<long long, long long>> arr;
    for (i = 0; i < n; i++)
    {
        long long l = a[i].first - a[i].second + 1, r = a[i].first;
        while (arr.size() && arr.top().second >= l)
        {
            l = min(l, arr.top().first);
            r = max(r, arr.top().second);
            arr.pop();
        }
        arr.push({l, r});
    }
    long long ans = 0;
    while (arr.size())
    {
        long long x = arr.top().second - arr.top().first + 1;
        ans += x * (x + 1ll) / 2ll;
        arr.pop();
    }
    cout << ans;
}

int main()
{
    cin.sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve(t);
        cout << "\n";
    }
}