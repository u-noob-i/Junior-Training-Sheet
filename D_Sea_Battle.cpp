#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <numeric>
#include <queue>
#include <climits>

using namespace std;

int n, m, i, j, k;
string s, p;
long long M = 998244353;

bool myfunc(vector<int> &a, vector<int> &b)
{
    return (a[0] > b[0]);
}

void solve(int T)
{
    int a, b;
    cin >> n >> a >> b >> k >> s;
    vector<vector<int>> ranges;
    i = 0;
    int tot = 0;
    while (i < n)
    {
        while (i < n && s[i] == '1')
            i++;
        if (i == n)
            break;
        int l, r;
        l = i;
        while (i < n - 1 && s[i + 1] == '0')
            i++;
        r = i;
        i++;
        tot += (r - l + 1) / b;
        ranges.push_back({(r - l + 1) / b, l, r});
    }
    sort(ranges.begin(), ranges.end(), myfunc);
    m = ranges.size();
    i = 0;
    vector<int> ans;
    while (i < m && tot >= a)
    {
        while (!ranges[i][0])
            i++;
        ranges[i][0]--;
        ranges[i][1] += b;
        tot--;
        ans.push_back(ranges[i][1]);
    }
    cout << ans.size() << "\n";
    for (i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}

int main()
{
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