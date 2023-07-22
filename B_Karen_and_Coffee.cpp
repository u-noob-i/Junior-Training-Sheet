#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <queue>
#include <climits>
#include <sstream>

using namespace std;

int n, m, i, j;
string s;

void solve(int T)
{
    int k;
    cin >> n >> k >> m;
    vector<long long> a(200002, 0);
    for (i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        a[x]++;
        a[y + 1]--;
    }
    for (i = 1; i < a.size(); i++)
        a[i] += a[i - 1];
    for (i = 0; i < a.size(); i++)
        if (a[i] >= k)
            a[i] = 1;
        else
            a[i] = 0;
    for (i = 1; i < a.size(); i++)
        a[i] += a[i - 1];
    for (i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        cout << a[y] - a[x - 1] << "\n";
    }
}

int main()
{

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    t = 1;
    for (int q = 1; q <= t; q++)
    {
        solve(t);
    }
}