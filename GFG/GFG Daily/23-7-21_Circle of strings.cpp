/* Given an array of lowercase strings A[] of size N, determine if the strings can be chained together to form a circle.
A string X can be chained together with another string Y if the last character of X is same as first
character of Y. If every string of the array can be chained, it will form a circle.

For example, for the array arr[] = {"for", "geek", "rig", "kaf"} the answer will be Yes as the given strings can be chained as "for", "rig", "geek" and "kaf"


Example 1:

Input:
N = 3
A[] = { "abc", "bcd", "cdf" }
Output:
0
Explaination:
These strings can't form a circle 
because no string has 'd'at the starting index.
Example 2:

Input:
N = 4
A[] = { "ab" , "bc", "cd", "da" }
Output:
1
Explaination:
These strings can form a circle 
of strings.

Your Task:
You don't need to read input or print output. Your task is to complete the function isCircle() which takes the length of the array N and the array A as input parameters and returns 1 if we can form a circle or 0 if we cannot.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)


Constraints: 
1 ≤ N ≤ 104
1 ≤ Length of strings ≤ 20 */

class Solution
{
public:
    stack<int> st;
    void myDFS(vector<int> g[], int N, int i, bool vis[])
    {
        vis[i] = true;
        vector<int>::iterator it;
        for (it = g[i].begin(); it != g[i].end(); it++)
        {
            if (!vis[*it])
            {
                myDFS(g, N, *it, vis);
            }
        }
        st.push(i);
    }

    void revDFS(vector<int> tg[], int N, int i, bool vis[])
    {
        vis[i] = true;
        vector<int>::iterator it;
        for (it = tg[i].begin(); it != tg[i].end(); it++)
        {
            if (!vis[*it])
            {
                revDFS(tg, N, *it, vis);
            }
        }
    }

    int Kosaraju(vector<int> g[], vector<int> &in)
    {
        int N = 26;
        stack<int> newst;
        st = newst;
        bool *vis1 = new bool[N];
        bool *vis2 = new bool[N];
        for (int i = 0; i < N; i++)
        {
            vis1[i] = false;
            vis2[i] = false;
        }
        for (int i = 0; i < N; i++)
        {
            if (in[i])
                myDFS(g, N, i, vis1);
        }

        vector<int> tg[N];
        vector<int>::iterator it;
        int count = 0;
        // Reverse the graph g and store it in tg
        for (int i = 0; i < N; i++)
        {
            for (it = g[i].begin(); it != g[i].end(); it++)
            {
                tg[*it].push_back(i);
            }
        }
        while (!st.empty())
        {
            int node = st.top();
            st.pop();
            if (!vis2[node])
            {
                count++;
                revDFS(tg, N, node, vis2);
            }
        }
        return count;
    }

    int isCircle(int N, vector<string> str)
    {
        vector<int> adj[26];
        vector<int> in(26, 0), out(26, 0);
        for (int i = 0; i < N; i++)
        {
            int len = str[i].length();
            adj[str[i][0] - 'a'].push_back(str[i][len - 1] - 'a');
            out[str[i][0] - 'a']++;
            in[str[i][len - 1] - 'a']++;
        }

        if (in == out && Kosaraju(adj, in) == 1)
        {
            return 1;
        }

        return 0;
    }
};