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
typedef pair<long long, int> pi;

int n, m, i, j, k;
char c;
string s;

long long modu = 1000000007;

void printalltop(vector<char> &a, vector<vector<int>> &adjlist, vector<int> &incoming, vector<char> &temp, int &count)
{
    if (temp.size() == a.size())
    {
        count++;
        for (i = 0; i < temp.size(); i++)
            cout << temp[i] << " ";
        cout << "\n";
        return;
    }
    for (int q = 0; q < incoming.size(); q++)
    {
        if (incoming[q] == 0)
        {
            incoming[q]--;
            temp.push_back(a[q]);
            for (int z = 0; z < adjlist[q].size(); z++)
                incoming[adjlist[q][z]]--;
            printalltop(a, adjlist, incoming, temp, count);
            for (int z = 0; z < adjlist[q].size(); z++)
                incoming[adjlist[q][z]]++;
            temp.pop_back();
            incoming[q]++;
        }
    }
}

void solve(int T)
{
    string p, q;
    getline(cin, s);
    getline(cin, p);
    vector<char> a;
    map<char, int> b;
    for (i = 0, j = 0; i < s.length(); i++)
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            a.push_back(s[i]);
            b[s[i]] = a.size() - 1;
        }
    vector<int> incoming(a.size(), 0);
    vector<vector<int>> adjlist(a.size());
    for (i = 0; i < p.length(); i += 4)
        if (i + 2 < p.length())
        {
            adjlist[b[p[i]]].push_back(b[p[i + 2]]);
            incoming[b[p[i + 2]]]++;
        }
    vector<char> temp;
    int count = 0;
    printalltop(a, adjlist, incoming, temp, count);
    if (!count)
        cout << "NO\n";
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
    cin >> t;
    for (int q = 1; q <= t; q++)
    {
        solve(t);
    }
}