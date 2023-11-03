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

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<string> a(n + 1);
    rep(i, 1, n)
    {
        cin >> a[i];
        a[i] = "#" + a[i];
    }
    string t = "";
    int l = 1;
    vvi q;
    q.pb({1, 1, 0});
    if (!k || a[1][1] == 'a')
        t += a[1][1];
    else
    {
        t += 'a';
        q[0][2]++;
    }
    while (q.size())
    {
        // cout << t << "\n";
        char ch = 'z' + 1;
        map<pi, int> m;
        rep(i, 0, q.size() - 1)
        {
            auto itr = m.find({q[i][0], q[i][1]});
            if (itr == m.end())
                m[ {q[i][0], q[i][1]}] = q[i][2];
            else
                m[ {q[i][0], q[i][1]}] = min(m[ {q[i][0], q[i][1]}], q[i][2]);
        }
        q.clear();
        for (auto &itr : m)
        {
            int i, j, cost;
            i = itr.first.first;
            j = itr.first.second;
            cost = itr.second;
            // cout << "{" << i << " " << j << " " << cost << "} ";
            if (i + 1 <= n)
            {
                char temp = a[i + 1][j];
                if (a[i + 1][j] != 'a' && cost < k)
                    temp = 'a';
                if (temp < ch)
                {
                    q.clear();
                    ch = temp;
                }
                if (temp == ch)
                {
                    q.pb({i + 1, j, cost});
                    if (a[i + 1][j] != 'a' && cost < k)
                        q[q.size() - 1][2]++;
                }
            }
            if (j + 1 <= n)
            {
                char temp = a[i][j + 1];
                if (a[i][j + 1] != 'a' && cost < k)
                    temp = 'a';
                if (temp < ch)
                {
                    q.clear();
                    ch = temp;
                }
                if (temp == ch)
                {
                    q.pb({i, j + 1, cost});
                    if (a[i][j + 1] != 'a' && cost < k)
                        q[q.size() - 1][2]++;
                }
            }
        }
        // cout << "\n";
        if (ch != 'z' + 1)
            t += ch;
    }
    cout << t;
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
