// On an N x N `grid`, each square `grid[i][j]` represents the elevation at that point `(i,j)`.

// Now rain starts to fall. At time `t`, the depth of the water everywhere is `t`. You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most `t`. You can swim infinite distance in zero time. Of course, you must stay within the boundaries of the grid during your swim.

// You start at the top left square `(0, 0)`. What is the least time until you can reach the bottom right square `(N-1, N-1)`?
class Solution
{
public:
    bool canReach(int t, vector<vector<int>> grid)
    {
        // every position has max(t,grid[i][j]) height
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid.size(); j++)
                grid[i][j] = max(grid[i][j], t);
        }
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid.size(), false));
        q.push({0, 0});
        vis[0][0] = true;
        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (x == grid.size() - 1 and y == grid.size() - 1)
                return true;
            if (grid[x][y] > t)
                continue;

            if (x + 1 < grid.size() and !vis[x + 1][y] and grid[x][y] >= grid[x + 1][y] and grid[x + 1][y] <= t)
            {
                q.push({x + 1, y});
                vis[x + 1][y] = true;
            }
            if (x - 1 >= 0 and !vis[x - 1][y] and grid[x][y] >= grid[x - 1][y] and grid[x - 1][y] <= t)
            {
                q.push({x - 1, y});
                vis[x - 1][y] = true;
            }
            if (y + 1 < grid.size() and !vis[x][y + 1] and grid[x][y] >= grid[x][y + 1] and grid[x][y + 1] <= t)
            {
                q.push({x, y + 1});
                vis[x][y + 1] = true;
            }
            if (y - 1 >= 0 and !vis[x][y - 1] and grid[x][y] >= grid[x][y - 1] and grid[x][y - 1] <= t)
            {
                q.push({x, y - 1});
                vis[x][y - 1] = true;
            }
        }
        return false;
    }
    int swimInWater(vector<vector<int>> &grid)
    {
        int N = grid.size();
        int l = 0, r = N * N, T_min = N * N;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (canReach(mid, grid))
            {
                T_min = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return T_min;
    }
};