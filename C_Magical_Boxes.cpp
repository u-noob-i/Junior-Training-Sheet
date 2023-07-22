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

int n, m, i, j;
string s;
long long modu = 100000000;

void solve(int T)
{
    long long x, y;
    cin >> n;
    map<long long, long long> a, b;
    for (i = 0; i < n; i++)
    {
        cin >> x >> y;
        a[x] = b[x] = y;
    }
    for (auto itr = a.begin(); itr != a.end(); itr++)
    {
        x = itr->first;
        y = itr->second;
        if (y == 1)
            continue;
        y -= 4 * a[x + 1];
        y = max(0ll, y);
        long long z = y / 4;
        if (y % 4)
            z++;
        a[x + 1] += z;
    }
    x = a.rbegin()->first;
    if (b.find(x) != b.end())
        x++;
    cout << x;
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