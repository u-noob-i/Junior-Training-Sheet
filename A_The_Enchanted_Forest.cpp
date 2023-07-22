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

int n, m, i, j;
string s, p;
long long M = 1000000007;

void solve(int T)
{
    long long k;
    cin >> n >> k;
    vector<long long> a(n);
    for (i = 0; i < n; i++)
        cin >> a[i];
    if (k <= n)
    {
        long long x = k * (k - 1) / 2, sum = 0, cur = 0;
        for (i = 0; i < k; i++)
            cur += a[i];
        sum = cur;
        for (i = k; i < n; i++)
        {
            cur += a[i] - a[i - k];
            sum = max(sum, cur);
        }
        cout << sum + x;
        return;
    }
    long long sum = (k * (k - 1) / 2) - ((k - n) * (k - 1 - n) / 2);
    for (i = 0; i < n; i++)
        sum += a[i];
    cout << sum;
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