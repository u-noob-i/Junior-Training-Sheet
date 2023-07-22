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
#include <iomanip>

using namespace std;

int n, m, i, j;
string s;
long long modu = 100000000;

void solve(int T)
{
    long long k;
    cin >> n >> k;
    vector<long long> a(n);
    for (i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    for (i = 0; i < n; i++)
    {
        j = i;
        while (j < n - 1 && a[j] == a[j + 1])
            j++;
        long long x = j - i + 1;
        // cout << "k: " << k << " " << x << "\n";
        if (x * n < k)
        {
            k -= (x * n);
            i = j;
            continue;
        }
        for (int p = 0; p < n; p++)
        {
            if (k <= x)
            {
                cout << a[i] << " " << a[p];
                return;
            }
            k -= x;
        }
    }
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