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

int n, m, i, j, k;
string s;
long long M = 1000000007;

void solve(int T)
{
    long long a, b, c, ca, cb, cc, money, ham = 0, bur = 0, che = 0;
    cin >> s >> a >> b >> c >> ca >> cb >> cc >> money;
    n = s.length();
    for (i = 0; i < n; i++)
        if (s[i] == 'B')
            ham++;
        else if (s[i] == 'S')
            bur++;
        else
            che++;
    long long ans = 0, l = 0, r = 1000000000000 + 200, mid;
    // cout << ham << " " << bur << " " << che << "\n";
    while (l <= r)
    {
        mid = (l + r) / 2;
        long long cost = (max(0ll, ham * mid - a) * ca) + (max(0ll, bur * mid - b) * cb) + (max(0ll, che * mid - c) * cc);
        if (cost <= money)
        {
            // cout << mid << " " << money << "\n";
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
    t = 1;
    for (int i = 1; i <= t; i++)
    {
        solve(t);
        cout << "\n";
    }
}