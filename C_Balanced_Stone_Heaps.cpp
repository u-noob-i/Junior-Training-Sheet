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

void in(vector<long long> &a, int &z)
{
    for (int x = 0; x < z; x++)
        cin >> a[x];
}

bool check(vector<long long> a, long long val)
{
    vector<long long> b = a;
    for (i = n - 1; i >= 0; i--)
    {
        if (b[i] < val)
            return 0;
        if (i < 2)
            continue;
        long long x = min(a[i], b[i] - val);
        x /= 3;
        b[i] -= 3 * x;
        b[i - 1] += x;
        b[i - 2] += 2 * x;
    }
    // cout << val << ": ";
    // for (i = 0; i < n; i++)
    //     cout << b[i] << " ";
    // cout << "\n";
    return 1;
}

void solve(int T)
{
    cin >> n;
    vector<long long> a(n), b(n);
    in(a, n);
    long long ans, l = 0, r = 1000000000, mid;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (check(a, mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
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