/* Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

Example 1:
Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:

Example 2:


Input: nums = [1,3]
Output: [3,1]
Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in a strictly increasing order. */

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

//My naive
class Solution
{
public:
    TreeNode *solve(vector<int> &a, int l, int r)
    {
        if (l > r)
            return NULL;
        int mid = l + (r - l) / 2;
        TreeNode *root = new TreeNode(a[mid]);
        root->left = solve(a, l, mid - 1);
        root->right = solve(a, mid + 1, r);
        return root;
    }

    TreeNode *sortedArrayToBST(vector<int> &a)
    {

        int r = a.size() - 1;
        int l = 0;
        int mid = l + (r - l) / 2;
        TreeNode *root = new TreeNode(a[mid]);
        root->left = solve(a, l, mid - 1);
        root->right = solve(a, mid + 1, r);
        return root;
    }
};

// We can also de this
class Solution
{
public:
    TreeNode *solve(vector<int> &a, int l, int r)
    {
        if (l > r)
            return NULL;
        int mid = l + (r - l) / 2;
        TreeNode *root = new TreeNode(a[mid]);
        root->left = solve(a, l, mid - 1);
        root->right = solve(a, mid + 1, r);
        return root;
    }

    TreeNode *sortedArrayToBST(vector<int> &a)
    { 
        if(a.size()==0) return NULL;
        return solve(a,0,a.size()-1)  ;
    }
};
