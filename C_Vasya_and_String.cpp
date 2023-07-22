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
    cin >> n >> k >> s;
    vector<int> a(n + 1, 0), b(n + 1, 0);
    for (i = 0; i < n; i++)
    {
        a[i + 1] = a[i];
        b[i + 1] = b[i];
        if (s[i] == 'a')
            a[i + 1]++;
        else
            b[i + 1]++;
    }
    int ans = 1;
    for (i = 1; i < n; i++)
    {
        int l = i, r = n, mid;
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (a[mid] - a[i - 1] <= k)
            {
                ans = max(ans, mid - i + 1);
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        l = i, r = n;
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (b[mid] - b[i - 1] <= k)
            {
                ans = max(ans, mid - i + 1);
                l = mid + 1;
            }
            else
                r = mid - 1;
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