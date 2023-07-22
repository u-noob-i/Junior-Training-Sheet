#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <iomanip>
#include <numeric>
#include <queue>
#include <climits>
#include <cfloat>
#include <sstream>
#include <stack>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define rep(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define irep(a, b, c) for (int(a) = (b); (a) >= (c); --(a))

long long gcd(long long a, long long b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int n, m, i, j, k;
string s;
long long M = 998244353;

void solve(int T)
{
    cin >> n;
    vector<pair<int, int>> a(n);
    rep(i, 0, n)
    {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a.begin(), a.end());
    vector<pair<int, int>> arr(5000001, {-1, -1});
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            int sum = a[i].first + a[j].first;
            if (arr[sum].first != -1 && arr[sum].first != a[i].second && arr[sum].second != a[j].second)
            {
                cout << "YES\n"
                     << a[i].second << " " << a[j].second << " " << arr[sum].first << " " << arr[sum].second;
                return;
            }
            arr[sum] = {a[i].second, a[j].second};
        }
    }
    cout << "NO";
}

int main()
{
    cin.sync_with_stdio(false);
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