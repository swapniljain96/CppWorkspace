// You are given an `m x n` binary matrix `grid`. An island is a group of `1`'s (representing land) connected **4-directionally** (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

// The **area** of an island is the number of cells with a value `1` in the island.

// Return *the maximum **area** of an island in* `grid`. If there is no island, return `0`.
class Solution
{
public:
    int dfs(vector<vector<int>> &a, int i, int j)
    {
        int r = a.size();
        int c = a[0].size();
        if (i < 0 || j < 0 || i >= r || j >= c || a[i][j] != 1)
            return 0;
        a[i][j] = 2;
        return (1 + dfs(a, i + 1, j) + dfs(a, i, j + 1) + dfs(a, i - 1, j) + dfs(a, i, j - 1));
    }

    int maxAreaOfIsland(vector<vector<int>> &a)
    {
        int r = a.size();
        int c = a[0].size();
        int ans = 0;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (a[i][j] == 1)
                {
                    ans = max(ans, dfs(a, i, j));
                }
            }
        }
        return ans;
    }
};