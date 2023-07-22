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
#include <iomanip>

using namespace std;

int n, m, i, j;
string s;
long long modu = 1000000007;

void solve(int T)
{
    cin >> n;
    cin >> s;
    vector<string> a(n), b(n);
    for (i = 0; i < n; i++)
    {
        getline(cin, a[i]);
        b[i] = a[i];
    }
    for (i = 0; i < n; i++)
    {
        s = "";
        for (j = 0; j < a[i].length(); j++)
            if (a[i][j] != ' ')
                s += a[i][j];
        a[i] = s;
    }
    string ans = "Unhandled Exception";
    j = 0;
    for (i = 0; i < n; i++)
    {
        if (a[i].size() >= 5 && a[i].substr(0, 5) == "throw")
        {
            s = a[i].substr(6, a[i].size() - 7);
            j = 0;
            while (i < n)
            {
                if (a[i].size() >= 3 && a[i].substr(0, 3) == "try")
                    j++;
                else if (a[i].size() >= 5 && a[i].substr(0, 5) == "catch")
                {
                    if (j)
                        j--;
                    else
                    {
                        string p = "";
                        for (int k = 6; a[i][k] != ','; k++)
                            p += a[i][k];
                        if (p == s)
                        {
                            for (j = 0; j < b[i].length(); j++)
                                if (b[i][j] == '"')
                                    break;
                            j++;
                            while (j < b[i].length() && b[i][j] != '"')
                                cout << b[i][j++];
                            return;
                        }
                    }
                }
                i++;
            }
        }
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