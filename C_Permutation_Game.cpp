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
#include <climits>

using namespace std;

int n, m, i, j, k;
string s;
long long M = 1000000007;

void solve(int T)
{
    cin >> n;
    vector<int> a(n + 1);
    for (i = 1; i <= n; i++)
        cin >> a[i];
    map<int, int> loc;
    for (i = 1; i <= n; i++)
        loc[a[i]] = i;
    vector<char> ans(n + 1);
    for (i = n; i; i--)
    {
        j = loc[i];
        bool f = 0;
        for (k = j + i; k <= n; k += i)
            if (a[k] > i && ans[k] == 'B')
            {
                f = 1;
                break;
            }
        for (k = j - i; k > 0; k -= i)
            if (a[k] > i && ans[k] == 'B')
            {
                f = 1;
                break;
            }
        if (f)
            ans[j] = 'A';
        else
            ans[j] = 'B';
    }
    for (i = 1; i <= n; i++)
        cout << ans[i];
}

int main()
{
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