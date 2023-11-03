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

ll M = 1000000000000000003;

void solve(int T)
{
    ll p = 3;
    vector<ll> pows(600001, 0);
    pows[0] = 1;
    rep(i, 1, 600001) pows[i] = (pows[i - 1] * p) % M;
    int n, m;
    cin >> n >> m;
    set<ll> hashes;
    string s;
    rep(i, 0, n)
    {
        cin >> s;
        ll cur = 0;
        rep(j, 0, s.length()) cur = (cur + (s[j] - 'a' + 1) * pows[j]) % M;
        hashes.insert(cur);
    }
    rep(i, 0, m)
    {
        cin >> s;
        int k = s.length();
        vector<ll> pref(k + 1, 0);
        rep(j, 0, k) pref[j + 1] = (pref[j] + (s[j] - 'a' + 1) * pows[j]) % M;
        bool ans = 0;
        rep(j, 0, k)
        {
            rep(p, 0, 3)
            {
                if (p == s[j] - 'a')
                    continue;
                ll cur = (pref[j] + pref[k] - pref[j + 1] + (p + 1) * pows[j]) % M;
                cur = (cur + M) % M;
                if(hashes.find(cur)!=hashes.end())
                    ans = 1;
                if(ans)
                    break;
            }
            if(ans)
                break;
        }
        if(ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
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