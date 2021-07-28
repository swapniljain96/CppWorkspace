#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
    int place = 1;
    int sum = 0;
    int n = 1008;
    while (n)
    {
        int rem = n % 10;
        if (rem == 0)
        {
            sum = sum + place * 5;
        }
        else
        {
            sum = sum + place * rem;
        }
        place = place * 10;
        n = n / 10;
    }
    cout << "\n"
         << sum;
    cout << "\n";
    system("pause");
    return 0;
}