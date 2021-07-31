/* Serialization is to store a tree in an array so that it can be later restored and Deserialization is reading tree back from the array. 
Now your task is to complete the function serialize which stores the tree into an array A[ ] and deSerialize which deserializes the array to tree and returns it.
Note: The structure of tree must be maintained.

Example 1:

Input:
      1
    /   \
   2     3
Output: 2 1 3
Example 2:

Input:
         10
       /    \
      20    30
    /   \
   40  60
Output: 40 20 60 10 30
Your Task:
The task is to complete two function serialize which takes the root node of the tree as input and stores the tree into an array and deSerialize which deserializes the array to the original tree and returns the root of it.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= Number of nodes <= 1000
1 <= Data of a node <= 1000 */

class Solution
{
public:
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int>
    serialize(Node *root)
    {
        vector<int> A;
        if (!root)
            return A;
        queue<Node *> q;
        q.push(root);
        Node *temp = new Node(-1);
        while (!q.empty())
        {
            Node *node = q.front();
            A.push_back(node->data);
            q.pop();
            if (node->data == -1)
            {
                continue;
            }

            if (node->left)
                q.push(node->left);
            else
                q.push(temp);

            if (node->right)
                q.push(node->right);
            else
                q.push(temp);
        }
        return A;
    }

    //Function to deserialize a list and construct the tree.
    Node *deSerialize(vector<int> &A)
    {
        if (A.size() == 0)
            return NULL;
        Node *root = new Node(A[0]);
        queue<Node *> queue;
        queue.push(root);
        int i = 1;
        while (!queue.empty() && i < A.size())
        {
            Node *currNode = queue.front();
            queue.pop();

            int currVal = A[i];

            if (currVal != -1)
            {
                currNode->left = new Node(currVal);
                queue.push(currNode->left);
            }
            i++;
            if (i >= A.size())
                break;
            currVal = A[i];

            if (currVal != -1)
            {
                currNode->right = new Node(currVal);
                queue.push(currNode->right);
            }
            i++;
        }
        return root;
    }
};