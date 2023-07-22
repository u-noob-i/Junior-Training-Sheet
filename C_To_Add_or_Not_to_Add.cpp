#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <queue>
#include <climits>
#include <sstream>
#include <tuple>
#include <iomanip>

using namespace std;

int n, m, i, j;
string s;
long long modu = 100000000;

void solve(int T)
{
    cin >> n >> m;
    vector<long long> a(n + 1, 0), arr(n + 1, 0);
    for (i = 1; i <= n; i++)
        cin >> a[i];
    a[0] = INT_MIN;
    sort(a.begin(), a.end());
    for (i = 1; i <= n; i++)
    {
        arr[i] = a[i];
        a[i] += a[i - 1];
    }
    // for (i = 1; i <= n; i++)
    //     cout << a[i] << " ";
    // cout << "\n";
    long long ans = 1, ansx = arr[1];
    for (i = 2; i <= n; i++)
    {
        int l = 1, r = i - 1, mid, temp = 0;
        while (l <= r)
        {
            mid = (l + r) / 2;
            long long x = a[i - 1] - a[i - mid - 1];
            x = (arr[i] * mid) - x;
            if (x <= m)
            {
                temp = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        if (temp + 1 > ans)
        {
            // cout << temp << " " << arr[i] << "\n";
            ans = temp + 1;
            ansx = arr[i];
        }
    }
    cout << ans << " " << ansx;
}

int main()
{

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    t = 1;
    for (int q = 1; q <= t; q++)
    {
        solve(t);
    }
}