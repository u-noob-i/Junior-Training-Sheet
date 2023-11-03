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
#include <bitset>
#include <random>
#include <chrono>

using namespace std;

#define ll long long
#define rep(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define irep(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define INF 1e9

ll M = 1000000007;

void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (!a && !b && !c && !d)
    {
        cout << 0;
        return;
    }
    if (!b && !c)
    {
        if (a && d)
        {
            cout << "Impossible";
            return;
        }
        else if (a)
        {
            int i = 1;
            while (1)
            {
                if (i * (i - 1) / 2 == a)
                {
                    string s(i, '0');
                    cout << s;
                    return;
                }
                if (i * (i - 1) / 2 > a)
                {
                    cout << "Impossible";
                    return;
                }
                i++;
            }
        }
        else
        {
            int i = 1;
            while (1)
            {
                if (i * (i - 1) / 2 == d)
                {
                    string s(i, '1');
                    cout << s;
                    return;
                }
                if (i * (i - 1) / 2 > d)
                {
                    cout << "Impossible";
                    return;
                }
                i++;
            }
        }
    }
    int n = -1, m = -1;
    int i = 1;
    while (n == -1 || m == -1)
    {
        ll x = 1ll * i * (i - 1) / 2;
        if (x > a && x > d)
            break;
        if (x == a)
            n = i;
        if (x == d)
            m = i;
        i++;
    }
    if (n == -1 || m == -1)
    {
        cout << "Impossible";
        return;
    }
    string s(n + m, '.');
    int x = n, y = m;
    // cout << n << " " << m << "\n";
    rep(i, 0, n + m)
    {
        if (!b && !c)
        {
            if (x && y)
            {
                cout << "Impossible";
                return;
            }
            else if (x)
            {
                x--;
                s[i] = '0';
            }
            else
            {
                y--;
                s[i] = '1';
            }
        }
        else if (x && b >= y)
        {
            s[i] = '0';
            x--;
            b -= y;
        }
        else if (y && c >= x)
        {
            s[i] = '1';
            y--;
            c -= x;
        }
        else
        {
            cout << "Impossible";
            return;
        }
    }
    if (b || c)
    {
        cout << "Impossible";
        return;
    }
    cout << s;
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
        solve();
        cout << "\n";
    }
}