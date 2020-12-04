#include <iostream>
#include <string>
using namespace std;
 
// count all n-digit binary strings without any consecutive 1's
int countStrings(int n)
{
    int T[n+1][2];
 
    T[0][0] = 0, T[0][1] = 0;        // no digit is left
    T[1][0] = 2, T[1][1] = 1;        // if only one digit is left
 
    for (int i = 2; i <= n; i++)
    {
        // if last digit is 0, we can have both 0 and 1 at current position
        T[i][0] = T[i-1][0] + T[i-1][1];
 
        // if last digit is 1, we can have only 0 at current position
        T[i][1] = T[i-1][0];
    }
 
    return T[n][0];
 
}
 
int main()
{
    // given number of digits
    int n = 5;
 
    cout << "Number of " << n << "-digit binary strings without any "
        "consecutive 1's are " << countStrings(n);
 
    return 0;
}

/*
#include <iostream>
#include <string>
using namespace std;
 
// print all n-digit binary strings without any consecutive 1's
void countStrings(int n, string out, int last_digit)
{
    // if number becomes N-digit, print it
    if (n == 0)
    {
        cout << out << endl;
        return;
    }
 
    // append 0 to the result and recur with one less digit
    countStrings(n - 1, out + "0", 0);
 
    // append 1 to the result and recur with one less digit
    // only if last digit is 0
    if (last_digit == 0)
        countStrings(n - 1, out + "1", 1);
}
 
int main()
{
    // given number of digits
    int n = 5;
    string out = "";
 
    countStrings(n, out, 0);
 
    return 0;
}
*/


