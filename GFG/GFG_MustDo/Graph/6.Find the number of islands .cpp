/* Given a grid consisting of '0's(Water) and '1's(Land). Find the number of islands.
Note: An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.
 

Example 1:

Input:
grid = {{0,1},{1,0},{1,1},{1,0}}
Output:
1
Explanation:
The grid is-
0 1
1 0
1 1
1 0
All lands are connected.
Example 2:

Input:
grid = {{0,1,1,1,0,0,0},{0,0,1,1,0,1,0}}
Output:
2
Expanation:
The grid is-
0 1 1 1 0 0 0
0 0 1 1 0 1 0 
There are two islands one is colored in blue 
and other in orange.
 

Your Task:
You don't need to read or print anything. Your task is to complete the function numIslands() which takes grid as input parameter and returns the total number of islands.
 

Expected Time Compelxity: O(n*m)
Expected Space Compelxity: O(n*m) */

class Solution
{
public:
    void dfs(int i, int j, vector<vector<char>> &a, int n, int &cnt)
    {
        if (i < 0 || j < 0 || i >= r || j >= c || a[i][j] != '1')
            return;

        if (a[i][j] == 1)
        {
            cnt++;
        }
        a[i][j] = '2';

        dfs(i + 1, j, a, r, c);
        dfs(i, j + 1, a, r, c);
        dfs(i - 1, j, a, r, c);
        dfs(i, j - 1, a, r, c);
    }

    int numIslands(vector<vector<int>> &a, vector<int> queries)
    {
        int r = a.size();
        unordered_map<int, int> m;
        if (r == 0)
            return 0;
        int c = a[0].size();
        int island = 0;
        int cnt = 0;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (a[i][j] == '1')
                {
                    dfs(i, j, a, n, cnt);
                    m[cnt]++;
                    cnt = 0;
                }
            }
        }
        vec for (int i = 0; i < queries.size(); i++)
        {
        }
        return island;
    }
};