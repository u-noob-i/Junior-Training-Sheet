#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <queue>
#include <climits>
#include <sstream>
#include <tuple>

using namespace std;

int n, m, i, j;
string s;
long long modu = 1000000009;

int calc(int x)
{
    int ret = 0, d = 1;
    while (x)
    {
        if (x % 10 == 7 || x % 10 == 4)
        {
            ret += (x % 10) * d;
            d *= 10;
        }
        x /= 10;
    }
    return ret;
}

void solve(int T)
{
    cin >> n >> m;
    n = max(n + 1, m);
    while (1)
    {
        i = calc(n);
        if (i == m)
        {
            cout << n;
            return;
        }
        n++;
    }
}

int main()
{

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    t = 1;
    for (int q = 1; q <= t; q++)
    {
        solve(t);
    }
}