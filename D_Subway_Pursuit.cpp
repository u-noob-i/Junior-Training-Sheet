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

ll M = 1000000007;

void solve(int T)
{
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    string s;
    ll n, k;
    cin >> n >> k;
    ll l = 1, r = n, mid;
    while (l <= r)
    {
        if (r - l + 1 <= 60)
        {
            ll x = uniform_int_distribution<long long>(l, r)(rng);
            cout << x << " " << x << "\n";
            cout.flush();
            cin >> s;
            if (s == "Yes")
                return;
            l = max(1ll, l - k);
            r = min(n, r + k);
        }
        else
        {
            l = max(1ll, l - k);
            r = min(n, r + k);
            mid = l + (r - l) / 2;
            cout << l << " " << mid << "\n";
            cout.flush();
            cin >> s;
            if (s == "Yes")
                r = min(n, mid + k);
            else
                l = max(1ll, mid - k);
        }
    }
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