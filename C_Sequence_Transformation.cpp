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

using namespace std;

int n, m, i, j, k;
char c;
string s;

long long modu = 1000000007;

void doo(set<int> &a)
{
    if (a.size() == 1)
    {
        cout << *a.begin();
        return;
    }
    if (a.size() == 2)
    {
        cout << *a.begin() << " " << *a.rbegin();
        return;
    }
    if (a.size() == 3)
    {
        cout << *a.begin() << " " << *a.begin() << " " << *a.rbegin();
        return;
    }
    int x = *a.begin();
    auto itr = a.begin();
    while (itr != a.end())
    {
        cout << x << " ";
        int y = *itr;
        itr++;
        if (itr != a.end())
            itr++;
        a.erase(y);
    }
    doo(a);
}

void solve(int T)
{
    cin >> n;
    set<int> a;
    for (i = 1; i <= n; i++)
        a.insert(i);
    doo(a);
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