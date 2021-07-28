/* Given a positive integer n, return the number of the integers in the range [0, n] whose binary representations do not contain consecutive ones.

Example 1:

Input: n = 5
Output: 5
Explanation:
Here are the non-negative integers <= 5 with their corresponding binary representations:
0 : 0
1 : 1
2 : 10
3 : 11
4 : 100
5 : 101
Among them, only integer 3 disobeys the rule (two consecutive ones) and the other 5 satisfy the rule. 
Example 2:

Input: n = 1
Output: 2
Example 3:

Input: n = 2
Output: 3
 
Constraints:
1 <= n <= 109 */

class Solution
{
public:
    int findIntegers(int n)
    {
        int f[32];
        f[0] = 1;
        f[1] = 2;
        for (int i = 2; i < 32; ++i)
            f[i] = f[i - 1] + f[i - 2];
        int ans = 0, k = 30, pre_bit = 0;
        while (k >= 0)
        {
            if (n & (1 << k))
            {
                ans += f[k];
                if (pre_bit)
                    return ans;
                pre_bit = 1;
            }
            else
                pre_bit = 0;
            --k;
        }
        return ans + 1;
    }
};