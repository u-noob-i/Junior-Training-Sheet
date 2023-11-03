#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define INF 1e9
#define pb push_back
#define pr pop_back
#define rep(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define irep(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define pi pair<int, int>
#define pl pair<ll, ll>
#define vi vector<int>
#define vb vector<bool>
#define vl vector<ll>
#define vpi vector<pair<int, int>>
#define vpl vector<pair<ll, ll>>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define vvvi vector<vector<vector<int>>>
ll M = 1e9 + 7;

int p[19]  = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};

void solve()
{
    int pows[100005];
    pows[0] = 1;
    rep(i, 1, 100004) pows[i] = (pows[i - 1] * 2) % M;
    int n;
    cin >> n;
    vi a(71, 0);
    rep(i, 0, n - 1)
    {
        int x;
        cin >> x;
        a[x]++;
    }
    vector<int> dp1(1 << 19, 0);
    dp1[0] = 1;
    rep(i, 1, 70)
    {
        if (!a[i])
            continue;
        vector<int> dp2(1 << 19, 0);
        int mask = 0;
        int x = i;
        rep(j, 0, 18)
        {
            while (x % p[j] == 0)
            {
                mask ^= (1 << j);
                x /= p[j];
            }
        }
        rep(j, 0, (1 << 19) - 1)
        {
            dp2[j] = (1ll * dp2[j] + (1ll * dp1[j] * pows[a[i] - 1]) % M) % M;
            dp2[j] = (1ll * dp2[j] + (1ll * dp1[j ^ mask] * pows[a[i] - 1]) % M) % M;
        }
        swap(dp2, dp1);
    }
    cout << (dp1[0] - 1 + M) % M;
}

int main()
{
    cin.sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int tt;
    tt = 1;
    for (int TT = 1; TT <= tt; TT++)
    {
        solve();
        cout << "\n";
    }
}
