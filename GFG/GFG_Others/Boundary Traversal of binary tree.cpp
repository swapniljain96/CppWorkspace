/* Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

Left boundary nodes: defined as the path from the root to the left-most node ie- the leaf node you could reach when you always travel preferring the left subtree over the right subtree. 
Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.
Reverse right boundary nodes: defined as the path from the right-most node to the root. The right-most node is the leaf node you could reach when you always travel preferring the right subtree over the left subtree. Exclude the root from this as it was already included in the traversal of left boundary nodes.
Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. 

Example 1:
Input:
        1
      /   \
     2     3    
   
Output: 1 2 3

Example 2:
Input:
          20
        /   \
       8     22
     /   \    \
    4    12    25
        /  \ 
       10   14 

Output: 20 8 4 10 14 25 22

Your Task:
This is a function problem. You don't have to take input. Just complete the function printBoundary() that takes the root node as input and returns an array containing the boundary values in anti-clockwise.
Expected Time Complexity: O(N). 
Expected Auxiliary Space: O(Height of the Tree).
Constraints:
1 ≤ Number of nodes ≤ 105
1 ≤ Data of a node ≤ 105 */

class Solution
{
public:
    vector<int> v;
    void printLeaves(struct Node *root)
    {
        if (!root)
            return;
        printLeaves(root->left);

        // Print it if it is a leaf node
        if (!(root->left) && !(root->right))
            v.push_back(root->data);

        printLeaves(root->right);
    }
    void printBoundaryLeft(struct Node *root)
    {
        if (!root)
            return;
        if (root->left)
        {

            // to ensure top down order, print the node
            // before calling itself for left subtree
            v.push_back(root->data);
            printBoundaryLeft(root->left);
        }
        else if (root->right)
        {
            v.push_back(root->data);
            printBoundaryLeft(root->right);
        }
        // do nothing if it is a leaf node, this way we avoid
        // duplicates in output
    }

    // A function to print all right boundary nodes, except a leaf node
    // Print the nodes in BOTTOM UP manner
    void printBoundaryRight(struct Node *root)
    {
        if (!root)
            return;

        if (root->right)
        {
            // to ensure bottom up order, first call for right
            // subtree, then print this node
            printBoundaryRight(root->right);
            v.push_back(root->data);
        }
        else if (root->left)
        {
            printBoundaryRight(root->left);
            v.push_back(root->data);
        }
        // do nothing if it is a leaf node, this way we avoid
        // duplicates in output
    }
    vector<int> printBoundary(Node *root)
    {
        if (!root)
            return {};
        v.push_back(root->data);
        printBoundaryLeft(root->left);
        printLeaves(root);
        printBoundaryRight(root->right);
        return v;
    }
};  