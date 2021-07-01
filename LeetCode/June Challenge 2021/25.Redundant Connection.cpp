// In this problem, a tree is an **undirected graph** that is connected and has no cycles.

// You are given a graph that started as a tree with `n` nodes labeled from `1` to `n`, with one additional edge added. The added edge has two **different** vertices chosen from `1` to `n`, and was not an edge that already existed. The graph is represented as an array `edges` of length `n` where `edges[i] = [ai, bi]` indicates that there is an edge between nodes `ai` and `bi` in the graph.

// Return *an edge that can be removed so that the resulting graph is a tree of* `n` *nodes*. If there are multiple answers, return the answer that occurs last in the input.
class Solution
{
public:
    int parent[2005];
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {   int n = edges.size();
        //make each node parent of itself
        for (int i = 0; i < n + 1; i++)
        {   parent[i] = i;    }
        for (auto x : edges)
        {   if (find_set(x[0]) == find_set(x[1]))
                return x;
            union_set(x[0], x[1]);
        }
        return {};
    }

    int find_set(int node)
    {  while (parent[node] != node)
        { node = parent[node];   }
        return node;
    }

    void union_set(int i, int j)
    {   int iRoot = find_set(i);
        int jRoot = find_set(j);
        if (iRoot != jRoot)
        {   parent[jRoot] = iRoot;  }
    }
};