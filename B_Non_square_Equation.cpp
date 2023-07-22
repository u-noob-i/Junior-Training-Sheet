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

long long sod(long long x)
{
    long long ret = 0;
    while (x)
    {
        ret += x % 10;
        x /= 10;
    }
    return ret;
}

void solve(int T)
{
    long long n;
    cin >> n;
    long long x = (81 * 81 / 4) + n;
    x = sqrt(x) - (81 / 2);
    x = max(x, 1ll);
    while (x <= sqrt(n))
    {
        long long z = sod(x);
        if ((x * x) + (sod(x) * x) == n)
        {
            cout << x;
            return;
        }
        x++;
    }
    cout << -1;
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