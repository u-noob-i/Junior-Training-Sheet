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

int m, j;
string s;

void solve(int T)
{
    long long n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    long long ans = 0;
    for (long long i = 1; i <= n; i++)
        if (b + i - c >= 1 && b + i - c <= n && a + i - d >= 1 && a + i - d <= n && a + b + i - c - d >= 1 && a + b + i - c - d <= n)
            ans += n;
    cout << ans;
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