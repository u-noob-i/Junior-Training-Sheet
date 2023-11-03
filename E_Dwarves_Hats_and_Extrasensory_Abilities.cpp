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
#include <bitset>
#include <random>
#include <chrono>

using namespace std;

#define ll long long
#define rep(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define irep(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define INF 1e18

void solve()
{
    int n, mid, lb = 0, lw = 1e9;
    string s;
    cin >> n;
    n--;
    cout << 1 << " " << 0 << "\n";
    cout.flush();
    cin >> s;
    if (s != "black")
        swap(lb, lw);
    while (n--)
    {
        mid = (lb + lw) >> 1;
        cout << 1 << " " << mid << "\n";
        cout.flush();
        cin >> s;
        if (s == "black")
            lb = mid;
        else
            lw = mid;
    }
    cout << 0 << " " << lb << " " << 2 << " " << lw << "\n";
    return;
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
        solve();
        cout << "\n";
    }
}