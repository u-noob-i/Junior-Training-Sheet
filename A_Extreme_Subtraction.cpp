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
#define irep(a, b, c) for (int(a) = (b); (a) >= (c); --(a))

long long gcd(long long a, long long b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int n, m, i, j, k;
string s;
long long M = 998244353;

void solve(int T)
{
    bool x = 0, y = 0;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    rep(i, 0, n) cin >> a[i];
    b[0] = a[0];
    c[0] = 0;
    rep(i, 1, n)
    {
        b[i] = min(b[i - 1], a[i] - c[i - 1]);
        c[i] = a[i] - b[i];
        if (b[i] < 0 || c[i] < 0)
        {
            cout << "NO";
            return;
        }
    }
    cout << "YES";
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