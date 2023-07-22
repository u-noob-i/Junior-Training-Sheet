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
    vector<long long> a(n);
    for (i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    if (n == 1)
    {
        cout << a[0];
        return;
    }
    long long ans = 0;
    if (a[0] < 0 && a[n - 1] < 0)
    {
        for (i = 0; i < n - 1; i++)
            ans -= a[i];
        ans += a[n - 1];
    }
    else if (a[0] > 0 && a[n - 1] > 0)
    {
        ans -= a[0];
        for (i = 1; i < n; i++)
            ans += a[i];
    }
    else
    {
        for (i = 0; i < n; i++)
            if (a[i] < 0)
                ans -= a[i];
            else
                ans += a[i];
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