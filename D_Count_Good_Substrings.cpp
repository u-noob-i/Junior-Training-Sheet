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
#include <bitset>
#include <random>
#include <chrono>

using namespace std;

#define ll long long
#define rep(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define irep(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define INF 1e9

ll M = 1000000007;

void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    ll odd = 0, even = 0;
    vector<vector<int>> a;
    a.push_back({0, 0});
    a.push_back({0, 0});
    irep(i, n - 1, 0)
    {
        int k = (s[i] == 'b');
        odd++;
        if (i % 2)
        {
            odd += a[k][1];
            even += a[k][0];
            a[k][1]++;
        }
        else
        {
            odd += a[k][0];
            even += a[k][1];
            a[k][0]++;
        }
        while (i && s[i] == s[i - 1])
        {
            odd++;
            i--;
            if (i % 2)
            {
                odd += a[k][1];
                even += a[k][0];
                a[k][1]++;
            }
            else
            {
                odd += a[k][0];
                even += a[k][1];
                a[k][0]++;
            }
        }
    }
    cout << even << " " << odd;
}

int main()
{
    cin.sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    t = 1;
    for (int T = 1; T <= t; T++)
    {
        solve();
        cout << "\n";
    }
}