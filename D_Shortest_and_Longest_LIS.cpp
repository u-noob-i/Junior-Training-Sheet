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
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define ll long long
#define rep(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define irep(a, b, c) for (int(a) = (b); (a) >= (c); --(a))

ll M = 1000000007;

void solve(int T)
{
    int n;
    string s;
    cin >> n >> s;
    s += '<';
    vector<int> mm(n, -1), ma(n, -1);
    int x;

    // minumum
    x = n;
    rep(i, 0, n) if (s[i] == '>') mm[i] = x--;
    rep(i, 0, n)
    {
        if (s[i] == '>')
            continue;
        int j = i;
        while (j < n - 1 && s[j + 1] == s[j])
            j++;
        int y = x - (j - i);
        x = y - 1;
        rep(k, i, j + 1) mm[k] = y++;
        i = j;
    }

    // maximum;
    x = 1;
    s = ">" + s;
    rep(i, 0, n)
    {
        if(s[i]=='<')
            continue;
        int j = i;
        while (j < n - 1 && s[j + 1] == s[j])
            j++;
        int y = x + (j - i);
        x = y + 1;
        rep(k, i, j + 1) ma[k] = y--;
        i = j;
    }
    rep(i, 0, n) if (s[i] == '<') ma[i] = x++;

    rep(i, 0, n) cout << mm[i] << " ";
    cout << "\n";
    rep(i, 0, n) cout << ma[i] << " ";
}

int main()
{
    cin.sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int T = 1; T <= t; T++)
    {
        solve(T);
        cout << "\n";
    }
}