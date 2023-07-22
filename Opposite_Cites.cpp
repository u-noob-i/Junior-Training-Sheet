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
    vector<int> a(n);
    for (i = 0; i < n; i++)
        cin >> a[i];
    if (n % 2)
    {
        cout << "NO";
        return;
    }
    int k = n / 2;
    for (i = 0; i < n; i++)
    {
        if (a[i] == -1 && a[(i + k) % n] == -1)
            a[i] = a[(i + k) % n] = 1;
        else if (a[i] == -1)
            a[i] = a[(i + k) % n];
        else if (a[(i + k) % n] == -1)
            a[(i + k) % n] = a[i];
        else if (a[i] != a[(i + k) % n])
        {
            cout << "NO";
            return;
        }
    }
    cout << "YES\n";
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
}

int main()
{
    cin.sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve(t);
        cout << "\n";
    }
}