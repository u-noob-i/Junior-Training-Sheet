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

ll M = 1000000007;

class DisjSet {
    int *rank, *parent, n;
public:
    DisjSet(int n)
    {
        rank = new int[n];
        parent = new int[n];
        this->n = n;
        makeSet();
    }
    void makeSet()
    {
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    void Union(int x, int y)
    {
        int xset = find(x);
        int yset = find(y);
        if (xset == yset)
            return;
        if (rank[xset] < rank[yset])
            parent[xset] = yset;
        else if (rank[xset] > rank[yset])
            parent[yset] = xset;
        else {
            parent[yset] = xset;
            rank[xset] = rank[xset] + 1;
        }
    }
};

void solve(int T)
{
    int n;
    cin >> n;
    vector<int> a(n);
    unordered_map<int, int> arr;
    rep(i, 0, n)
    {
        cin >> a[i];
        a[i]--;
        arr[a[i]] = i;
    }
    DisjSet dsu(n);
    int ans = INT_MAX, sum = 0;
    rep(i, 0, n)
    {
        int count = 0;
        int j = i;
        while (dsu.find(a[i]) != dsu.find(i))
        {
            dsu.Union(a[i], i);
            i = arr[i];
            count++;
        }
        // cout << count << " ";
        sum += count;
        i = j;
    }
    rep(i, 0, n - 1)
    {
        if (a[i] == i && a[i + 1] == i + 1 || dsu.find(i) != dsu.find(i + 1))
            ans = min(ans, sum + 1);
        else
            ans = min(ans, sum - 1);
    }
    cout << ans;
}

int main()
{
    cin.sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int T = 1; T <= t; T++)
    {
        solve(T);
        cout << "\n";
    }
}