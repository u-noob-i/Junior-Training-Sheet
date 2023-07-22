#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <queue>
#include <climits>
#include <sstream>
#include <tuple>
#include <iomanip>

using namespace std;

int n, m, i, j;
string s;
long long modu = 100000000;

void solve(int T)
{
    long long ans = 0;
    cin >> n;
    vector<long long> a(n + 1, 0);
    for (i = 1; i <= n; i++)
        cin >> a[i];
    map<long long, vector<int>> arr;
    for (i = 1; i <= n; i++)
    {
        a[i] += a[i - 1];
        arr[a[i]].push_back(i);
    }
    for (i = 1; i <= n; i++)
    {
        if (a[n] != 3 * a[i])
            continue;
        auto itr = arr.find(2 * a[i]);
        if (itr == arr.end())
            continue;
        int l = 0, r = (itr->second).size() - 1, mid, fin = -1;
        while (l <= r)
        {
            mid = (l + r) / 2;
            if ((itr->second)[mid] > i)
            {
                r = mid - 1;
                fin = mid;
            }
            else
                l = mid + 1;
        }
        if (fin != -1)
        {
            ans += (itr->second).size() - fin;
            if ((itr->second)[(itr->second).size() - 1] == n)
                ans--;
        }
        // cout << i << " " << fin << "\n";
    }
    cout << ans;
}

int main()
{

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    t = 1;
    for (int q = 1; q <= t; q++)
    {
        solve(t);
    }
}