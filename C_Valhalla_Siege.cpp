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

using namespace std;

int n, m, i, j;
string s;

void solve(int T)
{
    cin >> n >> m;
    vector<long long> a(n + 1, 0), b(m + 1, 0);
    for (i = 1; i <= n; i++)
        cin >> a[i];
    for (i = 1; i <= m; i++)
        cin >> b[i];
    for (i = 2; i <= n; i++)
        a[i] += a[i - 1];
    for (i = 2; i <= m; i++)
        if (b[i - 1] >= a[n])
            continue;
        else
            b[i] += b[i - 1];
    long long cur = 0;
    for (i = 1; i <= m; i++)
    {
        int l = 1, r = n, mid, ind;
        if (a[n] <= b[i])
        {
            cout << n << "\n";
            continue;
        }
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (a[mid] > b[i])
            {
                ind = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        cout << n - ind + 1 << "\n";
    }
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