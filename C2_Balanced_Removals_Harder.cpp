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
#include <tuple>

using namespace std;

int n, m, i, j;
string s;

void rec(vector<tuple<long long, long long, long long, int>> &a, int ind, int x, int y)
{
    if (x == y)
        return;
    if (ind == 1)
    {
        while (x < y)
        {
            cout << get<3>(a[x]) << " " << get<3>(a[x + 1]) << "\n";
            get<0>(a[x]) = get<0>(a[x + 1]) = 1e9;
            x += 2;
        }
        return;
    }
    int p, q;
    for (p = x; p <= y; p++)
    {
        q = p;
        while (q <= y - 1 && get<1>(a[q]) == get<1>(a[q + 1]))
            q++;
        rec(a, 1, p, q);
        p = q;
    }
    vector<int> temp;
    while (x <= y)
    {
        if (get<0>(a[x]) != 1e9)
            temp.push_back(x);
        x++;
    }
    for (p = 0; p < (int)temp.size() - 1; p += 2)
    {
        cout << get<3>(a[temp[p]]) << " " << get<3>(a[temp[p + 1]]) << "\n";
        get<0>(a[temp[p]]) = get<0>(a[temp[p + 1]]) = 1e9;
    }
}

void solve(int T)
{
    cin >> n;
    vector<tuple<long long, long long, long long, int>> a(n);
    for (int i = 0; i < a.size(); i++)
    {
        cin >> get<0>(a[i]) >> get<1>(a[i]) >> get<2>(a[i]);
        get<3>(a[i]) = i + 1;
    }
    sort(a.begin(), a.end());
    for (i = 0; i < n; i++)
    {
        j = i;
        while (j < n - 1 && get<0>(a[j]) == get<0>(a[j + 1]))
            j++;
        rec(a, 0, i, j);
        i = j;
    }
    vector<int> temp;
    i = 0;
    while (i < n)
    {
        if (get<0>(a[i]) != 1e9)
            temp.push_back(i);
        i++;
    }
    for (i = 0; i < (int)temp.size() - 1; i += 2)
        cout << get<3>(a[temp[i]]) << " " << get<3>(a[temp[i + 1]]) << "\n";
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