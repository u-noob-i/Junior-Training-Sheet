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

using namespace std;

int n, m, i, j;
string s;

void solve(int T)
{
    cin >> n;
    vector<int> a(n);
    for (i = 0; i < n; i++)
        cin >> a[i];
    int ans = 0;
    for (i = 1; i < n - 1; i++)
    {
        if (a[i] == a[i - 1] || a[i] == a[i + 1])
            continue;
        j = i;
        while (j < n - 1 && a[j] != a[j + 1])
            j++;
        i--;
        int o = 0, z = 0, temp = 0;
        for (int p = i; p <= j; p++)
        {
            if (a[p] == 1)
                o++;
            else
                z++;
        }
        if (o == z)
        {
            temp += o - 1;
            int x = a[i];
            while (o > 1)
            {
                a[++i] = x;
                o--;
            }
            while (z > 1)
            {
                z--;
                a[++i] = a[j];
            }
        }
        else
        {
            temp += min(o, z);
            while (i <= j)
                a[i++] = a[j];
        }
        ans = max(temp, ans);
    }
    cout << ans << "\n";
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
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