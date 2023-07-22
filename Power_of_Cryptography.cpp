#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    double a, b;
    while (scanf("%lf%lf", &a, &b) != EOF)
    {
        printf("%.0lf\n", pow(b, 1 / a));
    }
}