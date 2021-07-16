/* Given an integar A.
Compute and return the square root of A.
If A is not a perfect square, return floor(sqrt(A)).
DO NOT USE SQRT FUNCTION FROM STANDARD LIBRARY
Input Format
The first and only argument given is the integer A.
Output Format
Return floor(sqrt(A))
Constraints
1 <= A <= 10^9
For Example
Input 1:
    A = 11
Output 1:
    3
Input 2:
    A = 9
Output 2:
    3 */

//Method 1: use binary search for finding the floor value of (x*x),inturn we get sqrt of x from this
// TC=O(logn)
int Solution::sqrt(int n)
{
    int l = 1, r = n;
    int res;
    while (l <= r)
    {
        long m = l + (r - l) / 2;
        if (m * m <= n)
        {
            res = m;
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    return (int)res;
}

//Method 2: iterative approach
// TC=O(n)
int Solution::sqrt(int A)
{
    long int i = 1;
    while (i * i <= A)
        i++;
    if (i * i == A)
        return i;
    return --i;
}