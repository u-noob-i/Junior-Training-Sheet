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

int spf[100001];

void sieve()
{
    rep(i, 1, 100001) spf[i] = i;
    for (i = 2; i < 100001; i += 2)
        spf[i] = 2;
    for (i = 3; i < 100001; i += 2)
        if (spf[i] == i)
            for (j = i + i; j < 100001; j += i)
                if (spf[j] == j)
                    spf[j] = i;
    return;
}

map<ll, ll> factr(ll x)
{
    map<ll, ll> ret;
    while (x > 1)
    {
        ret[spf[x]]++;
        x /= spf[x];
    }
    return ret;
}

ll pow(ll x, ll y)
{
    ll ret = 1;
    while (y--)
        ret *= x;
    return ret;
}

struct Node
{
    int val;
    Node *next;
    Node(int x)
    {
        val = x;
        next = nullptr;
    }
};

void solve(int T)
{
    vector<vector<Node *>> a(500001, {nullptr, nullptr});
    cin >> n;
    int i = 0;
    while (n--)
    {
        int x, y;
        cin >> x;
        if (x == 1)
        {
            cin >> y;
            Node *temp = new Node(i++);
            if (!a[y][0])
                a[y] = {temp, temp};
            else
            {
                temp->next = a[y][0];
                a[y][0] = temp;
            }
        }
        else
        {
            cin >> x >> y;
            if (!a[x][0] || x == y)
                continue;
            if (!a[y][0])
            {
                a[y] = a[x];
                a[x][0] = a[x][1] = nullptr;
                continue;
            }
            a[x][1]->next = a[y][0];
            a[y][0] = a[x][0];
            a[x][0] = a[x][1] = nullptr;
        }
    }
    n = i;
    vector<int> ans(n);
    rep(i, 1, 500001) while (a[i][0])
    {
        ans[a[i][0]->val] = i;
        a[i][0] = a[i][0]->next;
    }
    rep(i, 0, n) cout << ans[i] << " ";
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
        // cout << "\n";
    }
}