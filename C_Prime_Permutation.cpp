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
set<int> primes;

void SieveOfEratosthenes()
{
    vector<bool> prime(1001, 1);

    for (int p = 2; p * p <= 1000; p++)
        if (prime[p] == true)
            for (int i = p * p; i <= 1000; i += p)
                prime[i] = false;
    for (int p = 2; p <= 1000; p++)
        if (prime[p])
            primes.insert(p);
}

void solve(int T)
{
    cin >> s;
    n = s.length();
    vector<int> count(26, 0);
    for (i = 0; i < n; i++)
        count[s[i] - 'a']++;
    int k = 0;
    for (i = 0; i < 26; i++)
        if (count[k] < count[i])
            k = i;
    SieveOfEratosthenes();
    vector<bool> f(n, 1);
    f[0] = 0;
    for (i = (n / 2) + 1; i <= n; i++)
        if (primes.find(i) != primes.end())
            f[i - 1] = 0;
    for (i = 0; i < n; i++)
        if (f[i])
        {
            // cout << i << " " << k << " " << count[k] << "\n";
            if (!count[k])
            {
                cout << "NO";
                return;
            }
            count[k]--;
            s[i] = 'a' + k;
        }
    k = 0;
    for (i = 0; i < n; i++)
    {
        if (f[i])
            continue;
        while (count[k] == 0)
            k++;
        s[i] = 'a' + k;
        count[k]--;
    }
    cout << "YES\n"
         << s;
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