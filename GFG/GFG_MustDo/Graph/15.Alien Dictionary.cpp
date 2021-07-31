/* Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. Find the order of characters in the alien language.
Note: Many orders may be possible for a particular test case, thus you may return any valid order and output will be 1 if the order of string returned by the function is correct else 0 denoting incorrect string returned.
 

Example 1:

Input: 
N = 5, K = 4
dict = {"baa","abcd","abca","cab","cad"}
Output:
1
Explanation:
Here order of characters is 
'b', 'd', 'a', 'c' Note that words are sorted 
and in the given language "baa" comes before 
"abcd", therefore 'b' is before 'a' in output.
Similarly we can find other orders.
Example 2:

Input: 
N = 3, K = 3
dict = {"caa","aaa","aab"}
Output:
1
Explanation:
Here order of characters is
'c', 'a', 'b' Note that words are sorted
and in the given language "caa" comes before
"aaa", therefore 'c' is before 'a' in output.
Similarly we can find other orders.
 

Your Task:
You don't need to read or print anything. Your task is to complete the function findOrder() which takes  the string array dict[], its size N and the integer K as input parameter and returns a string denoting the order of characters in the alien language.


Expected Time Complexity: O(N + K)
Expected Space Compelxity: O(K)


Constraints:
1 ≤ N, M ≤ 300
1 ≤ K ≤ 26
1 ≤ Length of words ≤ 50 */

class Solution
{
public:
    void dfs(int u, vector<int> adj[], vector<bool> &visited, stack<char> &st)
    {
        if (visited[u])
            return;
        visited[u] = true;
        for (int v : adj[u])
        {
            if (!visited[v])
                dfs(v, adj, visited, st);
        }
        st.push(u + 'a');
    }
    string topoSort(int V, vector<int> adj[])
    {
        vector<bool> visited(V, false);
        stack<char> st;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
                dfs(i, adj, visited, st);
        }
        string s = "";
        while (!st.empty())
        {
            s += st.top();
            st.pop();
        }
        return s;
    }

    string findOrder(string dict[], int N, int K)
    {
        vector<int> adj[K];
        for (int i = 0; i < N - 1; i++)
        {
            for (int j = 0; j < min(dict[i].size(), dict[i + 1].size()); j++)
            {
                if (dict[i][j] != dict[i + 1][j])
                {
                    adj[dict[i][j] - 'a'].push_back(dict[i + 1][j] - 'a');
                    break;
                }
            }
        }
        return topoSort(K, adj);
    }
};