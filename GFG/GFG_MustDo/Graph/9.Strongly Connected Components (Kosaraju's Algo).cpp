/* Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, Find the number of strongly connected components in the graph.
 

Example 1:

Input:

Output:
3
Explanation:

We can clearly see that there are 3 Strongly
Connected Components in the Graph
Example 2:

Input:

Output:
1
Explanation:
All of the nodes are connected to each other.
So, there's only one SCC.
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function kosaraju() which takes the number of vertices V and adjacency list of the graph as inputs and returns an integer denoting the number of strongly connected components in the given graph.
 

Expected Time Complexity: O(V+E).
Expected Auxiliary Space: O(V).
 

Constraints:
1 ≤ V ≤ 5000
0 ≤ E ≤ (V*(V-1))
0 ≤ u, v ≤ N-1
Sum of E over all testcases will not exceed 25*106 */

class Solution
{
public:
    stack<int> st;
    void dfs2(int u, vector<int> adj[], vector<bool> &vis)
    {
        vis[u] = true;
        for (auto v : adj[u])
        {
            if (!vis[v])
                dfs2(v, adj, vis);
        }
    }
    void dfs1(int u, vector<int> adj[], vector<bool> &vis)
    {
        vis[u] = true;
        for (auto v : adj[u])
        {
            if (!vis[v])
                dfs1(v, adj, vis);
        }
        st.push(u);
    }

    int kosaraju(int V, vector<int> adj[])
    {
        vector<int> rev[V];
        for (int i = 0; i < V; i++)
        {
            for (auto x : adj[i])
            {
                rev[x].push_back(i);
            }
        }

        vector<bool> vis(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs1(i, adj, vis);
            } //dfs for populating the stack
        }

        for (int i = 0; i < V; i++)
            vis[i] = false;
        int com = 0;
        while (!st.empty())
        {
            int u = st.top();
            st.pop();
            if (!vis[u])
            {
                dfs2(u, rev, vis); //dfs for on reverse graph
                com++;
            }
        }
        return com;
    }
};