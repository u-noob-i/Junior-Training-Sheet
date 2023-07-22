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
    vector<long long> a(n);
    for (i = 0; i < n; i++)
        cin >> a[i];
    vector<long long> count(32, 0);
    long long ans = 0;
    for (i = 0; i < n; i++)
        for (long long x = 20; x >= 0; x--)
            if ((a[i] & (1ll << x)) != 0)
                count[x]++;
    vector<long long> vals(n, 0);
    for (long long x = 20; x >= 0; x--)
    {
        int j = 0;
        while (count[x])
        {
            count[x]--;
            vals[j++] |= (1ll << x);
        }
    }
    for (i = 0; i < n; i++)
        ans += vals[i] * vals[i];
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