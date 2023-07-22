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
long long modu = 1000000007;

void solve(int T)
{
    double x1, x2, y1, y2, r1, R1, r2, R2;
    cin >> x1 >> y1 >> r1 >> R1 >> x2 >> y2 >> r2 >> R2;
    double c = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    int ans = 0;
    if (c <= r1 - R2 || c <= r2 - r1 || c >= r1 + R2)
        ans++;
    if (c <= R1 - R2 || c <= r2 - R1 || c >= R1 + R2)
        ans++;
    if (c <= r2 - R1 || c <= r1 - r2 || c >= r2 + R1)
        ans++;
    if (c <= R2 - R1 || c <= r1 - R2 || c >= R2 + R1)
        ans++;
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