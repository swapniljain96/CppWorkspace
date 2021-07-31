/* A frog jumps either 1, 2, or 3 steps to go to the top. In how many ways can it reach the top. As the answer will be large find the answer modulo 1000000007.

Example 1:

Input:
N = 1
Output: 1
Example 2:

Input:
N = 4
Output: 7
Explanation:Below are the 7 ways to reach
4
1 step + 1 step + 1 step + 1 step
1 step + 2 step + 1 step
2 step + 1 step + 1 step
1 step + 1 step + 2 step
2 step + 2 step
3 step + 1 step
1 step + 3 step
Your Task:
Your task is to complete the function countWays() which takes 1 argument(N) and returns the answer%(10^9 + 7).

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ N ≤ 105 */

class Solution
{
public:
    long long countWays(int n)
    {
        long long t[n + 1];
        t[0] = 1;
        t[1] = 1;
        t[2] = 2;
        t[3] = 4;
        for (int i = 4; i <= n; i++)
        {
            t[i] = (t[i - 1] + t[i - 2] + t[i - 3]) % 1000000007;
        }
        return t[n];
    }
};