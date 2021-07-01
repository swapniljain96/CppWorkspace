// Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    unordered_map<int, int> m;
    int i = 0;
    TreeNode *subTree(vector<int> &pre, int l, int r)
    {
        if (l > r)
            return NULL;
        TreeNode *cur = new TreeNode(pre[i++]);
        if (l == r)
            return cur;
        int mid = m[cur->val];
        cur->left = subTree(pre, l, mid - 1);
        cur->right = subTree(pre, mid + 1, r);
        return cur;
    }
    TreeNode *buildTree(vector<int> &pre, vector<int> &in)
    {   i = 0;
        for (int i = 0; i < in.size(); i++)
        {
            m[in[i]] = i;
        }
        TreeNode *root = subTree(pre, 0, in.size() - 1);
        return root;
    }
};