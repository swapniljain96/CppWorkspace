// There is an `m x n` grid with a ball. The ball is initially at the position `[startRow, startColumn]`. You are allowed to move the ball to one of the four adjacent cells in the grid (possibly out of the grid crossing the grid boundary). You can apply **at most** `maxMove` moves to the ball.

// Given the five integers `m`, `n`, `maxMove`, `startRow`, `startColumn`, return the number of paths to move the ball out of the grid boundary. Since the answer can be very large, return it **modulo** `109 + 7`.
class Solution
{
public:
#define MOD 1000000007
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        vector<vector<int>> dp1(m, vector<int>(n, 0));
        dp1[startRow][startColumn] = 1;
        int ans = 0;
        for (int moves = 1; moves <= maxMove; moves++)
        {
            vector<vector<int>> dp2(m, vector<int>(n, 0));
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    int right = (j + 1 < n ? dp1[i][j + 1] : 0);
                    int left = (j - 1 >= 0 ? dp1[i][j - 1] : 0);
                    int up = (i - 1 >= 0 ? dp1[i - 1][j] : 0);
                    int down = (i + 1 < m ? dp1[i + 1][j] : 0);

                    dp2[i][j] = (dp2[i][j] + right) % MOD;
                    dp2[i][j] = (dp2[i][j] + left) % MOD;
                    dp2[i][j] = (dp2[i][j] + up) % MOD;
                    dp2[i][j] = (dp2[i][j] + down) % MOD;
                }
            }
            for (int i = 0; i < m; i++)
            {
                ans = (ans + dp1[i][0]) % MOD;
                ans = (ans + dp1[i][n - 1]) % MOD;
            }
            for (int i = 0; i < n; i++)
            {
                ans = (ans + dp1[0][i]) % MOD;
                ans = (ans + dp1[m - 1][i]) % MOD;
            }
            swap(dp1, dp2);
        }
        return ans;
    }
};