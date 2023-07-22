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
#include <iomanip>

using namespace std;

int m, i, j;
string s;
long long modu = 100000000;

void solve(int T)
{
    long long n, k, b, t;
    cin >> k >> b >> n >> t;
    long long r = 1;
    for (i = 0; i <= n + 1; i++)
    {
        if (r > t)
            break;
        if (i == n && t >= r)
        {
            cout << 0;
            return;
        }
        r = (k * r) + b;
    }
    long long x = 1, first = b, second = (2 * t) - b, third = (b * n * n) - (b * n) + (2 * n);
    while (1)
    {
        if ((x * x * first) + (x * second) - third >= 0)
        {
            cout << x;
            return;
        }
        x++;
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