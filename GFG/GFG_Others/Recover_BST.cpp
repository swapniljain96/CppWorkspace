/* You are given the root of a binary search tree(BST), where exactly two nodes were swapped by mistake. Fix (or correct) the BST by swapping them back. Do not change the structure of the tree.
Note: It is guaranteed that the given input will form BST, except for 2 nodes that will be wrong. All changes must be reflected in the original linked list.
 
Example 1:
Input:
       10
     /    \
    5      8
   / \
  2   20
Output: 1
Explanation:
 
Example 2:

Input:
         11
       /    \
      3      17
       \    /
        4  10
Output: 1 
Explanation: 
By swapping nodes 11 and 10, the BST 
can be fixed.
Your Task:
You don't need to take any input. Just complete the function correctBst() that takes root node as parameter. The function should not return anything, all the changes must be done in the existing tree only. BST will then be checked by driver code and 0 or 1 will be printed.

Expected Time Complexity : O(n)
Expected Auxiliary Space : O(1)
 
Constraints:
1 <= Number of nodes <= 1000 */

class Solution
{
public:
    Node *f = NULL, *s = NULL;
    Node *prev = new Node(INT_MIN);
    void inorder(struct Node *root)
    {
        if (!root)
            return;

        inorder(root->left);

        if (!f && prev->data > root->data)
        {
            f = prev;
        }
        if (f && prev->data > root->data)
        {
            s = root;
        }
        prev = root;
        inorder(root->right);
    }

    void correctBST(struct Node *root)
    {
        inorder(root);
        swap(f->data, s->data);
    }
};
