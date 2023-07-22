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
    int k;
    cin >> s >> k;
    vector<pair<char, char>> a(k);
    for (i = 0; i < k; i++)
        cin >> a[i].first >> a[i].second;
    n = s.length();
    int ans = 0;
    for (i = 0; i < n - 1; i++)
    {
        int x = -1;
        for (j = 0; j < k; j++)
            if (s[i] == a[j].first || s[i] == a[j].second)
            {
                x = j;
                break;
            }
        if (x == -1)
            continue;
        int l = i, r = i;
        while (r < n - 1 && (s[r + 1] == a[x].first || s[r + 1] == a[x].second))
            r++;
        int c1 = 0, c2 = 0;
        while (l <= r)
        {
            if (s[l] == a[x].first)
                c1++;
            else
                c2++;
            l++;
        }
        // cout << i << " " << r << " " << c1 << " " << c2 << "\n";
        ans += min(c1, c2);
        i = r;
    }
    cout << ans;
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