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
    cin >> n >> s;
    vector<long long> a(4, 0);
    for (i = 0; i < n; i++)
        if (s[i] == 'A')
            a[0]++;
        else if (s[i] == 'C')
            a[1]++;
        else if (s[i] == 'G')
            a[2]++;
        else
            a[3]++;
    sort(a.begin(), a.end());
    long long count = 0;
    for (i = 0; i < 4; i++)
        if (a[i] == a[3])
            count++;
    long long ans = 1;
    for (i = 0; i < n; i++)
        ans = (ans * count) % modu;
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