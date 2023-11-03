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

struct Node {
    vector<Node*> child;
    bool w, l;
    Node()
    {
        child.assign(26, nullptr);
    }
};
Node *head;

void ins(string s)
{
    Node *cur = head;
    rep(i, 0, s.length() - 1)
    {
        int x = s[i] - 'a';
        if (!cur->child[x])
            cur->child[x] = new Node();
        cur = cur->child[x];
    }
}

void calc(Node *cur)
{
    int leaf = 0;
    cur->w = 0;
    cur->l = 0;
    for (int i = 0; i < 26; i++)
    {
        if (cur->child[i])
        {
            leaf = 1;
            calc(cur->child[i]);
            cur->w |= (!cur->child[i]->w);
            cur->l |= (!cur->child[i]->l);
        }
    }
    if (!leaf)
    {
        cur->w = 0;
        cur->l = 1;
    }
}

void solve()
{
    head = new Node();
    int n, k;
    cin >> n >> k;
    string s;
    rep(i, 1, n)
    {
        cin >> s;
        ins(s);
    }
    calc(head);
    bool x = head->w, y = head->l;
    if (x && (y || k % 2))
        cout << "First";
    else
        cout << "Second";
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
