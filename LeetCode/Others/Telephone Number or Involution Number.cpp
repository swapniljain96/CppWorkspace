/* Given a positive integer n. The task is to find the nth telephone number. The telephone numbers or the involution numbers are a sequence of integers that count the number of connection patterns in a telephone system with n subscribers, where connections are made between pairs of subscribers. These numbers also describe the number of matchings of a complete graph of n vertices, the number of permutations on n elements that are involutions, the sum of absolute value of coefficients of the Hermite polynomials, the number of standard Young tableaux with n cells, and the sum of the degrees of the irreducible representations of the symmetric group.

Telephone numbers also used to derive the number of ways to place n rooks on an n x n chessboard in such a way that no two rooks attack each other, and in such a way that the configuration of the rooks is symmetric under a diagonal reflection of the board.

Example 1:

Input: n = 4
Output: 10
Explaination: There are 10 such possible ways.
Example 2:

Input: n = 2
Output: 2
Explaination: There are only two ways.
Your Task:
You do not need  to read input or print anything. Your task is to complete the function telephoneNum() which takes n as input parameters and returns the resultant number modulo 109+7.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
1 ≤ n ≤ 1000   */

class Solution
{
public:
    long long telephoneNum(long long n)
    {
        long long dp[n + 1];
        memset(dp, 0, sizeof(dp));
        // Base case
        dp[0] = dp[1] = 1;
        // finding ith telephone number, where 2 <= i <= n.
        for (int i = 2; i <= n; i++)
            dp[i] = dp[i - 1] + (i - 1) * dp[i - 2];
        return 0LL + dp[n];
    }
};
