#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define INF 1e9
#define pb push_back()
#define pr pop_back()
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

void solve()
{
    string s;
    int n, k;
    cin >> n >> k >> s;
    int i = 0;
    while (k--)
    {
        while (i < n - 1 && (s[i] != '4' || s[i + 1] != '7'))
            i++;
        if (i == n - 1)
            break;
        if (i % 2)
        {
            s[i] = s[i + 1];
            if (i > 0 && s[i - 1] == '4')
            {
                if (k % 2)
                    s[i] = '4';
                break;
            }
        }
        else
            s[i + 1] = s[i];
    }
    cout << s;
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
