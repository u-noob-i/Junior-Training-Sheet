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

int n, m, i, j, k;
string s;
long long M = 1000000007;

void solve(int T)
{
    cin >> n;
    vector<int> a(n);
    int one = 0;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i])
            one++;
    }
    int l = -1, r = -1;
    for (i = 0; i < n; i++)
    {
        if (a[i] == 1)
        {
            if (l == -1)
                l = i;
            r = i;
        }
    }
    cout << (r - l + 1) - one;
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