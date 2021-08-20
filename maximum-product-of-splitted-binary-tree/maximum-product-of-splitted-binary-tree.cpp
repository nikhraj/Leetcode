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
    long long sumi,ans=0;
    long long sum(TreeNode *root)
    {
        if(!root)
            return 0;
        return sum(root->left)+sum(root->right)+root->val;
        
    }
    
    long long dfs(TreeNode *root)
    {
        if(!root)
            return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        int sumii = left+right+root->val;
        ans=max(ans,(sumi-sumii)*sumii);
        
        return sumii;
    }
    int maxProduct(TreeNode* root) {
        sumi = sum(root);
        dfs(root);
        return (ans%int(1e9+7));
    }
};