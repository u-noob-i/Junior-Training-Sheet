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

using namespace std;

int n, m, i, j, k;
string s, p;
long long M = 998244353;

void solve(int T)
{
    int temp, count, ans = 0;
    cin >> n >> m;
    vector<long long> a(n), b(m);
    for (i = 0; i < n; i++)
        cin >> a[i];
    for (i = 0; i < m; i++)
        cin >> b[i];
    long long mem[32], rem[32];
    for (i = 0; i < 32; i++)
        mem[i] = rem[i] = 0;
    for (i = 0; i < n; i++)
        for (j = 0; j < 32; j++)
            if ((1ll << j) & a[i])
                mem[j]++;
    for (i = 0; i < m; i++)
        rem[b[i]]++;
    for (i = 0; i < 32; i++)
    {
        if (!mem[i])
            continue;
        long long x = (1ll << i) * mem[i];
        for (j = 0; j <= i; j++)
        {
            long long y = (1ll << j);
            while (rem[j] && x - y >= 0)
            {
                ans++;
                rem[j]--;
                x -= y;
            }
        }
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