// You are given a **0-indexed** integer array `nums` and an integer `k`.

// You are initially standing at index `0`. In one move, you can jump at most `k` steps forward without going outside the boundaries of the array. That is, you can jump from index `i` to any index in the range `[i + 1, min(n - 1, i + k)]` **inclusive**.

// You want to reach the last index of the array (index `n - 1`). Your **score** is the **sum** of all `nums[j]` for each index `j` you visited in the array.

// Return *the **maximum score** you can get*.
class Solution
{
public:
    int maxResult(vector<int> &a, int k)
    {
        int n = a.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = a[0];

        multiset<int, greater<int>> s;
        s.insert(dp[0]);
        for (int i = 1; i < n; i++)
        {
            int val = *s.begin();
            dp[i] = a[i] + val;

            if (i - k >= 0)
            {
                s.erase(s.find(dp[i - k]));
            }
            s.insert(dp[i]);
        }
        return dp[n - 1];
    }
};