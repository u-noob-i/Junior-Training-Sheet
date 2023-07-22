#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <utility>

using namespace std;

void solve(int T)
{
    long long n, k, x, y;
    cin >> n >> k >> x >> y;

    if (n % 3ll)
    {
        cout << "no";
        return;
    }
    long long a, b, c;
    if (((2 * x) + y + k) % 3 == 0)
    {
        a = ((2 * x) + y + k) / 3;
        c = a - x - y;
        b = c + y;
        if (a >= 0 && b >= 0 && c >= 0 && a + b + c == k && a <= n / 3 && b <= n / 3 && c <= n / 3)
        {
            cout << "yes";
            return;
        }
    }
    if ((k - x - y) % 3 == 0)
    {
        b = (k - x - y) / 3;
        a = b + x;
        c = b + y;
        if (a >= 0 && b >= 0 && c >= 0 && a + b + c == k && a <= n / 3 && b <= n / 3 && c <= n / 3)
        {
            cout << "yes";
            return;
        }
    }
    if ((x + y + k) % 3 == 0)
    {
        b = (x + y + k) / 3;
        a = b - x;
        c = b - y;
        if (a >= 0 && b >= 0 && c >= 0 && a + b + c == k && a <= n / 3 && b <= n / 3 && c <= n / 3)
        {
            cout << "yes";
            return;
        }
    }
    if ((x - y + k) % 3 == 0)
    {
        b = (x - y + k) / 3;
        a = b - x;
        c = b + y;
        if (a >= 0 && b >= 0 && c >= 0 && a + b + c == k && a <= n / 3 && b <= n / 3 && c <= n / 3)
        {
            cout << "yes";
            return;
        }
    }
    cout << "no";
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve(i);
        cout << "\n";
    }
}