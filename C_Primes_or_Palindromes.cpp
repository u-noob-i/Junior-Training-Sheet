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

void SieveOfEratosthenes(vector<long long> &primes)
{
    vector<bool> prime(10000001, 1);

    for (int p = 2; p * p <= 10000000; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= 10000000; i += p)
                prime[i] = false;
        }
    }
    for (int p = 2; p <= 10000000; p++)
        if (prime[p])
            primes[p] = 1;
}

bool checkPal(int x)
{
    int y = 0, temp = x;
    while (temp)
    {
        y = (y * 10) + (temp % 10);
        temp /= 10;
    }
    return (x == y) ? 1 : 0;
}

void solve(int T)
{
    long long p, q;
    cin >> p >> q;
    vector<long long> primes(10000001, 0), pal(10000001, 0);
    SieveOfEratosthenes(primes);
    for (i = 1; i <= 10000000; i++)
    {
        primes[i] += primes[i - 1];
        if (checkPal(i))
            pal[i] = 1;
        pal[i] += pal[i - 1];
    }
    int ans = -1;
    for (int i = 10000000; i > 0; i--)
    {
        if (q * primes[i] <= p * pal[i])
        {
            ans = i;
            break;
        }
    }
    // cout << primes[10000000] << " " << pal[10000000] << "\n";
    if (ans != -1)
        cout << ans;
    else
        cout << "Palindromic tree is better than splay tree";
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