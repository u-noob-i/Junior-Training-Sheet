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

void solve(int T)
{
    int k;
    cin >> n >> k;
    vector<long long> a(n);
    for (i = 0; i < n; i++)
        cin >> a[i];
    long long sum = 0, ans = 0;
    map<long long, int> count;
    for (i = 0; i < n; i++)
    {
        sum += a[i];
        count[sum]++;
    }
    sum = 0;
    for (i = 0; i < n; i++)
    {
        if (k == 1)
            ans += count[1 + sum];
        else if (k == -1)
        {
            ans += count[1 + sum];
            ans += count[-1 + sum];
        }
        else
            for (long long temp = 1; abs(temp) <= 1000000000000000; temp *= k)
                ans += count[temp + sum];
        sum += a[i];
        count[sum]--;
    }
    cout << ans;
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