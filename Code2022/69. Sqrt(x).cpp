/* Given a non-negative integer x, compute and return the square root of x.

Since the return type is an integer, the decimal digits are truncated, and only the integer part of the result is returned.
Note: You are not allowed to use any built-in exponent function or operator, such as pow(x, 0.5) or x ** 0.5.
Example 1:

Input: x = 4
Output: 2
Example 2:

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since the decimal part is truncated, 2 is returned.

Constraints:

0 <= x <= 231 - 1 */

/*
?Explanation
x=17

low   mid    high      check               ans

1             17
 \           /
       9               9*9>17
    /      \\
1            8(mid-1)
  \        /
      4                4*4<17              4  (one possible answer)
   //      \
5 (mid+1)     8
  \         /
       6               6*6>17              4 (it is still best possible answer bocz sqrt(x)*sqrt(x) cannot be greater than x)
    /     \
5          5
      5                5*5>17              4  (our answer is still 4)
here l>h and while loop ends in BS thus we get out best possible answer */

class Solution
{
public:
    int mySqrt(int x)
    {
        int l = 1, h = x;
        long long mid = 0, ans;
        while (l <= h)
        {
            mid = l + (h - l) / 2;
            if (mid * mid <= x)
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                h = mid - 1;
            }
        }
        return ans;
    }
};