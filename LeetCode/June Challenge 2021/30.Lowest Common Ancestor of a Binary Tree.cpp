// Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

// According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root)
            return root; // work for single node i.e.: root
        if (root == p || root == q)
            return root; // Base Case

        TreeNode *left = lowestCommonAncestor(root->left, p, q);   // if root is not the answer
        TreeNode *right = lowestCommonAncestor(root->right, p, q); //  goto left and right

        if (!left)
            return right; // if left not there return right
        if (!right)
            return left; // if right not there return left
        return root;     // if both not then return root
    }
};