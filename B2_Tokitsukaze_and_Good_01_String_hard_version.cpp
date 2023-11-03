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

ll M = 1000000000000000003;

void solve(int T)
{
    int n;
    string s;
    cin >> n >> s;
    int count = 0, ans = 0, L = -1;
    for (int i = 0; i < n; i += 2)
    {
        if (s[i] != s[i + 1])
            ans++;
        else 
        {
            if (s[i] != L)
                count++;
            L = s[i];
        }
    }
    cout << ans << " " << max(count, 1);
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