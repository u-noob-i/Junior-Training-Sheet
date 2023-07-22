#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <climits>
#include <set>

using namespace std;

int n, m, i, j;
string s;

void solve(int T)
{
    cin >> n;
    long long ans = 0;
    vector<int> a(n);
    for (i = 0; i < n; i++)
        cin >> a[i];
    for (i = 0; i < n; i++)
    {
        long long l = 1;
        while (i < n - 1 && a[i + 1] == a[i])
        {
            i++;
            l++;
        }
        ans += l * (l + 1) / 2;
    }
    cout << ans;
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