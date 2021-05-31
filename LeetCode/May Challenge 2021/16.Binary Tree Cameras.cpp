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
class Solution {
public:
    int res=0;
    int minCameraCover(TreeNode* root) {
        return (dfs(root)=="notCovered"?1:0)+res;
    }
    
    string dfs(TreeNode* root){
        if(root==NULL) return "covered";
        string left=dfs(root->left);
        string right=dfs(root->right);
        if(left=="notCovered" || right=="notCovered")
        { res++;
          return "havingCamera";
        }
        
        return left=="havingCamera" || right=="havingCamera"?"covered":"notCovered";
    }
};