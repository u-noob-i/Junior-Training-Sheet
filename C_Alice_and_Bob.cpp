#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <set>

using namespace std;

int n, m, i, j;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

void solve(int T)
{
    cin >> n;
    vector<int> a(n);
    for (i = 0; i < n; i++)
        cin >> a[i];
    int g = a[0];
    for (i = 1; i < n; i++)
        g = gcd(g, a[i]);
    int x = a[0];
    for (i = 1; i < n; i++)
        x = max(x, a[i]);
    x /= g;
    x -= n;
    if (x % 2)
        cout << "Alice";
    else
        cout << "Bob";
}

int main()
{
    int t;
    t = 1;
    for (int p = 1; p <= t; p++)
    {
        solve(p);
        cout << "\n";
    }
}