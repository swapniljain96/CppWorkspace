// For an integer array `nums`, an **inverse pair** is a pair of integers `[i, j]` where `0 <= i < j < nums.length` and `nums[i] > nums[j]`.

// Given two integers n and k, return the number of different arrays consist of numbers from `1` to `n` such that there are exactly `k` **inverse pairs**. Since the answer can be huge, return it **modulo** `109 + 7`.
class Solution
{
public:
    int kInversePairs(int n, int k)
    {
        int MOD = 1000000007;
        int t[n + 1][k + 1];
        memset(t, 0, sizeof(t));
        for (int i = 0; i < n + 1; i++)
            t[i][0] = 1;
        for (int N = 1; N <= n; N++)
        {
            for (int K = 1; K <= k; K++)
            {
                t[N][K] = (t[N - 1][K] + t[N][K - 1]) % MOD;
                if (K - N >= 0)
                {
                    t[N][K] = (t[N][K] - t[N - 1][K - N] + MOD) % MOD;
                }
            }
        }
        return t[n][k];
    }
};