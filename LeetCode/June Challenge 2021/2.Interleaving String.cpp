// Given strings `s1`, `s2`, and `s3`, find whether `s3` is formed by an **interleaving** of `s1` and `s2`.

// An **interleaving** of two strings `s` and `t` is a configuration where they are divided into **non-empty** substrings such that:

// - `s = s1 + s2 + ... + sn`
// - `t = t1 + t2 + ... + tm`
// - `|n - m| <= 1`
// - The **interleaving** is `s1 + t1 + s2 + t2 + s3 + t3 + ...` or `t1 + s1 + t2 + s2 + t3 + s3 + ...`

// **Note:** `a + b` is the concatenation of strings `a` and `b`.
class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        int l1 = s1.length();
        int l2 = s2.length();
        int l3 = s3.length();

        if (l1 + l2 != l3)
            return false;

        bool dp[l2 + 1][l1 + 1];
        dp[0][0] = true;

        for (int j = 1; j < l1 + 1; j++)
        {
            dp[0][j] = dp[0][j - 1] && (s1[j - 1] == s3[j - 1]);
        }

        for (int i = 1; i < l2 + 1; i++)
        {
            dp[i][0] = dp[i - 1][0] && (s2[i - 1] == s3[i - 1]);
        }

        for (int i = 1; i < l2 + 1; i++)
        {
            for (int j = 1; j < l1 + 1; j++)
            {
                dp[i][j] = (dp[i - 1][j] && (s2[i - 1] == s3[i + j - 1])) ||
                           (dp[i][j - 1] && (s1[j - 1] == s3[i + j - 1]));
            }
        }
        return dp[l2][l1];
    }
};