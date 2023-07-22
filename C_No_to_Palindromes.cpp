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
long long modu = 100000000;

void solve(int T)
{
    cin >> n >> m >> s;
    if (m == 1)
    {
        cout << "NO";
        return;
    }
    if (m == 2)
    {
        if (n == 1 && s[0] == 'a')
            cout << 'b';
        else if (n == 2 && s == "ab")
            cout << "ba";
        else
            cout << "NO";
        return;
    }
    for (i = n - 1; i >= 0; i--)
    {
        for (char c = s[i] + 1; c < 'a' + m; c++)
        {
            if ((i > 0 && s[i - 1] == c) || (i > 1 && s[i - 2] == c))
                continue;
            string q = s;
            q[i] = c;
            for (j = i + 1; j < n; j++)
            {
                char x = 'a';
                if (j > 0 && q[j - 1] == x)
                    x++;
                if (j > 1 && q[j - 2] == x)
                    x++;
                if (j > 0 && q[j - 1] == x)
                    x++;
                if (j > 1 && q[j - 2] == x)
                    x++;
                q[j] = x;
            }
            cout << q;
            return;
        }
    }
    cout << "NO";
    return;
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