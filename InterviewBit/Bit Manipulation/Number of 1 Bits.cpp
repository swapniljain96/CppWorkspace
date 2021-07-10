/* Write a function that takes an unsigned integer and returns the number of 1 bits it has.
Example:
The 32-bit integer 11 has binary representation
00000000000000000000000000001011
so the function should return 3.
Note that since Java does not have unsigned int, use long for Java */

// Method 1: using built in popcount
int Solution::numSetBits(unsigned int n)
{
    int cnt = __builtin_popcount(n);
    return cnt;
}

// Method 2:
int Solution::numSetBits(unsigned int n)
{
    int cnt = 0;
    while (n)
    {
        n = n & (n - 1);
        cnt++;
    }
    return cnt;
}
