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
    cin >> n >> s;
    int count = 0;
    bool flag = 0;
    while (!flag)
    {
        flag = 1;
        for (char ch = 'z'; ch >= 'b'; ch--)
        {
            for (i = 0; i < n; i++)
            {
                if ((i > 0 && s[i] == ch && s[i - 1] == ch - 1) || (i < n - 1 && s[i] == ch && s[i + 1] == ch - 1))
                {
                    string temp = "";
                    for (j = 0; j < n; j++)
                        if (i != j)
                            temp += s[j];
                    s = temp;
                    flag = 0;
                    count++;
                    n--;
                    break;
                }
            }
            if (!flag)
                break;
        }
    }
    cout << count;
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