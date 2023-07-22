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
    cin >> n;
    vector<int> a(n);
    map<int, long long> arr;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        arr[a[i]]++;
    }
    long long ans = 0;
    for (i = 0; i < n; i++)
    {
        arr[a[i]]--;
        ans += arr[-a[i]];
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