#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

int main()
{
    unsigned long long a, b;
    while (cin >> a >> b)
    {
        if (!a && !b)
            break;
        int ans = 0;
        if (a < b)
            swap(a, b);
        while (a && b)
        {
            ans++;
            if (a / b > 1)
                break;
            a -= b;
            swap(a, b);
        }
        if (ans % 2)
            cout << "Stan wins\n";
        else
            cout << "Ollie wins\n";
    }
}