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
#define INF 1e9

ll M = 1000000007;

void solve()
{
    string s;
    int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    int x, ct = 0;
    rep(i, 0, 4)
    {
        cout << primes[i] << "\n";
        cout.flush();
        cin >> s;
        if (s == "yes")
        {
            x = primes[i];
            ct++;
        }
        if (ct > 1)
        {
            cout << "composite\n";
            cout.flush();
            return;
        }
    }
    if (!ct)
    {
        cout << "prime\n";
        cout.flush();
        return;
    }
    rep(i, 0, 25)
    {
        if (primes[i] * x > 100)
            break;
        cout << primes[i] * x << "\n";
        cout.flush();
        cin >> s;
        if (s == "yes")
        {
            cout << "composite\n";
            cout.flush();
            return;
        }
    }
    cout << "prime\n";
    cout.flush();
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