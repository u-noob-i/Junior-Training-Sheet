#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <climits>
#include <set>

using namespace std;

int n, m, i, j;
string s;

void solve(int T)
{
    int k, x;
    cin >> n >> k >> x;
    vector<int> a(n);
    for (i = 0; i < n; i++)
        cin >> a[i];
    int ans = 0;
    for (i = 0; i < n; i++)
    {
        vector<int> b(n + 1);
        for (j = 0; j < i; j++)
            b[j] = a[j];
        b[i] = x;
        for (j = i + 1; j <= n; j++)
            b[j] = a[j - 1];
        int l = -1, r = -1;
        if (i + 2 <= n && b[i] == b[i + 1] && b[i] == b[i + 2])
        {
            l = i - 1;
            r = i + 3;
        }
        else if (i > 0 && i + 1 <= n && b[i - 1] == b[i] && b[i] == b[i + 1])
        {
            l = i - 2;
            r = i + 2;
        }
        else if (i > 1 && b[i - 2] == b[i] && b[i] == b[i - 1])
        {
            l = i - 3;
            r = i + 1;
        }
        if (l == -1)
            continue;
        int cur = 2, in = 0;
        while (l >= in || r <= n)
        {
            if (r > n)
            {
                r = l;
                n = l;
            }
            if (l < in)
            {
                l = r;
                in = r;
            }
            if (b[l] != b[r])
                break;
            int count = 2;
            if (l == r)
                count = 1;
            while (l > in && b[l - 1] == b[l])
            {
                count++;
                l--;
            }
            while (r < n && b[r + 1] == b[r])
            {
                count++;
                r++;
            }
            if (count > 2)
            {
                cur += count;
                l--;
                r++;
                continue;
            }
            break;
        }
        ans = max(ans, cur);
    }
    cout << ans;
}

int main()
{
    int t;
    t = 1;
    for (int p = 1; p <= t; p++)
    {
        solve(p);
        cout << "\n";
    }
}