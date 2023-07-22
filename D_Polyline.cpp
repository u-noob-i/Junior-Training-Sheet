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

int n, m, i, j, k, q;
string s, p;
long long M = 1000000007;

void solve(int T)
{
    long long a[3][2];
    for (i = 0; i < 3; i++)
        for (j = 0; j < 2; j++)
            cin >> a[i][j];
    if ((a[0][0] == a[1][0] && a[0][0] == a[2][0]) || (a[0][1] == a[1][1] && a[1][1] == a[2][1]))
        cout << 1;
    else if ((a[0][0] == a[1][0] && (a[2][1] >= max(a[0][1], a[1][1]) || a[2][1] <= min(a[0][1], a[1][1]))) ||
             (a[0][0] == a[2][0] && (a[1][1] >= max(a[0][1], a[2][1]) || a[1][1] <= min(a[0][1], a[2][1]))) ||
             (a[1][0] == a[2][0] && (a[0][1] >= max(a[1][1], a[2][1]) || a[0][1] <= min(a[1][1], a[2][1]))) ||
             (a[0][1] == a[1][1] && (a[2][0] >= max(a[0][0], a[1][0]) || a[2][0] <= min(a[0][0], a[1][0]))) ||
             (a[0][1] == a[2][1] && (a[1][0] >= max(a[0][0], a[2][0]) || a[1][0] <= min(a[0][0], a[2][0]))) ||
             (a[1][1] == a[2][1] && (a[0][0] >= max(a[1][0], a[2][0]) || a[0][0] <= min(a[1][0], a[2][0]))))
        cout << 2;
    else
        cout << 3;
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