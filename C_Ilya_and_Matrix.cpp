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
    cin >> n;
    vector<long long> a(n);
    for (i = 0; i < n; i++)
        cin >> a[i];
    if (n == 1)
    {
        cout << a[0];
        return;
    }
    sort(a.begin(), a.end(), greater<long long>());
    long long ans = a[0];
    for (i = 1; i < n; i++)
        a[i] += a[i - 1];
    for (i = 4; i <= n; i *= 4)
        ans += a[i - 1];
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    for (int p = 1; p <= t; p++)
    {
        solve(p);
        cout << "\n";
    }
}