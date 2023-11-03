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

#define rep(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define irep(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define vpl vector<pair<long long, long long>>
#define pl pair<long long, long long>
#define vl vector<long long>
#define vpi vector<pair<int, int>>
#define pi pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define ll long long
#define INF 1e9
ll M = 1e9 + 7;

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
    irep(i, 31, 0)
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
}

void rem(Node *head, int x)
{
    Node *cur = head;
    irep(i, 31, 0)
    {
        if ((1 << i) & x)
            cur = cur->r;
        else
            cur = cur->l;
        cur->count--;
    }
}

void solve()
{
    Node *head = new Node();
    int n, k;
    cin >> n >> k;
    vi a(n + 1);
    int x = 0;
    rep(i, 1, n)
    {
        cin >> a[i];
        x ^= a[i];
        ins(head, x);
    }
    x = 0;
    ll ans = 0;
    rep(i, 1, n)
    {
        Node *cur = head;
        int ct = 0;
        irep(j, 31, 0)
        {
            bool f = 0;
            if ((1 << j) & x)
                f = 1;
            if ((1 << j) & k)
            {
                if (!f)
                {
                    if (cur->l)
                        ct += cur->l->count;
                    if (cur->r)
                        cur = cur->r;
                    else
                        break;
                }
                else
                {
                    if (cur->r)
                        ct += cur->r->count;
                    if (cur->l)
                        cur = cur->l;
                    else
                        break;
                }
            }
            else
            {
                if (!f && cur->l)
                    cur = cur->l;
                else if (f && cur->r)
                    cur = cur->r;
                else
                    break;
            }
        }
        ans += n - i + 1 - ct;
        x ^= a[i];
        rem(head, x);
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
        solve();
        cout << "\n";
    }
}