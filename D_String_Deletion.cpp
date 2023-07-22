#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <iomanip>
#include <numeric>
#include <queue>
#include <climits>
#include <cfloat>
#include <sstream>
#include <stack>

using namespace std;

#define rep(a, b, c) for (int(a) = (b); (a) < (c); ++(a))

int n, m, i, j, k;
string s;
long long M = 1000000007;

void solve(int T)
{
    cin >> n >> s;
    int ans = 0;
    set<int> x;
    for (i = 0; i < n; i++)
        while (i < n - 1 && s[i] == s[i + 1])
            x.insert(i++);
    for (i = 0; i < n; i++)
    {
        if (s[i] == '.')
            continue;
        ans++;
        if (!x.size())
        {
            i++;
            while (i < n && s[i] == '.')
                i++;
        }
        else
        {
            int a = *x.begin();
            x.erase(a);
            if (i == a)
            {
                while (i < n - 1 && s[i + 1] == s[i])
                {
                    i++;
                    x.erase(i);
                }
            }
            s[a] = '.';
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
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve(t);
        cout << "\n";
    }
}