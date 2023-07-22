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

using namespace std;

int n, m, i, j, k, q;
string s, p;
long long M = 1000000007;

void solve(int T)
{
    cin >> n >> k;
    vector<string> a(n);
    map<string, int> arr;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        arr[a[i]]++;
    }
    long long ans = 0;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            s = a[i];
            for (q = 0; q < k; q++)
                if (a[i][q] != a[j][q] && a[i][q] != 'S' && a[j][q] != 'S')
                    s[q] = 'S';
                else if (a[i][q] != a[j][q] && a[i][q] != 'E' && a[j][q] != 'E')
                    s[q] = 'E';
                else if (a[i][q] != a[j][q] && a[i][q] != 'T' && a[j][q] != 'T')
                    s[q] = 'T';
            long long temp = arr[s];
            if (a[i] == s)
                temp -= 2;
            ans += max(temp, 0ll);
        }
    }
    cout << ans / 3;
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