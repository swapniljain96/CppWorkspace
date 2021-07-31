/* Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1. 

Example 1:

Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]

Example 2:

Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]
 
Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 104
1 <= m * n <= 104
mat[i][j] is either 0 or 1.
There is at least one 0 in mat. */

// Method 1: Using Dynamic Programming
class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &a)
    {
        int r = a.size();
        int c = a[0].size();
        vector<vector<int>> t(r, vector<int>(c, INT_MAX - 100000));
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (a[i][j] == 0)
                {
                    t[i][j] = 0;
                }
                else
                {
                    if (i > 0)
                    {
                        t[i][j] = min(t[i][j], t[i - 1][j] + 1);
                    }
                    if (j > 0)
                    {
                        t[i][j] = min(t[i][j], t[i][j - 1] + 1);
                    }
                }
            }
        }

        for (int i = r - 1; i >= 0; i--)
        {
            for (int j = c - 1; j >= 0; j--)
            {
                if (i < r - 1)
                {
                    t[i][j] = min(t[i][j], t[i + 1][j] + 1);
                }
                if (j < c - 1)
                {
                    t[i][j] = min(t[i][j], t[i][j + 1] + 1);
                }
            }
        }
        return t;
    }
};

// Method 2: Using BFS
class Solution
{
    int x[4] = {-1, 0, 1, 0};
    int y[4] = {0, 1, 0, -1};

public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        if (m == 0)
            return {};
        int n = matrix[0].size();
        vector<vector<int>> dis(m, vector<int>(n, -1));
        queue<pair<int, int>> que;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    que.push({i, j});
                    dis[i][j] = 0;
                }
            }
        }
        while (!que.empty())
        {
            pair<int, int> point = que.front();
            que.pop();
            for (int dir = 0; dir < 4; dir++)
            {
                int xd = point.first + x[dir];
                int yd = point.second + y[dir];
                if (xd >= 0 && yd >= 0 && xd <= m - 1 && yd <= n - 1 && matrix[xd][yd] == 1 && dis[xd][yd] == -1)
                {
                    dis[xd][yd] = dis[point.first][point.second] + 1;
                    que.push({xd, yd});
                }
            }
        }
        return dis;
    }
};