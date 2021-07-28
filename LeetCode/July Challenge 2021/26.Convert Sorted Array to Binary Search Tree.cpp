/* Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

Example 1:
Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:

Example 2:
Input: nums = [1,3]
Output: [3,1]
Explanation: [1,3] and [3,1] are both a height-balanced BSTs.
 
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

// Method 1:
class Solution
{
public:
    TreeNode *solve(vector<int> &a, int l, int r)
    {
        if (l <= r)
        {
            int mid = l + (r - l) / 2;
            TreeNode *root = new TreeNode(a[mid]);
            root->left = solve(a, l, mid - 1);
            root->right = solve(a, mid + 1, r);
            return root;
        }
        return NULL;
    }
    TreeNode *sortedArrayToBST(vector<int> &a)
    {
        return solve(a, 0, a.size() - 1);
    }
};

// Method 2:
class Solution
{
public:
    TreeNode *sortedArrayToBST(vector<int> &a)
    {
        int n = a.size();
        if (n == 0)
            return NULL;
        if (n == 1)
            return new TreeNode(a[0]);

        int mid = n / 2;
        TreeNode *root = new TreeNode(a[mid]);
        vector<int> left(a.begin(), a.begin() + mid);
        vector<int> right(a.begin() + mid + 1, a.end());
        root->left = sortedArrayToBST(left);
        root->right = sortedArrayToBST(right);
        return root;
    }
};