// Alice and Bob take turns playing a game, with **Alice starting first**.

// There are `n` stones arranged in a row. On each player's turn, they can **remove** either the leftmost stone or the rightmost stone from the row and receive points equal to the **sum** of the remaining stones' values in the row. The winner is the one with the higher score when there are no stones left to remove.

// Bob found that he will always lose this game (poor Bob, he always loses), so he decided to **minimize the score's difference**. Alice's goal is to **maximize the difference** in the score.

// Given an array of integers `stones` where `stones[i]` represents the value of the `ith` stone **from the left**, return *the **difference** in Alice and Bob's score if they both play **optimally**.*
class Solution
{
public:
    int solve(int l, int r, vector<int> &a, int sum, vector<vector<int>> &dp)
    {
        if (l == r)
            return 0;
        if (dp[l][r] != -1)
        {
            return dp[l][r];
        }
        int c1 = sum - a[l] - solve(l + 1, r, a, sum - a[l], dp);
        int c2 = sum - a[r] - solve(l, r - 1, a, sum - a[r], dp);
        return dp[l][r] = max(c1, c2);
    }

    int stoneGameVII(vector<int> &a)
    {
        int n = a.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int sum = accumulate(a.begin(), a.end(), 0);
        return solve(0, n - 1, a, sum, dp);
    }
};