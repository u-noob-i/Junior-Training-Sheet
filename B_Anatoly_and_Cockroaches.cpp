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

using namespace std;

int n, m, i, j;
string s;
long long modu = 1000000007;

void solve(int T)
{
    cin >> n >> s;
    string p = s;
    int x = 0, y = 0, a = 0, b = 0;
    for (i = 0; i < n; i++)
    {
        if (i % 2 && s[i] != 'r')
            a++;
        else if (i % 2 == 0 && s[i] != 'b')
            b++;
        if (i % 2 && s[i] != 'b')
            x++;
        else if (i % 2 == 0 && s[i] != 'r')
            y++;
    }
    cout << min(max(a, b), max(x, y));
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