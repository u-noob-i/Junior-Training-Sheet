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

using namespace std;

#define ll long long
#define rep(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define irep(a, b, c) for (int(a) = (b); (a) >= (c); --(a))

ll M = 1000000007;

int n, m;
string a[11];
int ct[11];
string x;
bool check[36];
int ans;

void calc()
{
    rep(i, 0, m)
    {
        int count = 0;
        rep(j, 0, n) if (a[i][j] == x[j]) count++;
        if (count != ct[i])
            return;
    }
    ans++;
}

void rec(int pos, int same)
{
    if (!same)
    {
        rep(i, 0, n)
        {
            if (check[i])
                x[i] = a[0][i];
            else if (a[0][i] == '1')
                x[i] = '0';
            else
                x[i] = '1';
        }
        calc();
        return;
    }

    if (pos == n)
        return;

    rec(pos + 1, same);
    check[pos] = 1;
    rec(pos + 1, same - 1);
    check[pos] = 0;

    return;
}

void solve(int T)
{
    ans = 0;

    cin >> n >> m;
    rep(i, 0, m) cin >> a[i] >> ct[i];

    x = string(n, 0);
    rep(i, 0, n) check[i] = 0;

    rec(0, ct[0]);

    cout << ans;
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