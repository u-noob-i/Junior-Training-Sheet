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

using namespace std;

int n, m, i, j, k;
string s;
long long M = 1000000007;

void solve(int T)
{
    long long x;
    cin >> n >> x;
    vector<long long> a(n), b(n);
    for (i = 0; i < n; i++)
        cin >> a[i];
    for (i = 0; i < n; i++)
        cin >> b[i];
    vector<long long> one, two;
    for (i = 0; i < n; i++)
        if (b[i] == 1)
            one.push_back(a[i]);
        else
            two.push_back(a[i]);
    sort(one.begin(), one.end(), greater<long long>());
    sort(two.begin(), two.end(), greater<long long>());
    one.insert(one.begin(), 0);
    two.insert(two.begin(), 0);
    for (i = 1; i < one.size(); i++)
        one[i] += one[i - 1];
    for (i = 1; i < two.size(); i++)
        two[i] += two[i - 1];
    // for (i = 0; i < one.size(); i++)
    //     cout << one[i] << " ";
    // cout << "\n";
    // for (i = 0; i < two.size(); i++)
    //     cout << two[i] << " ";
    // cout << "\n";
    long long ans = LLONG_MAX;
    for (i = 0; i < one.size(); i++)
    {
        int l = 0, r = two.size() - 1, mid;
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (one[i] + two[mid] >= x)
            {
                // cout << one[i] << " " << two[mid] << "\n";
                ans = min(ans, i + 2ll * mid);
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
    }
    if (ans == LLONG_MAX)
        ans = -1;
    cout << ans << "\n";
}

int main()
{
    cin.sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve(t);
    }
}