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

int n, m, i, j, k;
string s;
long long M = 1000000007;

void solve(int T)
{
    cin >> n;
    vector<int> a(n);
    for (i = 0; i < n; i++)
        cin >> a[i];
    map<int, int> count;
    set<int> mex;
    for (i = 0; i < n; i++)
        count[a[i]]++;
    for (i = 0; i <= n; i++)
        if (!count[i])
            mex.insert(i);
    i = -1;
    vector<int> arr;
    while (i < n - 1)
    {
        while (i < n - 1 && a[i + 1] == i + 1)
            i++;
        if (i == n - 1)
            break;
        int x = *mex.begin();
        if (x == i + 1)
        {
            i++;
            mex.erase(i);
            count[a[i]]--;
            if (!count[a[i]])
            {
                count.erase(a[i]);
                mex.insert(a[i]);
            }
            a[i] = i;
            arr.push_back(i + 1);
        }
        else if (x != n && a[x] != x)
        {
            mex.erase(x);
            count[x]++;
            count[a[x]]--;
            if (!count[a[x]])
            {
                count.erase(a[x]);
                mex.insert(a[x]);
            }
            a[x] = x;
            arr.push_back(x + 1);
        }
        else
        {
            x = *mex.begin();
            for (j = 0; j < n; j++)
            {
                if (a[j] == i + 1)
                {
                    mex.erase(x);
                    count[i + 1]--;
                    if (!count[i + 1])
                    {
                        count.erase(i + 1);
                        mex.insert(i + 1);
                    }
                    count[x]++;
                    a[j] = x;
                    arr.push_back(j + 1);
                    break;
                }
            }
        }
    }
    cout << arr.size() << "\n";
    for (i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << "\n";
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
    }
}