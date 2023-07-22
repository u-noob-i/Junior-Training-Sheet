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

void solve(int T)
{
    cin >> m >> n;
    if (!n && !m)
        return;
    vector<string> arr(n);
    for (i = 0; i < n; i++)
        cin >> arr[i];
    vector<vector<long long>> a(n, vector<long long>(m));
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            if (arr[i][j] == 'X' || arr[i][j] == 'D')
                a[i][j] = LLONG_MAX;
            else if (arr[i][j] == 'S')
                a[i][j] = 0;
            else
                a[i][j] = arr[i][j] - '0';
    vector<long long> cost(n * m, LLONG_MAX);
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    int x;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            if (arr[i][j] == 'S')
            {
                x = (i * m) + j;
                break;
            }
    pq.push({0, x});
    cost[x] = 0;
    while (!pq.empty())
    {
        pair<long long, int> p = pq.top();
        pq.pop();
        x = p.second;
        i = x / m;
        j = x % m;
        if (arr[i][j] == 'D')
            continue;
        if (i > 0 && arr[i - 1][j] != 'X' && cost[x - m] > cost[x] + a[i][j])
        {
            cost[x - m] = cost[x] + a[i][j];
            pq.push({cost[x - m], x - m});
        }
        if (i < n - 1 && arr[i + 1][j] != 'X' && cost[x + m] > cost[x] + a[i][j])
        {
            cost[x + m] = cost[x] + a[i][j];
            pq.push({cost[x + m], x + m});
        }
        if (j > 0 && arr[i][j - 1] != 'X' && cost[x - 1] > cost[x] + a[i][j])
        {
            cost[x - 1] = cost[x] + a[i][j];
            pq.push({cost[x - 1], x - 1});
        }
        if (j < m - 1 && arr[i][j + 1] != 'X' && cost[x + 1] > cost[x] + a[i][j])
        {
            cost[x + 1] = cost[x] + a[i][j];
            pq.push({cost[x + 1], x + 1});
        }
    }
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            if (arr[i][j] == 'D')
            {
                x = (i * m) + j;
                break;
            }
    cout << cost[x] << "\n";
    solve(T);
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
    for (int i = 1; i <= t; i++)
    {
        solve(t);
        cout << "\n";
    }
}