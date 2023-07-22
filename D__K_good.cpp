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

ll M = 1000000007;

void solve(int T)
{
    ll x;
    cin >> x;
    if (x % 2)
    {
        cout << 2;
        return;
    }
    ll y = 2;
    while (x % y == 0)
        y *= 2;
    if (y == x * 2)
        cout << -1;
    else if (x * 2 / y < y + 1)
        cout << x * 2 / y;
    else
        cout << y;
}

int main()
{
    cin.sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int T = 1; T <= t; T++)
    {
        solve(T);
        cout << "\n";
    }
}