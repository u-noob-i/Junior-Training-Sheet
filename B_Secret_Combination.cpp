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
long long modu = 1000000009;

void solve(int T)
{
    cin >> n >> s;
    vector<int> a(n);
    for (i = 0; i < n; i++)
        a[i] = s[i] - '0';
    int ind = 0, add = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= 9; j++)
        {
            string cur = "";
            for (int k = i; k < i + n; k++)
                cur += to_string((a[k % n] + j) % 10);
            if (cur < s)
            {
                s = cur;
                ind = i;
                add = j;
            }
        }
    }
    for (i = ind; i < ind + n; i++)
        cout << (a[i % n] + add) % 10;
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