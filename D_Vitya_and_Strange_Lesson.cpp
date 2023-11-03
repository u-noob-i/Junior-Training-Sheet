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
#include <random>
#include <chrono>

using namespace std;

#define ll long long
#define rep(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define irep(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define INF 1e9

ll M = 1000000007;

struct Node
{
    int count;
    Node *l, *r;
    Node()
    {
        count = 0;
        l = r = nullptr;
    }
};

void ins(Node *head, int x)
{
    Node *cur = head;
    irep(i, 22, 0)
    {
        if ((1 << i) & x)
        {
            if (!cur->r)
                cur->r = new Node();
            cur = cur->r;
        }
        else
        {
            if (!cur->l)
                cur->l = new Node();
            cur = cur->l;
        }
        cur->count++;
    }
    return;
}

int findmin(Node *head, int x)
{
    Node *cur = head;
    int ret = 0;
    irep(i, 22, 0)
    {
        if ((1 << i) & x)
        {
            if (cur->r)
            {
                cur = cur->r;
                ret = ret | (1 << i);
            }
            else if (cur->l)
                cur = cur->l;
            else
                return ret;
        }
        else
        {
            if (cur->l)
                cur = cur->l;
            else if (cur->r)
            {
                cur = cur->r;
                ret = ret | (1 << i);
            }
            else
                return ret;
        }
    }
    return ret ^ x;
}

void solve()
{
    int n, q;
    cin >> n >> q;
    set<int> a;
    rep(i, 0, n)
    {
        int x;
        cin >> x;
        a.insert(x);
    }
    int j = 0;
    Node *head = new Node();
    while (j <= 600000)
    {
        if (a.find(j) == a.end())
            ins(head, j);
        j++;
    }
    int x = 0, y;
    while (q--)
    {
        cin >> y;
        x = x ^ y;
        cout << findmin(head, x) << "\n";
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
        solve();
        cout << "\n";
    }
}