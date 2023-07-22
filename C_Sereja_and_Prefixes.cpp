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
#include <iomanip>

using namespace std;

int n, m, i, j;
string s;
long long modu = 100000000;

void solve(int T)
{
    cin >> n;
    vector<long long> a;
    vector<pair<int, pair<int, int>>> op(n);
    for (i = 0; i < n; i++)
    {
        cin >> op[i].first >> op[i].second.first;
        if (op[i].first == 2)
            cin >> op[i].second.second;
    }
    map<long long, int> sing;
    long long curl = 0;
    for (i = 0; i < n; i++)
    {
        if (op[i].first == 1 && a.size() < 100000)
        {
            a.push_back(op[i].second.first);
            op[i].first = 0;
            curl++;
        }
        else if (a.size() < 100000)
        {
            curl += (long long)op[i].second.first * (long long)op[i].second.second;
            while (op[i].second.second && a.size() < 100000)
            {
                op[i].second.second--;
                for (j = 0; j < op[i].second.first; j++)
                    a.push_back(a[j]);
            }
            if (!op[i].second.second)
                op[i].first = 0;
        }
        else if (op[i].first == 1)
            sing[++curl] = op[i].second.first;
        else
            curl += (long long)op[i].second.first * (long long)op[i].second.second;
    }
    cin >> m;
    long long k = 0;
    j = 0;
    for (i = 0; i < m; i++)
    {
        long long x;
        cin >> x;
        if (sing[x])
            cout << sing[x] << " ";
        else if (x <= a.size())
            cout << a[x] << " ";
        else
        {
            while (j < n &&)
        }
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