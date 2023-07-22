#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <climits>
#include <set>

using namespace std;

int n, m, i, j;
string s;

void solve(int T)
{
    long long k, mh = LLONG_MAX;
    cin >> n >> k;
    vector<long long> a(n), b(200002, 0);
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        mh = min(a[i], mh);
        b[1]++;
        b[a[i] + 1]--;
    }
    sort(a.begin(), a.end());
    if (a[0] == a[n - 1])
    {
        cout << 0;
        return;
    }
    for (i = 1; i < 200002; i++)
        b[i] += b[i - 1];
    long long ans = 0, cur = 0, neg = 0;
    i = 200000;
    while (i > mh)
    {
        while (i > mh && cur + b[i] <= k)
            cur += b[i--];
        ans++;
        cur = 0;
    }
    cout << ans;
}

int main()
{
    int t;
    t = 1;
    for (int p = 1; p <= t; p++)
    {
        solve(p);
        cout << "\n";
    }
}