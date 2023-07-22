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

using namespace std;

int n, m, i, j;
string s;

void solve(int T)
{
    int a, b, c;
    cin >> n >> a >> b;
    if (a == n - 1 && a)
    {
        cout << -1;
        return;
    }
    vector<int> arr(n, 0);
    i = 0;
    arr[i++] = 1;
    if (b == 0)
        arr[i++] = 1;
    while (i < n)
    {
        if (b)
        {
            b--;
            for (j = 0; j < i; j++)
                arr[i] += arr[j];
            arr[i]++;
        }
        else if (a)
        {
            a--;
            arr[i] = arr[i - 1] + 1;
        }
        else
            arr[i] = 1;
        i++;
    }
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
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