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

#define MAXN 15000001
int spf[MAXN];

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

void sieve()
{
    spf[1] = 1;
    for (int i = 2; i < MAXN; i++)
        spf[i] = i;
    for (int i = 4; i < MAXN; i += 2)
        spf[i] = 2;
    for (int i = 3; i * i < MAXN; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j < MAXN; j += i)
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}

set<int> getFactorization(int x)
{
    set<int> ret;
    while (x != 1)
    {
        ret.insert(spf[x]);
        x = x / spf[x];
    }
    return ret;
}

void solve(int T)
{
    sieve();
    cin >> n;
    vector<int> a(n);
    for (i = 0; i < n; i++)
        cin >> a[i];
    int x = a[0];
    for (i = 1; i < n; i++)
        x = gcd(x, a[i]);
    for (i = 0; i < n; i++)
        a[i] /= x;
    sort(a.begin(), a.end());
    if (a[0] == a[n - 1])
    {
        cout << -1;
        return;
    }
    map<int, int> primes;
    for (i = 0; i < n; i++)
    {
        set<int> temp = getFactorization(a[i]);
        for (auto itr = temp.begin(); itr != temp.end(); itr++)
            primes[*itr]++;
    }
    int ans = INT_MAX;
    for (auto itr = primes.begin(); itr != primes.end(); itr++)
        if (itr->first == 1)
            continue;
        else
            ans = min(ans, n - itr->second);
    cout << ans << "\n";
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