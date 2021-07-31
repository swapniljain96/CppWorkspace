/* Given a 2D binary matrix A(0-based index) of dimensions NxM. Find the minimum number of steps required to reach from (0,0) to (X, Y).
Note: You can only move left, right, up and down, and only through cells that contain 1.

Example 1:

Input:
N=3
M=4
A=[[1,0,0,0], 
[1,1,0,1],[0,1,1,1]]
X=2
Y=3 
Output:
5
Explanation:
The shortest path is as follows:
(0,0)->(1,0)->(1,1)->(2,1)->(2,2)->(2,3).
Example 2:

Input:
N=3
M=4
A=[[1,1,1,1],
[0,0,0,1],[0,0,0,1]]
X=0
Y=3
Output:
3
Explanation:
The shortest path is as follows:
(0,0)->(0,1)->(0,2)->(0,3).

Your Task:
You don't need to read input or print anything. Your task is to complete the function shortestDistance() which takes the integer N, M, X, Y, and the 2D binary matrix A as input parameters and returns the minimum number of steps required to go from (0,0) to (X, Y).If it is impossible to go from (0,0) to (X, Y),then function returns -1. If value of the cell (0,0) is 0 (i.e  A[0][0]=0) then return -1.


Expected Time Complexity:O(N*M)
Expected Auxillary Space:O(N*M)

 

Constraints:
1 <= N,M <= 250

0 <= X < N

0 <= Y < M
0 <= A[i][j] <= 1 */

class Solution
{
public:
    struct Point
    {
        int x;
        int y;
    };
    struct queueNode
    {
        Point pt;
        int dist;
    };
    bool isValid(int row, int col, int r, int c)
    {
        return (row >= 0) && (row < r) &&
               (col >= 0) && (col < c);
    }
    int rowNum[4] = {-1, 0, 0, 1};
    int colNum[4] = {0, -1, 1, 0};

    int shortestDistance(int r, int c, vector<vector<int>> A, int a, int b)
    {
        if (!A[0][0] || !A[a][b])
            return -1;
        vector<vector<bool>> visit(r, vector<bool>(c, false));
        visit[0][0] = true;
        queue<queueNode> q;
        queueNode s = {{0, 0}, 0};
        q.push(s);
        while (!q.empty())
        {
            queueNode curr = q.front();
            Point pt = curr.pt;
            if (a == pt.x and b == pt.y)
            {
                return curr.dist;
            }
            q.pop();
            for (int k = 0; k < 4; k++) //bcoz we have to search in 4 directions
            {
                int row = pt.x + rowNum[k];
                int col = pt.y + colNum[k];
                if (isValid(row, col, r, c) && A[row][col] && !visit[row][col])
                {
                    visit[row][col] = true;
                    q.push({{row, col}, curr.dist + 1});
                }
            }
        }
        return -1;
    }
};