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

int n;
ll p = 51;
ll ppow[200001], hs1[200001], hs2[200001];
;
string s1, s2;

bool merge(int l1, int r1, int l2, int r2)
{
    ll a = (hs1[r1 + 1] - hs1[l1] + M) % M, b = (hs2[r2 + 1] - hs2[l2] + M) % M;
    if (l1 > l2 && (ppow[l1 - l2] * b) % M == a)
        return 1;
    else if ((ppow[l2 - l1] * a) % M == b)
        return 1;
    if ((r1 - l1 + 1) % 2)
        return 0;
    int m1 = l1 + (r1 - l1) / 2, m2 = l2 + (r2 - l2) / 2;
    return ((merge(l1, m1, m2 + 1, r2) && merge(m1 + 1, r1, l2, m2)) || (merge(l1, m1, l2, m2) && merge(m1 + 1, r1, m2 + 1, r2)));
}

void solve()
{
    cin >> s1 >> s2;
    n = s1.length();
    ppow[0] = 1;
    rep(i, 1, n + 1) ppow[i] = (ppow[i - 1] * p) % M;
    hs1[0] = hs2[0] = 0;
    rep(i, 0, n)
    {
        hs1[i + 1] = (hs1[i] + (s1[i] - 'a' + 1) * ppow[i]) % M;
        hs2[i + 1] = (hs2[i] + (s2[i] - 'a' + 1) * ppow[i]) % M;
    }
    if (merge(0, n - 1, 0, n - 1))
        cout << "YES";
    else
        cout << "NO";
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