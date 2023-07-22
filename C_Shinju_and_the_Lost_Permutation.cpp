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

#define rep(a, b, c) for (int(a) = (b); (a) < (c); ++(a))

int n, m, i, j, k;
string s;
long long M = 1000000007;

void solve(int T)
{
    cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    int oc = 0, ind = -1;
    for (i = 0; i < n; i++)
        if (a[i] == 1)
        {
            oc++;
            ind = i;
        }
    if (oc != 1)
    {
        cout << "NO";
        return;
    }
    i = ind;
    int prev = 1;
    for (j = i + 1; j % n != i; j++)
    {
        if (a[j % n] > prev + 1)
        {
            cout << "NO";
            return;
        }
        prev = a[j % n];
    }
    cout << "YES";
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