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

using namespace std;

#define ll long long
#define rep(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define irep(a, b, c) for (int(a) = (b); (a) >= (c); --(a))

ll M = 1000000007;

struct Node
{
    int count;
    Node *a[2];
    Node()
    {
        count = 0;
        a[0] = a[1] = nullptr;
    }
};

Node *root;

void ins(int x)
{
    Node *cur = root;
    irep(i, 30, 0)
    {
        int j = 0;
        if (((1 << i) & x))
            j = 1;
        if (!(cur->a[j]))
            cur->a[j] = new Node();
        cur = cur->a[j];
        cur->count++;
    }
    return;
}

void del(int x)
{
    Node *cur = root;
    irep(i, 30, 0)
    {
        int j = 0;
        if (((1 << i) & x))
            j = 1;
        cur = cur->a[j];
        cur->count--;
    }
}

int calc(int x)
{
    Node *cur = root;
    int val = 0;
    irep(i, 30, 0)
    {
        if (!(cur->a[0]))
        {
            val = val | (1 << i);
            cur = cur->a[1];
            continue;
        }
        if (!(cur->a[1]))
        {
            cur = cur->a[0];
            continue;
        }
        if (cur->a[0]->count == 0 && cur->a[1]->count == 0)
            break;
        int j = 1;
        if (((1 << i) & x))
            j = 0;
        if (cur->a[j]->count == 0)
            j = (j + 1) % 2;
        cur = cur->a[j];
        if (j)
            val = val | (1 << i);
    }
    return (x ^ val);
}

void solve(int T)
{
    int n;
    cin >> n;
    char ch;
    int x;
    root = new Node();
    ins(0);
    while (n--)
    {
        cin >> ch >> x;
        if (ch == '+')
            ins(x);
        else if (ch == '-')
            del(x);
        else
            cout << calc(x) << "\n";
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