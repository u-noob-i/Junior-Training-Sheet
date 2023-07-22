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
#include <cfloat>
#include <sstream>

using namespace std;

int n, m, i, j, k;
string s, p;
long long M = 1000000007;

void sim()
{
    vector<int> ans;
    set<pair<int, int>> work, rest;
    i = 1;
    while (i <= n + m)
    {
        while (rest.size() && (*rest.begin()).first + m == i)
        {
            pair<int, int> x = *rest.begin();
            rest.erase(x);
            work.insert({i, x.second});
        }
        while (work.size() && (*work.begin()).first + n == i)
        {
            pair<int, int> x = *work.begin();
            work.erase(x);
            rest.insert({i, x.second});
        }
        int f = 0;
        for (auto itr = work.begin(); itr != work.end(); itr++)
            if ((*itr).first + n == i + 1)
                f++;
        if (f == work.size())
        {
            ans.push_back(i);
            work.insert({i, ans.size()});
        }
        while (work.size() < k)
        {
            ans.push_back(i);
            work.insert({i, ans.size()});
        }
        i++;
    }
    cout << ans.size() << "\n";
    for (i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    return;
}

void solve(int T)
{
    cin >> n >> m >> k;
    sim();
    return;
}

int main()
{
    cin.sync_with_stdio(false);
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