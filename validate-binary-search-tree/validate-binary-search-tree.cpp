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
    int ans=true;
    long prev = LONG_MIN;
    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        
        ans&=isValidBST(root->left);
        if(root->val<=prev)
            return false;
        prev=root->val;
        
        ans&=isValidBST(root->right);
        return ans;
        
    }
};