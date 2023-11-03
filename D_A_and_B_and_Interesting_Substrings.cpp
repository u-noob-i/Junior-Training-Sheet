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

using namespace std;

#define ll long long
#define rep(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define irep(a, b, c) for (int(a) = (b); (a) >= (c); --(a))

ll M = 1000000007;

void solve(int T)
{
    ll a[26];
    string s;
    int n;
    rep(i, 0, 26) cin >> a[i];
    cin >> s;
    n = s.length();
    vector<ll> pref(n + 1, 0);
    map<char, vector<ll>> arr;
    rep(i, 0, n)
    {
        pref[i + 1] = a[s[i] - 'a'] + pref[i];
        arr[s[i]].push_back(pref[i + 1]);
    }
    ll ans = 0;
    for (auto itr : arr)
    {
        char ch = itr.first;
        vector<ll> temp = itr.second;
        map<ll, ll> ct;
        rep(j, 0, temp.size())
        {
            ans += ct[temp[j] - a[ch - 'a']];
            ct[temp[j]]++;
        }
    }
    cout << ans;
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