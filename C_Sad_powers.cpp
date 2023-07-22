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
#include <cfloat>

using namespace std;

int n, m, i, j, k;
string s, p;
long long M = 1000000007;

set<long long> pows;
vector<long long> ct;

long long sqt(long long x)
{
    long long ret = sqrtl(x);
    return ret;
}

long long bs(long long x)
{
    int l = 0, r = ct.size(), mid, ret = -1;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (ct[mid] >= x)
        {
            ret = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    return ret;
}

void solve(int T)
{
    long long l, r, ans = 0;
    cin >> l >> r;
    long long x = sqt(l - 1), y = sqt(r);
    ans = bs(r + 1) - bs(l) + y - x;
    cout << ans;
}

int main()
{
    cin.sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long x = 2;
    while (x <= 1000000)
    {
        long long y = x * x;
        while (LLONG_MAX / y >= x)
        {
            y *= x;
            if (sqt(y) * sqt(y) != y)
                pows.insert(y);
        }
        x++;
    }
    i = 1;
    for (auto itr = pows.begin(); itr != pows.end(); itr++)
        ct.push_back(*itr);
    sort(ct.begin(), ct.end());

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve(t);
        cout << "\n";
    }
}