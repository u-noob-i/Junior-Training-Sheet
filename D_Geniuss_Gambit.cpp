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
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define ll long long
#define rep(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define irep(a, b, c) for (int(a) = (b); (a) >= (c); --(a))

ll M = 998244353;

void solve(int T)
{
    int a, b, k;
    cin >> a >> b >> k;
    if ((k && k >= a + b - 1) || (b == 1 && k) || (!a && k))
    {
        cout << "No";
        return;
    }
    cout << "Yes\n";
    string x = "", y;
    rep(i, 0, b) x += "1";
    rep(i, b, a + b) x += "0";
    y = x;
    if (!k)
    {
        cout << x << "\n"
             << x;
        return;
    }
    int zc = 1, oc = 1;
    x[a + b - 1 - k] = y[a + b - 1] = '1';
    y[a + b - 1 - k] = x[a + b - 1] = '0';
    int start = 0;
    if (a + b - 1 - k > 0)
    {
        start++;
        x[0] = y[0] = '1';
        oc++;
    }
    rep(i, start, a + b - 1)
    {
        if (i == a + b - 1 - k)
            continue;
        if (zc < a)
        {
            zc++;
            x[i] = y[i] = '0';
        }
        else
        {
            oc++;
            x[i] = y[i] = '1';
        }
    }
    cout << x << "\n"
         << y;
}

int main()
{
    cin.sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    t = 1;
    for (int T = 1; T <= t; T++)
    {
        solve(T);
        cout << "\n";
    }
}