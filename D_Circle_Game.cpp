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
    long long d, x;
    cin >> d >> x;
    long long a = 0;
    while (2ll * (a + x) * (a + x) <= d * d)
        a += x;
    if ((a + x) * (a + x) + a * a <= d * d)
        cout << "Ashish";
    else
        cout << "Utkarsh";
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