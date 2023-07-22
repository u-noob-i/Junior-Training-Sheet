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
#include <queue>
#include <climits>

using namespace std;

int n, m, i, j, k;
string s, p;
long long M = 998244353;

long long gcd(long long A, long long B)
{
    if (B == 0)
        return A;
    return gcd(B, A % B);
}

void solve(int T)
{
    cin >> n;
    vector<long long> a(n + 1, 0), b(n + 1, 0), c(n + 1, 0);
    for (i = 1; i <= n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    long long x, num = 0, dem;
    for (i = 2, x = 1; i <= n; i++, x++)
    {
        b[i] = a[i] - a[i - 1];
        b[i] = x * b[i] + b[i - 1];
    }
    for (i = n - 1, x = 1; i >= 1; i--, x++)
    {
        c[i] = a[i + 1] - a[i];
        c[i] = x * c[i] + c[i + 1];
    }
    // for (i = 0; i <= n; i++)
    //     cout << b[i] << " " << c[i] << "\n";
    for (i = 0; i <= n; i++)
        num += b[i] + c[i];
    for (i = 1; i <= n; i++)
        num += a[i];
    dem = n;
    x = gcd(num, dem);
    num /= x;
    dem /= x;
    cout << num << " " << dem << "\n";
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