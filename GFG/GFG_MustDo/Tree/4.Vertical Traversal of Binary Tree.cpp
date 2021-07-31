/* Given a Binary Tree, find the vertical traversal of it starting from the leftmost level to the rightmost level.
If there are multiple nodes passing through a vertical line, then they should be printed as they appear in level order traversal of the tree.

Example 1:

Input:
           1
         /   \
       2       3
     /   \   /   \
   4      5 6      7
              \      \
               8      9           
Output: 
4 2 1 5 6 3 8 7 9 
Explanation:

Example 2:

Input:
       1
    /    \
   2       3
 /    \      \
4      5      6
Output: 4 2 1 5 3 6
Your Task:
You don't need to read input or print anything. Your task is to complete the function verticalOrder() which takes the root node as input parameter and returns an array containing the vertical order traversal of the tree from the leftmost to the rightmost level. If 2 nodes lie in the same vertical level, they should be printed in the order they appear in the level order traversal of the tree.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 <= Number of nodes <= 3*104 */

class Solution
{
public:
    vector<int> verticalOrder(Node *root)
    {
        vector<int> v;
        if (!root)
            return v;
        multimap<int, int> m;
        queue<pair<Node *, int>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            Node *t = q.front().first;
            int h = q.front().second;
            q.pop();
            m.insert({h, t->data});
            if (t->left)
                q.push({t->left, h - 1});
            if (t->right)
                q.push({t->right, h + 1});
        }

        for (auto x : m)
        {
            v.push_back(x.second);
        }
        return v;
    }
};