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
#include <climits>

using namespace std;

int n, m, i, j, k;
string s;
long long M = 1000000007;

void solve(int T)
{
    cin >> s;
    n = s.length();
    cout << 0 << " ";
    for (i = 1; i < n; i++)
    {
        if (i == n - 1)
        {
            string p = s;
            reverse(p.begin(), p.end());
            if (p < s)
                cout << 1 << " ";
            else
                cout << 0 << " ";
            return;
        }
        if (s[i] == 'a')
        {
            if (s[i + 1] == 'a')
            {
                cout << 0 << " ";
                continue;
            }
            for (j = 0, k = i; j < k; j++, k--)
                swap(s[j], s[k]);
            cout << 1 << " ";
        }
        else
        {
            if (s[i + 1] == 'a' && s[0] == 'a')
            {
                for (j = 0, k = i; j < k; j++, k--)
                    swap(s[j], s[k]);
                cout << 1 << " ";
                continue;
            }
            cout << 0 << " ";
        }
    }
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