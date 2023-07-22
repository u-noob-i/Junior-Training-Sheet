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

int n, m, i, j;
string s;
long long M = 1000000007;

void in(vector<long long> &a, int &z)
{
    for (int x = 0; x < z; x++)
        cin >> a[x];
}

long long bs(vector<long long> &a, long long k)
{
    long long change = n - i + 2;
    long long sum = a[i - 1] - a[1];
    long long l = 0, r = 1000000000000, mid;
    while (l < r)
    {
        mid = (l + r) / 2;
        if (sum + change * (a[1] - mid) > k)
            l = mid + 1;
        else
        {
            r = mid;
        }
    }
    return l;
}

void solve(int T)
{
    long long k;
    cin >> n >> k;
    vector<long long> a(n + 1, 0);
    in(a, n);
    sort(a.begin(), a.end());
    for (i = 1; i <= n; i++)
        a[i] += a[i - 1];
    if (a[n] <= k)
    {
        cout << 0;
        return;
    }
    long long ans = a[n] - k;
    for (i = 2; i <= n; i++)
        ans = min(ans, bs(a, k) + n - i + 1);
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