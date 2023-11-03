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

#define rep(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define irep(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define vpl vector<pair<long long, long long>>
#define pll pair<long long, long long>
#define vll vector<long long>
#define vpi vector<pair<int, int>>
#define pii pair<int, int>
#define vii vector<int>
#define ll long long
#define INF 1e9

vector<int> zfunc(string s)
{
    int n = s.length(), l = 0, r = 0;
    vector<int> z(n);
    rep(i, 1, n)
    {
        if (r > i)
            z[i] = min(r - i, z[i - l]);
        while (i + z[i] < n && s[i + z[i]] == s[z[i]])
            z[i]++;
        if (i + z[i] > r)
        {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

void solve()
{
    string s, t;
    cin >> s >> t;
    int n = s.length(), m = t.length();
    if (m > n)
    {
        cout << s;
        return;
    }
    int zero = 0, one = 0, zt = 0, ot = 0;
    rep(i, 0, n)
    {
        if (s[i] == '0')
            zero++;
        else
            one++;
    }
    rep(i, 0, m)
    {
        if (t[i] == '0')
            zt++;
        else
            ot++;
    }
    if (zero < zt || one < ot)
    {
        cout << s;
        return;
    }
    vector<int> z = zfunc(t);
    int p = 0;
    rep(i, 1, m)
    {
        if (i + z[i] == m)
        {
            p = z[i];
            break;
        }
    }
    rep(i, 0, m)
    {
        if (t[i] == '1')
            one--;
        else
            zero--;
        s[i] = t[i];
    }
    int i = m, j = p;
    while (i < n)
    {
        if (j == m)
            j = p;
        if (t[j] == '1')
        {
            if (!one)
                break;
            one--;
        }
        else
        {
            if (!zero)
                break;
            zero--;
        }
        s[i] = t[j];
        i++;
        j++;
    }
    while (zero)
    {
        zero--;
        s[i] = '0';
        i++;
    }
    while (one)
    {
        one--;
        s[i] = '1';
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