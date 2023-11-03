#include <iostream>
#include <cstring>
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

#define rep(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define irep(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define vpl vector<pair<long long, long long>>
#define pl pair<long long, long long>
#define vl vector<long long>
#define vvl vector<vector<long long>>
#define vpi vector<pair<int, int>>
#define pi pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define ll long long
#define INF 1e9
ll M = 1e9 + 7;

struct Node
{
    int t, r, c;
    vi ind;
    vector<Node *> child;
    Node()
    {
        t = r = c = -1;
    }
};

int n, m;
Node *op[100001];
int ans[100001];

void dfs(Node *cur, vector<bitset<1001>> a, vvi b, int tot)
{
    int t = cur->t, r = cur->r, c = cur->c;
    if (t == 1)
    {
        if (b[r][0] % 2 == 0 && !a[r][c])
        {
            a[r][c] = 1;
            b[r][1]++;
            tot++;
        }
        else if (b[r][0] % 2 && a[r][c])
        {
            a[r][c] = 0;
            b[r][1]++;
            tot++;
        }
    }
    if (t == 2)
    {
        if (b[r][0] % 2 == 0 && a[r][c])
        {
            a[r][c] = 0;
            b[r][1]--;
            tot--;
        }
        else if (b[r][0] % 2 && !a[r][c])
        {
            a[r][c] = 1;
            b[r][1]--;
            tot--;
        }
    }
    if (t == 3)
    {
        b[r][0]++;
        tot += m - 2 * b[r][1];
        b[r][1] = m - b[r][1];
    }
    for (int v : cur->ind)
        ans[v] = tot;
    for (Node *v : cur->child)
        dfs(v, a, b, tot);
    return;
}

void solve()
{
    int q, t, x;
    cin >> n >> m >> q;
    op[0] = new Node();
    op[0]->ind.emplace_back(0);
    rep(i, 1, q)
    {
        cin >> t;
        if (t == 4)
        {
            cin >> x;
            op[i] = op[x];
            op[i]->ind.emplace_back(i);
            continue;
        }
        Node *cur = new Node(), *prv = op[i - 1];
        cur->t = t;
        if (t == 3)
            cin >> cur->r;
        else
            cin >> cur->r >> cur->c;
        prv->child.emplace_back(cur);
        cur->ind.emplace_back(i);
        op[i] = cur;
    }
    vector<bitset<1001>> a(n + 1);
    vvi b(n + 1, {0, 0});
    dfs(op[0], a, b, 0);
    rep(i, 1, q) cout << ans[i] << "\n";
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
