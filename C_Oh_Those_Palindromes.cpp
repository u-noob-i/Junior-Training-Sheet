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

using namespace std;

int n, m, i, j, k;
char c;
string s;

long long modu = 1000000007;

void solve(int T)
{
    cin >> n >> s;
    vector<long long> count(26, 0);
    long long ans = 0;
    for (i = 0; i < n; i++)
        count[s[i] - 'a']++;
    sort(s.begin(), s.end());
    cout << s;
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