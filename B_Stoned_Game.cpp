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

void in(vector<int> &a, int &z)
{
    for (int x = 0; x < z; x++)
        cin >> a[x];
}

void solve(int T)
{
    cin >> n;
    vector<int> a(n);
    in(a, n);
    int sum = 0, val = -1;
    for (i = 0; i < n; i++)
    {
        sum += a[i];
        val = max(val, a[i]);
    }
    if (val > sum / 2 || sum % 2)
        cout << "T";
    else
        cout << "HL";
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