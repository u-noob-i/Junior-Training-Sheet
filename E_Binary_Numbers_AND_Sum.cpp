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
#include <climits>

using namespace std;

int n, m, i, j, k;
string s, p;
long long M = 998244353;

void solve(int T)
{
    cin >> n >> m >> s >> p;
    vector<long long> a(max(n, m), 0);
    for (i = m - 1, j = 0; i >= 0; i--, j++)
    {
        if (p[j] == '1')
            a[i]++;
        if (i < m - 1)
            a[i] += a[i + 1];
    }
    long long ans = 0;
    vector<long long> power(max(n, m));
    power[0] = 1;
    for (i = 1; i < max(n, m); i++)
        power[i] = (power[i - 1] * 2) % M;
    for (i = 0, j = n - 1; i < n; i++, j--)
    {
        if (s[j] == '1')
        {
            ans += (a[i] * power[i]) % M;
            ans %= M;
        }
    }
    cout << ans;
}

int main()
{
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