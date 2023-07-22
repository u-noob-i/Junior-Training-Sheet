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

int n, m, i, j, k, q;
string s, p;
long long M = 1000000007;

void solve(int T)
{
    cin >> n;
    vector<int> a(n);
    for (i = 0; i < n; i++)
        cin >> a[i];
    vector<int> b(n);
    b[n - 1] = a[n - 1];
    for (i = n - 2; i >= 0; i--)
        b[i] = min(a[i], b[i + 1]);
    for (i = 0; i < n; i++)
    {
        int l = i + 1, r = n - 1, mid, ans = -1;
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (b[mid] < a[i])
            {
                ans = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        if (ans != -1)
            ans -= i + 1;
        cout << ans << " ";
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