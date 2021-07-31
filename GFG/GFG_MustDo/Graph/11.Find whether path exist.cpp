/* Given a grid of size n*n filled with 0, 1, 2, 3. Check whether there is a path possible from the source to destination. You can traverse up, down, right and left.
The description of cells is as follows:

A value of cell 1 means Source.
A value of cell 2 means Destination.
A value of cell 3 means Blank cell.
A value of cell 0 means Wall.
Note: There are only a single source and a single destination.
 

Example 1:

Input: grid = {{3,0,3,0,0},{3,0,0,0,3}
,{3,3,3,3,3},{0,2,3,0,0},{3,0,0,1,3}}
Output: 0
Explanation: The grid is-
3 0 3 0 0 
3 0 0 0 3 
3 3 3 3 3 
0 2 3 0 0 
3 0 0 1 3 
There is no path to reach at (3,1) i,e at 
destination from (4,3) i,e source.
Example 2:

Input: grid = {{1,3},{3,2}}
Output: 1
Explanation: The grid is-
1 3
3 2
There is a path from (0,0) i,e source to (1,1) 
i,e destination.
 

Your Task:
You don't need to read or print anything. Your task is to complete the function is_Possible() which takes the grid as input parameter and returns boolean value true if there is a path otherwise returns false.
 

Expected Time Complexity: O(n2)
Expected Auxiliary Space: O(n2)
 

Constraints:
1 ≤ n ≤ 500 */

class Solution
{
public:
    bool dfs(vector<vector<int>> &a, int i, int j, int n, vector<vector<bool>> &visited)
    {
        if (i >= 0 && j >= 0 && i < n && j < n && a[i][j] != 0 && !visited[i][j])
        {
            visited[i][j] = true;
            if (a[i][j] == 2)
                return true;
            if (dfs(a, i - 1, j, n, visited))
                return true;
            if (dfs(a, i + 1, j, n, visited))
                return true;
            if (dfs(a, i, j - 1, n, visited))
                return true;
            if (dfs(a, i, j + 1, n, visited))
                return true;
        }
        return false;
    }

    bool is_Possible(vector<vector<int>> &a)
    {
        int n = a.size();
        if (n == 0)
            return false;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (a[i][j] == 1 && !visited[i][j])
                {
                    return dfs(a, i, j, n, visited);
                }
            }
        }
        return false;
    }
};
