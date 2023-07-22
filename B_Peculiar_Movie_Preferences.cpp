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

bool ispal(string p)
{
    for (int x = 0, y = p.length() - 1; x < y; x++, y--)
        if (p[x] != p[y])
            return 0;
    return 1;
}

void solve(int T)
{
    cin >> n;
    vector<string> a(n);
    for (i = 0; i < n; i++)
        cin >> a[i];
    set<string> arr;
    for (i = 0; i < n; i++)
    {
        s = a[i];
        if (ispal(s) || arr.find(s) != arr.end())
        {
            cout << "YES";
            return;
        }
        reverse(s.begin(), s.end());
        arr.insert(s);
        if (s.length() == 3)
        {
            arr.insert(s.substr(1, 2));
            if (s[0] == s[1])
                arr.insert("" + s[2]);
        }
        if (s.length() == 2)
            arr.insert("" + s[1]);
    }
    arr.clear();
    for (i = n - 1; i >= 0; i--)
    {
        s = a[i];
        if (ispal(s) || arr.find(s) != arr.end())
        {
            cout << "YES";
            return;
        }
        reverse(s.begin(), s.end());
        arr.insert(s);
        if (s.length() == 3)
        {
            arr.insert(s.substr(0, 2));
            if (s[1] == s[2])
                arr.insert("" + s[0]);
        }
        if (s.length() == 2)
            arr.insert("" + s[0]);
    }
    cout << "NO";
}

int main()
{
    cin.sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve(t);
        cout << "\n";
    }
}