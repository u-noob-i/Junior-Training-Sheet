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

using namespace std;

int n, m, i, j, k, q;
string s, p;
long long M = 1000000007;

void solve(int T)
{
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> a(k);
    int x = 1, y = 1, add = 1;
    for (i = 0; i < k - 1; i++)
    {
        vector<pair<int, int>> temp(2);
        temp[0] = {x, y};
        y += add;
        if (y > m)
        {
            add = -1;
            y += add;
            x++;
        }
        else if (y < 1)
        {
            add = 1;
            y += add;
            x++;
        }
        temp[1] = {x, y};
        y += add;
        if (y > m)
        {
            add = -1;
            y += add;
            x++;
        }
        else if (y < 1)
        {
            add = 1;
            y += add;
            x++;
        }
        a[i] = temp;
    }
    vector<pair<int, int>> temp;
    while (x <= n)
    {
        temp.push_back({x, y});
        y += add;
        if (y > m)
        {
            add = -1;
            y += add;
            x++;
        }
        else if (y < 1)
        {
            add = 1;
            y += add;
            x++;
        }
    }
    a[k - 1] = temp;
    for (i = 0; i < k; i++)
    {
        cout << a[i].size() << " ";
        for (j = 0; j < a[i].size(); j++)
            cout << a[i][j].first << " " << a[i][j].second << " ";
        cout << "\n";
    }
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