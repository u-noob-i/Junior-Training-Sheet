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
#include <cfloat>
#include <sstream>

using namespace std;

int n, m, i, j, k;
string s, p;
long long M = 1000000007;

void solve(int T)
{
    cin >> n;
    vector<int> a(n), b(n);
    for (i = 0; i < n; i++)
        cin >> a[i];
    for (i = 0; i < n; i++)
        cin >> b[i];
    int ans = 0;
    set<int> x;
    i = 0, j = n - 1;
    while (i < n && a[i] == b[i])
        i++;
    k = i;
    while (i < n && j >= k)
    {
        if (i < n && x.find(b[i]) != x.end())
        {
            x.erase(b[i]);
            i++;
        }
        else if (i < n && k <= j && a[k] == b[i])
        {
            i++;
            k++;
        }
        else if (i < n && j >= k && a[j] == b[i])
        {
            ans++;
            i++;
            j--;
        }
        else if (i < n && j >= k)
        {
            x.insert(a[j]);
            ans++;
            j--;
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