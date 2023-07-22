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

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int n, m, i, j, k;
string s;
ll M = 1000000007;

vector<int> zfunc(string p)
{
    int N = p.length();
    vector<int> z(N, 0);
    int l = 0, r = 0;
    for (i = 1; i < N; i++)
    {
        if (i < r)
            z[i] = min(r - i, z[i - l]);
        while (i + z[i] < N && p[i + z[i]] == p[z[i]])
            z[i]++;
        if (i + z[i] > r)
        {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

void solve(int T)
{
    cin >> s;
    n = s.length();
    vector<int> z = zfunc(s);
    vector<int> val(n + 1, 0), isvalid(n + 1, 0), ans;
    for (i = 1; i < n; i++)
    {
        // cout << z[i] << " ";
        val[1]++;
        val[z[i] + 1]--;

        if (i + z[i] == n)
            isvalid[z[i]] = 1;
    }
    isvalid[n] = 1;
    val[1]++;
    for (i = 1; i <= n; i++)
        val[i] += val[i - 1];
    for (i = 1; i <= n; i++)
        if (isvalid[i])
            ans.push_back(i);
    cout << ans.size() << "\n";
    for (i = 0; i < ans.size(); i++)
        cout << ans[i] << " " << val[ans[i]] << "\n";
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
        solve(T);
        cout << "\n";
    }
}