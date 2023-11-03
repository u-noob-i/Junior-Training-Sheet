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

#define ll long long
#define rep(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define irep(a, b, c) for (int(a) = (b); (a) >= (c); --(a))

ll M = 998244353;

void solve(int T)
{
    int n, c;
    cin >> n >> c;
    vector<int> a(n);
    unordered_set<int> arr;
    rep(i, 0, n)
    {
        cin >> a[i];
        arr.insert(a[i]);
    }
    sort(a.begin(), a.end());
    a.resize(distance(a.begin(), unique(a.begin(), a.end())));
    n = a.size();
    rep(i, 0, n)
    {
        int x = a[i];
        rep(j, 1, c + 1)
        {
            if (x * j > a[n - 1])
                break;
            if (arr.find(j) != arr.end())
                continue;
            int l = i, r = n - 1, mid;
            while (l <= r)
            {
                mid = (l + r) / 2;
                if (a[mid] / x == j)
                {
                    cout << "No";
                    return;
                }
                if (a[mid] / x > j)
                    r = mid - 1;
                else
                    l = mid + 1;
            }
        }
    }
    cout << "Yes";
}

int main()
{
    cin.sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int T = 1; T <= t; T++)
    {
        solve(T);
        cout << "\n";
    }
}