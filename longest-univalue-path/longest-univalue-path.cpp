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
    int ans=0;
    int dfs(TreeNode *root)
    {
        if(!root)
            return 0;
        int l=dfs(root->left),r=dfs(root->right);
        if(root->left)
        {
            if(root->left->val==root->val)
                l=l+1;
            else
                l=0;
        }
        if(root->right)
        {
            if(root->right->val==root->val)
                r=r+1;
            else
                r=0;
        }
        ans=max(ans,l+r);
        return max(l,r);
        
    }
    int longestUnivaluePath(TreeNode* root) {
        
        dfs(root);
        return ans;
    }
};