/* Determine whether an integer is a palindrome. Do this without extra space.

A palindrome integer is an integer x for which reverse(x) = x where reverse(x) is x with its digit reversed.
Negative numbers are not palindromic.

Example :

Input : 12121
Output : True

Input : 123
Output : False */

// Method 1: By reversing the number
int Solution::isPalindrome(int a)
{
    int n = a;
    int r = 0;
    while (n > 0)
    {
        r = r * 10 + n % 10;
        n /= 10;
    }
    return r == a;
}

//Method 2: By casting to string and checking for reverse conversion
int Solution::isPalindrome(int a)
{
    string s = to_string(a);
    string r = s;
    reverse(r.begin(), r.end());
    return r == s;
}
