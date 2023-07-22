#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <numeric>
#include <queue>
#include <climits>

using namespace std;

int n, m, i, j, k;
string s, p;
long long M = 998244353;

void solve(int T)
{
    cin >> n;
    vector<int> a(n);
    for (i = 0; i < n; i++)
        cin >> a[i];
    int ans = 0;
    set<pair<int, pair<int, int>>> segs;
    map<pair<int, int>, int> lp;
    set<pair<int, int>> inds;
    for (i = 0; i < n; i++)
    {
        j = i;
        while (j < n - 1 && a[j] == a[j + 1])
            j++;
        segs.insert({-(j - i + 1), {i, j}});
        inds.insert({i, j});
        lp.insert({{i, j}, -(j - i + 1)});
        i = j;
    }
    while (segs.size())
    {
        ans++;
        pair<int, pair<int, int>> x = *segs.begin();
        segs.erase(x);
        int l = x.second.first, r = x.second.second;
        auto itr = inds.lower_bound({l, r}), btr = inds.upper_bound({l, r});
        if (itr == inds.begin() || btr == inds.end())
        {
            inds.erase(*itr);
            lp.erase({l, r});
            continue;
        }
        pair<int, int> y, z;
        y = *itr;
        itr--;
        inds.erase(y);
        y = *itr;
        z = *btr;
        if (a[y.second] == a[z.first])
        {
            auto f1 = lp.find(y), f2 = lp.find(z);
            int len1 = f1->second, len2 = f2->second;
            inds.erase(y);
            inds.erase(z);
            segs.erase({f1->second, y});
            segs.erase({f2->second, z});
            lp.erase(y);
            lp.erase(z);
            segs.insert({len1 + len2, {y.first, z.second}});
            inds.insert({y.first, z.second});
            lp.insert({{y.first, z.second}, len1 + len2});
        }
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    for (int i = 1; i <= t; i++)
    {
        solve(t);
        cout << "\n";
    }
}