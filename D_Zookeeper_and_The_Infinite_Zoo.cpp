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

int n, m, i, j, k;
string s;
ll M = 1000000007;

void solve(int T)
{
    int l, r;
    cin >> l >> r;
    if (r < l)
    {
        cout << "NO";
        return;
    }
    int a = 0, x, y;
    for (i = 1; i <= r; i *= 2)
    {
        x = l & i, y = r & i;
        if (x)
            a++;
        if (y)
            a--;
        if (a < 0)
            break;
    }
    if (a >= 0)
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
    cin >> t;
    for (int T = 1; T <= t; T++)
    {
        solve(T);
        cout << "\n";
    }
}