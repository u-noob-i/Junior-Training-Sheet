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

using namespace std;

int n, m, i, j, k;
string s;
long long M = 1000000007;

void in(vector<long long> &a, int &z)
{
    for (int x = 0; x < z; x++)
        cin >> a[x];
}

void solve(int T)
{
    cin >> n >> k;
    vector<string> a;
    for (i = 0; i < k; i++)
    {
        string x = "";
        x += (char)('a' + i);
        a.push_back(x);
        for (j = i + 1; j < min(26, k); j++)
            a.push_back(x + (char)('a' + j));
    }
    i = 0;
    m = a.size();
    // for (i = 0; i < m; i++)
    //     cout << a[i] << "\n";
    string ans = "";
    while (n)
    {
        string x = a[i % m];
        i++;
        if (x.length() <= n)
        {
            n -= x.length();
            ans += x;
        }
        else
        {
            ans += x[0];
            n--;
        }
    }
    cout << ans;
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