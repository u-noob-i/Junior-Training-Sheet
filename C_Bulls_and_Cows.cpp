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

int n, m, i, j;
string s;

void gen(set<string> &num, string p)
{
    if (p.length() == 4)
    {
        num.insert(p);
        return;
    }
    for (char c = '1'; c <= '9'; c++)
    {
        bool f = 1;
        for (int r = 0; r < p.length(); r++)
            if (p[r] == c)
                f = 0;
        if (!f)
            continue;
        string temp = p;
        temp += c;
        gen(num, temp);
    }
}

pair<int, int> check(string a, string b)
{
    pair<int, int> ret = {0, 0};
    for (int p = 0; p < 4; p++)
    {
        for (int q = 0; q < 4; q++)
        {
            if (p == q && a[p] == b[q])
                ret.first++;
            else if (a[p] == b[q])
                ret.second++;
        }
    }
    return ret;
}

void solve(int T)
{
    cin >> n;
    vector<string> a(n);
    vector<pair<int, int>> b(n);
    for (i = 0; i < n; i++)
        cin >> a[i] >> b[i].first >> b[i].second;
    set<string> nums;
    for (char c = '0'; c <= '9'; c++)
    {
        string temp = "";
        temp += c;
        gen(nums, temp);
    }
    for (i = 0; i < n; i++)
    {
        for (auto itr = nums.begin(); itr != nums.end();)
        {
            pair<int, int> x = check(a[i], *itr);
            if (x == b[i])
            {
                string temp = *itr;
                itr++;
                nums.erase(temp);
            }
            else
                itr++;
        }
    }
    if (nums.size() == 1)
        cout << *nums.begin();
    if (nums.size() > 1)
        cout << "Need more data";
    if (!nums.size())
        cout << "Incorrect data";
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