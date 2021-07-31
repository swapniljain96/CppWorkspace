/* Given a 5x6 snakes and ladders board, find the minimum number of dice throws required to reach the destination or last cell (30th cell) from the source (1st cell).

You are given an integer N denoting the total number of snakes and ladders and an array arr[] of 2*N size where 2*i and (2*i + 1)th values denote the starting and ending point respectively of ith snake or ladder. The board looks like the following.

Example 1:

Input:
N = 8
arr[] = {3, 22, 5, 8, 11, 26, 20, 29, 
       17, 4, 19, 7, 27, 1, 21, 9}
Output: 3
Explanation:
The given board is the board shown
in the figure. For the above board 
output will be 3. 
a) For 1st throw get a 2. 
b) For 2nd throw get a 6.
c) For 3rd throw get a 2.

Your Task:
You do not need to read input or print anything. Your task is to complete the function minThrow() which takes N and arr as input parameters and returns the minimum number of throws required to reach the end of the game.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)


Constraints:
1 ≤ N ≤ 10
1 ≤ arr[i] ≤ 30 */

class Solution
{
public:
    int minThrow(int N, int arr[])
    {
        unordered_map<int, int> m;
        int size = 2 * N;
        for (int i = 0; i < size - 1; i += 2)
            m[arr[i]] = arr[i + 1];
        vector<int> adj[32];
        for (int i = 1; i <= 30; i++)
        {
            if (m.find(i) != m.end()) // leaving those squares which are either start of ladder or snake
                continue;
            for (int j = 1; j <= 6; j++)
            {
                if (i + j <= 30)
                {
                    if (m.find(i + j) == m.end())
                    {
                        adj[i].push_back(i + j);
                    }

                    else if (m.find(i + j) != m.end())
                    {
                        adj[i].push_back(m[i + j]);
                    }
                }
            }
        }
        vector<bool> visited(32, false); // Do not forget to add this too!!! Since the graph may contain cycles
        queue<int> q;
        q.push(1);
        visited[1] = true;
        int depth = 0; //current depth of the BFS tree
        while (!q.empty())
        {
            int lsize = q.size(); // current level size of the BFS tree
            while (lsize--)
            {
                int u = q.front();
                q.pop();
                if (u == 30)
                    return depth;
                for (int v : adj[u])
                {
                    if (!visited[v])
                    {
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }
            depth++;
        }
        return -1;
    }
};