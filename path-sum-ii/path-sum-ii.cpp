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
    vector <vector <int>> ans;
    int s;
    void dfs(TreeNode *root,int sum,vector <int> v)
    {
        if(!root)
            return;
        v.push_back(root->val);
        sum+=root->val;
        if(sum==s&&!root->left&&!root->right)
            ans.push_back(v);
        
        dfs(root->left,sum,v);
        dfs(root->right,sum,v);
    }
    
    vector <vector<int>> pathSum(TreeNode* root, int targetSum) {
        s=targetSum;
        dfs(root,0,{});
        return ans;    
    }
};