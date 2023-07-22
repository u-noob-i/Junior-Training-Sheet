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
    int x, y, z;
    cin >> m >> n;
    vector<int> a, b(m);
    for (i = 0; i < m; i++)
        cin >> b[i];
    int f = 0;
    for (i = 0; i < n; i++)
    {
        cin >> x >> y >> z;
        if (x == 1 && y == 1000000000)
            f++;
        else if (x == 1)
            a.push_back(y);
    }
    n = a.size();
    if (!m || !n)
    {
        cout << f;
        return;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ans = INT_MAX, temp;
    for (i = 0; i <= m; i++)
    {
        x = i < m ? b[i] : 1000000000;
        int l = 0, r = n - 1, mid, ind = -1;
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (a[mid] < x)
            {
                ind = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        if (ind == -1)
            ans = min(ans, n + i);
        else
            ans = min(ans, n - ind - 1 + i);
    }
    cout << f + ans;
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