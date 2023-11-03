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
#define INF 1e18
#define pii pair<int, int>
#define vii vector<int>

bool check(map<string, vii> &a, string s)
{
    vector<pair<string, vii>> arr(4);
    int i = 0;
    for (auto &it : a)
    {
        arr[i].first = it.first;
        arr[i].second = it.second;
        i++;
    }
    sort(arr.begin(), arr.end(), [&](pair<string, vii> &a, pair<string, vii> &b)
         {
            if(a.second[2] > b.second[2]) return 1;
            if(a.second[2] < b.second[2]) return 0;
            if(a.second[0] - a.second[1] > b.second[0] - b.second[1]) return 1;
            if(a.second[0] - a.second[1] < b.second[0] - b.second[1]) return 0;
            if(a.second[0] > b.second[0]) return 1;
            if(a.second[0] < b.second[0]) return 0;
            if(a.first < b.first) return 1;
            return 0; });
    if (arr[0].first == s || arr[1].first == s)
        return 1;
    return 0;
}

void solve()
{
    string s, p, q, t, n = "BERLAND";
    map<string, vii> a;
    map<string, int> ct;
    rep(i, 0, 5)
    {
        cin >> s >> p >> q;
        ct[s]++;
        ct[p]++;
        int x = q[0] - '0', y = q[2] - '0';
        if (a.find(s) == a.end())
            a[s] = {0, 0, 0};
        if (a.find(p) == a.end())
            a[p] = {0, 0, 0};
        a[s][0] += x;
        a[s][1] += y;
        a[p][0] += y;
        a[p][1] += x;
        if (x > y)
            a[s][2] += 3;
        else if (y > x)
            a[p][2] += 3;
        else
        {
            a[s][2]++;
            a[p][2]++;
        }
    }
    for (auto &it : ct)
        if (it.second == 2 && it.first != "BERLAND")
            t = it.first;
    a[n][2] += 3;
    vector<pii> cand;
    rep(i, 1, 50) rep(j, 0, i)
    {
        a[n][0] += i;
        a[n][1] += j;
        a[t][0] += j;
        a[t][1] += i;
        if (check(a, n))
            cand.push_back({i, j});
        a[n][0] -= i;
        a[n][1] -= j;
        a[t][0] -= j;
        a[t][1] -= i;
    }
    sort(cand.begin(), cand.end(), [&](pii &a, pii &b)
         {
                if(a.first - a.second < b.first - b.second) return 1; 
                if(a.first - a.second > b.first - b.second) return 0; 
                if(a.second < b.second) return 1;
                return 0; });
    if (!cand.size())
        cout << "IMPOSSIBLE";
    else
        cout << cand[0].first << ":" << cand[0].second;
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