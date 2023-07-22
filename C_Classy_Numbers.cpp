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
vector<long long> ans;

void gen(long long temp, int y, int count)
{
    if (count > 3)
        return;
    if (y == 18)
    {
        ans.push_back(temp);
        return;
    }
    gen(temp * 10, y + 1, count);
    for (long long x = 1; x <= 9; x++)
        gen(temp * 10 + x, y + 1, count + 1);
}

void solve(int T)
{
    long long l, r;
    cin >> l >> r;
    int x = 1, y = ans.size() - 1, mid, left = -1, right = -1;
    while (x <= y)
    {
        mid = (x + y) / 2;
        if (ans[mid] <= r)
        {
            right = mid;
            x = mid + 1;
        }
        else
            y = mid - 1;
    }
    x = 1;
    y = ans.size() - 1;
    while (x <= y)
    {
        mid = (x + y) / 2;
        if (ans[mid] >= l)
        {
            left = mid;
            y = mid - 1;
        }
        else
            x = mid + 1;
    }
    if (right < left)
        cout << 0;
    else
        cout << right - left + 1;
}

int main()
{
    gen(0, 0, 0);
    sort(ans.begin(), ans.end());
    ans.push_back(1000000000000000000);
    int t;
    cin >> t;
    for (int p = 1; p <= t; p++)
    {
        solve(p);
        cout << "\n";
    }
}