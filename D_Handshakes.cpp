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
    map<int, set<int>> a;
    for (i = 0; i < n; i++)
    {
        cin >> j;
        a[j].insert(i + 1);
    }
    i = 0;
    vector<int> ans;
    while (a.size())
    {
        if (a.find(i) != a.end())
        {
            int x = *a[i].begin();
            ans.push_back(x);
            a[i].erase(x);
            if (!a[i].size())
                a.erase(i);
            i++;
        }
        else
        {
            bool dun = 0;
            for (j = i - 3; j >= 0; j -= 3)
            {
                if (a.find(j) != a.end())
                {
                    i = j;
                    dun = 1;
                    break;
                }
            }
            if (!dun)
                break;
        }
    }
    if (ans.size() == n)
    {
        cout << "Possible\n";
        for (i = 0; i < n; i++)
            cout << ans[i] << " ";
    }
    else
        cout << "Impossible";
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