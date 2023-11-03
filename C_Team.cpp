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
    int n, m;
    cin >> n >> m;
    string s(n + m, '.');
    bool turn = 0;
    int i = 1, z = n, o = m;
    if (z > o)
    {
        s[0] = '0';
        z--;
    }
    else
    {
        s[0] = '1';
        o--;
    }
    while (i < n + m)
    {
        if (s[i - 1] == '0')
        {
            if (!o)
            {
                s = "-1";
                break;
            }
            o--;
            s[i] = '1';
        }
        else if (i > 1 && s[i - 1] == s[i - 2] && s[i - 1] == '1')
        {
            if (!z)
            {
                s = "-1";
                break;
            }
            z--;
            s[i] = '0';
        }
        else if (z > o)
        {
            z--;
            s[i] = '0';
        }
        else
        {
            o--;
            s[i] = '1';
        }
        i++;
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