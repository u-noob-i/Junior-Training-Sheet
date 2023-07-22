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

int n, m, i, j, k;
string s, p;
long long M = 1000000007;

void solve(int T)
{
    long long a, b;
    cin >> a >> b >> n;
    while (n--)
    {
        long long l, t, x;
        cin >> l >> t >> x;
        long long left = l, right = 100000000, mid, ans = -1;
        while (left <= right)
        {
            mid = (left + right) / 2;
            long long sum = (mid * a) + ((mid * (mid - 1) / 2) * b);
            sum -= ((l - 1) * a) + (((l - 1) * (l - 2) / 2) * b);
            if (sum <= t * x && a + (mid - 1) * b <= t)
            {
                // cout << l << " " << mid << " " << sum << "\n";
                ans = mid;
                left = mid + 1;
            }
            else
                right = mid - 1;
        }
        cout << ans << "\n";
    }
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