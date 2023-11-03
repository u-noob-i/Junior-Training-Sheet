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
    cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    sort(a.begin(), a.end());
    vector<bool> visited(n + 2, 0);
    int ma = 0, mm = 0;
    rep(i, 0, n)
    {
        if (!visited[a[i] - 1])
        {
            visited[a[i] - 1] = 1;
            ma++;
        }
        else if(!visited[a[i]])
        {
            visited[a[i]] = 1;
            ma++;
        }
        else if (!visited[a[i] + 1])
        {
            visited[a[i] + 1] = 1;
            ma++;
        }
    }
    rep(i, 0, n + 2) visited[i] = 0;
    rep(i, 0, n)
    {
        int j = i;
        while (j < n - 1 && a[j + 1] - a[i] <= 2)
            j++;
        mm++;
        i = j;
    }
    cout << mm << " " << ma;
}

int main()
{
    cin.sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    t = 1;
    for (int T = 1; T <= t; T++)
    {
        solve(T);
        cout << "\n";
    }
}