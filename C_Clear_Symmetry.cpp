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

using namespace std;

int n, m, i, j;
string s;

void solve(int T)
{
    cin >> m;
    if (m == 1)
    {
        cout << 1;
        return;
    }
    if (m == 3)
    {
        cout << 5;
        return;
    }
    i = 3;
    while (1)
    {
        j = i / 2;
        n = j * j;
        j++;
        n += j * j;
        if (m <= n)
        {
            cout << i;
            return;
        }
        i += 2;
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