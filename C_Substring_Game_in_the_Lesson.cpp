#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <set>

using namespace std;

int n, m, i, j;
string s;

void solve(int T)
{
    cin >> s;
    n = s.length();
    vector<int> a(26, 0);
    for (i = 0; i < n; i++)
    {
        bool ans = 0;
        for (j = 0; j < 26 && j < s[i] - 'a'; j++)
        {
            if (a[j])
                ans = 1;
        }
        if (ans)
            cout << "Ann\n";
        else
            cout << "Mike\n";
        a[s[i] - 'a']++;
    }
}

int main()
{
    int t;
    t = 1;
    for (int p = 1; p <= t; p++)
    {
        solve(p);
        cout << "\n";
    }
}