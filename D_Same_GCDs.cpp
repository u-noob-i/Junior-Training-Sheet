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

using namespace std;

#define rep(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define irep(a, b, c) for (int(a) = (b); (a) >= (c); --(a))

long long gcd(long long a, long long b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int n, m, i, j, k;
string s;
long long M = 998244353;

void solve(int T)
{
    long long x, y;
    cin >> x >> y;
    long long g = gcd(x, y), p = x / g, q = y / g, temp;
    vector<long long> primes;
    temp = q;
    if (temp % 2 == 0)
    {
        primes.push_back(2);
        while (temp % 2 == 0)
            temp /= 2;
    }
    for (long long a = 3; a <= sqrt(temp); a += 2)
        if (temp % a == 0)
        {
            primes.push_back(a);
            while (temp % a == 0)
                temp /= a;
        }
    if (temp > 1)
        primes.push_back(temp);
    long long ans = q;
    for (i = 0; i < primes.size(); i++)
        ans -= ans / primes[i];
    cout << ans;
}

int main()
{
    cin.sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve(t);
        cout << "\n";
    }
}