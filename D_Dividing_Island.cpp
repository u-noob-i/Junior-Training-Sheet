#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <numeric>

using namespace std;

int n, m, i, j;

void solve(int T)
{
    int a, b, c, d;
    cin >> a >> b >> c >> d >> n;
    vector<int> arr(n);
    for (i = 0; i < n; i++)
        cin >> arr[i];
    vector<vector<char>> ans(max(b, d), vector<char>(a + c, '.'));
    if (b > d)
    {
        int cur = 0;
        if (c % 2)
        {
            i = a + c - 1;
            int turn = 0;
            while (i >= a)
            {
                if (turn % 2 == 0)
                {
                    for (j = d - 1; j >= 0; j--)
                    {
                        if (cur >= n)
                            break;
                        while (!arr[cur])
                            cur++;
                        if (arr[cur])
                        {
                            ans[j][i] = 'a' + cur;
                            arr[cur]--;
                        }
                    }
                }
                else
                {
                    for (j = 0; j < d; j++)
                    {
                        if (cur >= n)
                            break;
                        while (!arr[cur])
                            cur++;
                        if (arr[cur])
                        {
                            ans[j][i] = 'a' + cur;
                            arr[cur]--;
                        }
                    }
                }
                turn++;
                i--;
            }
            while (i >= 0)
            {
                if (turn % 2 == 0)
                {
                    for (j = b - 1; j >= 0; j--)
                    {
                        if (cur >= n)
                            break;
                        while (!arr[cur])
                            cur++;
                        if (arr[cur])
                        {
                            ans[j][i] = 'a' + cur;
                            arr[cur]--;
                        }
                    }
                }
                else
                {
                    for (j = 0; j < b; j++)
                    {
                        if (cur >= n)
                            break;
                        while (!arr[cur])
                            cur++;
                        if (arr[cur])
                        {
                            ans[j][i] = 'a' + cur;
                            arr[cur]--;
                        }
                    }
                }
                turn++;
                i--;
            }
        }
        else
        {
            i = a + c - 1;
            int turn = 0;
            while (i >= a)
            {
                if (turn % 2 == 0)
                {
                    for (j = d - 1; j >= 0; j--)
                    {
                        if (cur >= n)
                            break;
                        while (!arr[cur])
                            cur++;
                        if (arr[cur])
                        {
                            ans[j][i] = 'a' + cur;
                            arr[cur]--;
                        }
                    }
                }
                else
                {
                    for (j = 0; j < d; j++)
                    {
                        if (cur >= n)
                            break;
                        while (!arr[cur])
                            cur++;
                        if (arr[cur])
                        {
                            ans[j][i] = 'a' + cur;
                            arr[cur]--;
                        }
                    }
                }
                turn++;
                i--;
            }
            while (i >= 0)
            {
                if (turn % 2)
                {
                    for (j = b - 1; j >= 0; j--)
                    {
                        if (cur >= n)
                            break;
                        while (!arr[cur])
                            cur++;
                        if (arr[cur])
                        {
                            ans[j][i] = 'a' + cur;
                            arr[cur]--;
                        }
                    }
                }
                else
                {
                    for (j = 0; j < b; j++)
                    {
                        if (cur >= n)
                            break;
                        while (!arr[cur])
                            cur++;
                        if (arr[cur])
                        {
                            ans[j][i] = 'a' + cur;
                            arr[cur]--;
                        }
                    }
                }
                turn++;
                i--;
            }
        }
    }
    else
    {
        int cur = 0;
        if (a % 2)
        {
            i = 0;
            int turn = 0;
            while (i < a)
            {
                if (turn % 2 == 0)
                {
                    for (j = b - 1; j >= 0; j--)
                    {
                        if (cur >= n)
                            break;
                        while (!arr[cur])
                            cur++;
                        if (arr[cur])
                        {
                            ans[j][i] = 'a' + cur;
                            arr[cur]--;
                        }
                    }
                }
                else
                {
                    for (j = 0; j < b; j++)
                    {
                        if (cur >= n)
                            break;
                        while (!arr[cur])
                            cur++;
                        if (arr[cur])
                        {
                            ans[j][i] = 'a' + cur;
                            arr[cur]--;
                        }
                    }
                }
                turn++;
                i++;
            }
            while (i < a + c)
            {
                if (turn % 2 == 0)
                {
                    for (j = d - 1; j >= 0; j--)
                    {
                        if (cur >= n)
                            break;
                        while (!arr[cur])
                            cur++;
                        if (arr[cur])
                        {
                            ans[j][i] = 'a' + cur;
                            arr[cur]--;
                        }
                    }
                }
                else
                {
                    for (j = 0; j < d; j++)
                    {
                        if (cur >= n)
                            break;
                        while (!arr[cur])
                            cur++;
                        if (arr[cur])
                        {
                            ans[j][i] = 'a' + cur;
                            arr[cur]--;
                        }
                    }
                }
                turn++;
                i++;
            }
        }
        else
        {
            i = 0;
            int turn = 0;
            while (i < a)
            {
                if (turn % 2 == 0)
                {
                    for (j = b - 1; j >= 0; j--)
                    {
                        if (cur >= n)
                            break;
                        while (!arr[cur])
                            cur++;
                        if (arr[cur])
                        {
                            ans[j][i] = 'a' + cur;
                            arr[cur]--;
                        }
                    }
                }
                else
                {
                    for (j = 0; j < b; j++)
                    {
                        if (cur >= n)
                            break;
                        while (!arr[cur])
                            cur++;
                        if (arr[cur])
                        {
                            ans[j][i] = 'a' + cur;
                            arr[cur]--;
                        }
                    }
                }
                turn++;
                i++;
            }
            while (i < a + c)
            {
                if (turn % 2)
                {
                    for (j = d - 1; j >= 0; j--)
                    {
                        if (cur >= n)
                            break;
                        while (!arr[cur])
                            cur++;
                        if (arr[cur])
                        {
                            ans[j][i] = 'a' + cur;
                            arr[cur]--;
                        }
                    }
                }
                else
                {
                    for (j = 0; j < d; j++)
                    {
                        if (cur >= n)
                            break;
                        while (!arr[cur])
                            cur++;
                        if (arr[cur])
                        {
                            ans[j][i] = 'a' + cur;
                            arr[cur]--;
                        }
                    }
                }
                turn++;
                i++;
            }
        }
    }
    cout << "YES";
    for (i = 0; i < max(b, d); i++)
    {
        cout << "\n";
        for (j = 0; j < a + c; j++)
            cout << ans[i][j];
    }
}

int main()
{
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