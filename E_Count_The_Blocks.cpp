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
long long M = 998244353;

void solve(int T)
{
    long long x;
    cin >> x;
    vector<long long> a(x + 1);
    a[0] = 1;
    for (i = 1; i <= x; i++)
        a[i] = (a[i - 1] * 10) % M;
    for (long long y = 1; y < x; y++)
    {
        long long cur = (2ll * 10 * 9 * a[x - y - 1]) % M;
        cur = (cur + ((x - y - 1) * 10 * 9 * 9 * a[x - y - 2]) % M) % M;
        cout << cur << " ";
    }
    cout << 10;
}

int main()
{
    cin.sync_with_stdio(false);
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