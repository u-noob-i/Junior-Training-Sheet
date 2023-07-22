#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <numeric>

using namespace std;

int i, j;

void solve(int T)
{
    double n, m, ans = 0;
    cin >> m >> n;
    for (long long k = 1; k <= m; k++)
    {
        double cur = k;
        cur *= (pow(cur / m, n) - pow((cur - 1) / m, n));
        ans += cur;
    }
    cout << setprecision(9) << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    for (int i = 1; i <= t; i++)
    {
        solve(t);
        cout << "\n";
    }
}