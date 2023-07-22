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
    int a, b;
    cin >> a >> b;
    for (i = 1; i <= 1000; i++)
    {
        for (j = 1; j <= 1000; j++)
        {
            if ((i * i) + (j * j) == a * a)
            {
                if ((b * j) % a == 0 && (b * i) % a == 0)
                {
                    int x1 = b * j / a, y1 = b * i / a;
                    if (x1 != 0 && x1 != i && y1 != 0 && -y1 != j)
                    {
                        cout << "YES\n"
                             << 0 << " " << 0 << "\n"
                             << i << " " << j << "\n"
                             << x1 << " " << -y1;
                        return;
                    }
                    if (x1 != 0 && -x1 != i && y1 != 0 && y1 != j)
                    {
                        cout << "YES\n"
                             << 0 << " " << 0 << "\n"
                             << i << " " << j << "\n"
                             << -x1 << " " << y1;
                        return;
                    }
                }
                else
                    continue;
            }
        }
    }
    cout << "NO";
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