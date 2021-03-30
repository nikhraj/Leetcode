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
    bool dfs(TreeNode *root)
    {
       if(!root)
            return true;
        int c=0;
       if(dfs(root->left))
       {
           c++;
           root->left=NULL;
       }
       if(dfs(root->right))
       {
           c++;
            root->right=NULL;
       }
        
        if(root->val==0&&c==2)
        {
            return true;   
        }
        return false;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        TreeNode *parent=new TreeNode(-1);
        parent->left=root;
        if(dfs(root))
        {
            return NULL;
        }
        
        return parent->left;
    }
};