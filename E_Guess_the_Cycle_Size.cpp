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
    ll x = 2, val = 1, a, b;
    rep(i, 0, 25)
    {
        cout << "? " << 1 << " " << x << "\n"
             << flush;
        cin >> a;
        cout << "? " << x << " " << 1 << "\n"
             << flush;
        cin >> b;
        if (a == -1)
            break;
        if (a == b)
            val++;
        else
        {
            val = a + b;
            break;
        }
        x++;
    }
    cout << "! " << val << "\n"
         << flush;
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