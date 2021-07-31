/* Given a square grid of size N, each cell of which contains integer cost which represents a cost to traverse through that cell, we need to find a path from top left cell to bottom right cell by which the total cost incurred is minimum.
From the cell (i,j) we can go (i,j-1), (i, j+1), (i-1, j), (i+1, j). 

Note: It is assumed that negative cost cycles do not exist in the input matrix.
 

Example 1:

Input: grid = {{9,4,9,9},{6,7,6,4},
{8,3,3,7},{7,4,9,10}}
Output: 43
Explanation: The grid is-
9 4 9 9
6 7 6 4
8 3 3 7
7 4 9 10
The minimum cost is-
9 + 4 + 7 + 3 + 3 + 7 + 10 = 43.
Example 2:

Input: grid = {{4,4},{3,7}}
Output: 14
Explanation: The grid is-
4 4
3 7
The minimum cost is- 4 + 3 + 7 = 14.
 

Your Task:
You don't need to read or print anything. Your task is to complete the function minimumCostPath() which takes grid as input parameter and returns the minimum cost to react at bottom right cell from top left cell.
 

Expected Time Compelxity: O(n2*log(n))
Expected Auxiliary Space: O(n2) 
 

Constraints:
1 ≤ n ≤ 500
1 ≤ cost of cells ≤ 1000 */

class Solution
{ 
static int[] dx = { -1, 0, 1, 0 };
static int[] dy = { 0, 1, 0, -1 };
static class Cell
{   int x;    int y;
    int distance;
    Cell(int x, int y, int distance)
    {   this.x = x;
        this.y = y;
        this.distance = distance;
    }
}

static class distanceComparator  implements Comparator<Cell>
{   public int compare(Cell a, Cell b)
    {   if (a.distance < b.distance) {   return -1;   }
        else if (a.distance > b.distance)
        {   return 1; }
        else {return 0;}
    }
}
 
static boolean isInsideGrid(int i, int j,int row,int col)
{ return (i >= 0 && i < row &&  j >= 0 && j < col); }

public int minimumCostPath(int[][] grid)
    {   int row,col;
        row=col=grid.length;
        int[][] dist = new int[row][col];
        for(int i = 0; i < row; i++)
        {  for(int j = 0; j < col; j++)
           { dist[i][j] = Integer.MAX_VALUE;}
        }
        dist[0][0] = grid[0][0];
        PriorityQueue<Cell> pq = new PriorityQueue<Cell>(row * col, new distanceComparator());
                   
        pq.add(new Cell(0, 0, dist[0][0]));
        while (!pq.isEmpty())
        {   Cell curr = pq.poll();
            for(int i = 0; i < 4; i++)
            {   int rows = curr.x + dx[i];
                int cols = curr.y + dy[i];
                if (isInsideGrid(rows, cols,row,col))
                {   if (dist[rows][cols] >
                        dist[curr.x][curr.y] +
                        grid[rows][cols])
                        {  if (dist[rows][cols] != Integer.MAX_VALUE)
                        {   Cell adj = new Cell(rows, cols,dist[rows][cols]);
                            pq.remove(adj);
                        }
                        dist[rows][cols] = dist[curr.x][curr.y] +   grid[rows][cols];
                        pq.add(new Cell(rows, cols,dist[rows][cols]));
                    }
                }
            }
        }
     return dist[row - 1][col - 1];
    }
}