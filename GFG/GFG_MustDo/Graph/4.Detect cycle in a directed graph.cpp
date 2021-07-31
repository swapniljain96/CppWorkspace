/* Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.


Example 1:

Input:
Output: 1
Explanation: 3 -> 3 is a cycle

Example 2:

Input:
Output: 0
Explanation: no cycle in the graph

Your task:
You don’t need to read input or print anything. Your task is to complete the function isCyclic() which takes the integer V denoting the number of vertices and adjacency list as input parameters and returns a boolean value denoting if the given directed graph contains a cycle or not.


Expected Time Complexity: O(V + E)
Expected Auxiliary Space: O(V)


Constraints:
1 ≤ V, E ≤ 105 */

class Solution
{
public:
    bool dfs(int u, vector<int> adj[], vector<bool> &visited, vector<bool> &backEdge)
    {
        if (!visited[u])
        {
            visited[u] = true;
            backEdge[u] = true;
        }
        for (int v : adj[u])
        {
            if (!visited[v])
            {
                if (dfs(v, adj, visited, backEdge))
                    return true;
            }
            else if (backEdge[v])
                return true;
        }
        backEdge[u] = false;
        return false;
    }
    //Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        vector<bool> visited(V, false);
        vector<bool> backEdge(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (dfs(i, adj, visited, backEdge))
                    return true;
            }
        }
        return false;
    }
};