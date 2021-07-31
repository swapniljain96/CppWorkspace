/* Given a weighted, undirected and connected graph of V vertices and E edges, Find the shortest distance of all the vertex's from the source vertex S.
Note: The Graph doesn't contain any negative weight cycle.

Example 1:

Input:

S = 0
Output:
0 9
Explanation:
Shortest distance of all nodes from
source is printed.
Example 2:

Input:

S = 2
Output:
4 3 0
Explanation:
For nodes 2 to 0, we can follow the path-
2-1-0. This has a distance of 1+3 = 4,
whereas the path 2-0 has a distance of 6. So,
the Shortest path from 2 to 0 is 4.
The other distances are pretty straight-forward.
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function dijkstra()  which takes number of vertices V and an adjacency list adj as input parameters and returns a list of integers, where ith integer denotes the shortest distance of the ith node from Source node. Here adj[i] contains a list of lists containing two integers where the first integer j denotes that there is an edge between i and j and second integer w denotes that the weight between edge i and j is w.

 

Expected Time Complexity: O(V2).
Expected Auxiliary Space: O(V2).

 

Constraints:
1 ≤ V ≤ 1000
0 ≤ adj[i][j] ≤ 1000
0 ≤ S < V */

#define pp pair<int, int>
class Solution
{
public:
    //Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        vector<int> weight(V, INT_MAX);
        pq.push({0, S}); // pair= { weight,vertex }
        weight[S] = 0;
        vector<vector<int>> adj_mat(V, vector<int>(V, INT_MAX)); //Weight Matrix
        for (int i = 0; i < V; i++)
        {
            adj_mat[i][i] = 0;
            for (int j = 0; j < adj[i].size(); j++)
                adj_mat[i][adj[i][j][0]] = adj[i][j][1];
        }
        while (!pq.empty())
        {
            auto p = pq.top();
            int u = p.second;
            int wt = p.first;
            pq.pop();
            for (int i = 0; i < adj_mat[u].size(); i++)
            {
                if (adj_mat[u][i] != INT_MAX && weight[i] > wt + adj_mat[u][i])
                {
                    weight[i] = wt + adj_mat[u][i];
                    pq.push({weight[i], i});
                }
            }
        }
        return weight;
    }
};