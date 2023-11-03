#include <bits/stdc++.h>

using namespace std;

#define ll long long
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
#define vvpi vector<vector<pair<int,int>>>

ll M = 1e9 + 7;

int GCD(int x, int y) { return y == 0 ? x : GCD(y, x % y); }

void solve()
{
    int n;
    cin >> n;
    vi a(n + 1);
    rep(i, 1, n) cin >> a[i];
    priority_queue<int, vi, greater<int>> used, unused;
    ll ans = 0;
    rep(i, 1, n)
    {
        if ((used.size() && used.top() < a[i]) ||
                (unused.size() && unused.top() < a[i]))
        {
            if (used.size() && unused.size())
            {
                if (used.top() < unused.top())
                {
                    int x = used.top();
                    used.pop();
                    unused.push(x);
                    used.push(a[i]);
                    ans += a[i] - x;
                }
                else
                {
                    int x = unused.top();
                    unused.pop();
                    used.push(a[i]);
                    ans += a[i] - x;
                }
            }
            else if (used.size())
            {
                int x = used.top();
                used.pop();
                unused.push(x);
                used.push(a[i]);
                ans += a[i] - x;
            }
            else
            {
                int x = unused.top();
                unused.pop();
                used.push(a[i]);
                ans += a[i] - x;
            }
        }
        else
            unused.push(a[i]);
    }
    cout << ans;
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
    for (int ttt = 1; ttt <= tt; ttt++)
    {
        solve();
        cout << "\n";
    }
}
