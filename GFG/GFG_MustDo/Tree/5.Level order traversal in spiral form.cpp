/* Complete the function to find spiral order traversal of a tree. For below tree, function should return 1, 2, 3, 4, 5, 6, 7.

Example 1:

Input:
      1
    /   \
   3     2
Output:1 3 2

Example 2:

Input:
           10
         /     \
        20     30
      /    \
    40     60
Output: 10 20 30 60 40 
Your Task:
The task is to complete the function findSpiral() which takes root node as input parameter and returns the elements in spiral form of level order traversal as a list. The newline is automatically appended by the driver code.
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
0 <= Number of nodes <= 105
0 <= Data of a node <= 105 */

vector<int> findSpiral(Node *root)
{
    vector<int> v;
    if (!root)
        return v;
    queue<Node *> q;
    q.push(root);
    bool turn = false;
    while (!q.empty())
    {
        int cnt = q.size();
        vector<int> level;
        while (cnt--)
        {
            Node *n = q.front();
            q.pop();
            level.push_back(n->data);
            if (n->left)
                q.push(n->left);
            if (n->right)
                q.push(n->right);
        }

        if (turn)
        {
            for (int i = 0; i < level.size(); i++)
            {
                v.push_back(level[i]);
            }
        }
        else
        {
            for (int i = level.size() - 1; i >= 0; i--)
            {
                v.push_back(level[i]);
            }
        }
        turn = !turn;
    }
    return v;
}