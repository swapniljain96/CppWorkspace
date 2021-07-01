// You are given an integer array `cost` where `cost[i]` is the cost of `ith` step on a staircase. Once you pay the cost, you can either climb one or two steps.

// You can either start from the step with index `0`, or the step with index `1`.

// Return *the minimum cost to reach the top of the floor*.
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &a)
    {
        int n = a.size();
        vector<int> dp(n);
        dp[0] = a[0];
        dp[1] = a[1];
        for (int i = 2; i < n; i++)
            dp[i] = a[i] + min(dp[i - 1], dp[i - 2]);
        return min(dp[n - 2], dp[n - 1]);
    }
};