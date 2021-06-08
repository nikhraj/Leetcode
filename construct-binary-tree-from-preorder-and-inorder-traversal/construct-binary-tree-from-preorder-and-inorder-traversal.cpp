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
    unordered_map <int,int> m;
    
    TreeNode * dfs(vector <int> &preorder, int l,int r,int i)
    {
        if(l>r||i>preorder.size())
        {
            return NULL;
        }
        TreeNode *temp = new TreeNode(preorder[i]);
        int index = m[temp->val];
        temp->left = dfs(preorder,l,index-1,i+1);
        temp ->right = dfs(preorder,index+1,r,i-l+index+1);
        
        return temp;
    }
    
    TreeNode* buildTree(vector <int>& preorder, vector<int>& inorder) {
        if(inorder.size()==0)
            return NULL;
        for(int i=0;i<inorder.size();i++)
        {
            m[inorder[i]]=i;
        }
        
        
        return dfs(preorder,0,preorder.size()-1,0);
        
        
    }
};