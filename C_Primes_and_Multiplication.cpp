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

using namespace std;

int n, m, i, j, k;
string s;
long long M = 1000000007;

long long binpow(long long a, long long b)
{
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % M;
        a = (a * a) % M;
        b >>= 1;
    }
    return res;
}

void solve(int T)
{
    long long x, y, ans = 0;
    cin >> x >> y;
    vector<long long> primes;
    for (long long i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0)
        {
            primes.push_back(i);
            while (x % i == 0)
                x /= i;
        }
    }
    if (x > 1)
        primes.push_back(x);
    for (i = 0; i < primes.size(); i++)
    {
        long long a = primes[i];
        while (a <= y)
        {
            long long l = 1, r = a - 1, mid, val = -1;
            while (l <= r)
            {
                mid = (l + r) / 2;
                if (a * mid <= y)
                {
                    val = mid;
                    l = mid + 1;
                }
                else
                    r = mid - 1;
            }
            ans = (max(ans, 1ll) * binpow(a, val)) % M;
            if (LLONG_MAX - primes[i] < a)
                break;
            a += primes[i];
        }
    }
    cout << ans;
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