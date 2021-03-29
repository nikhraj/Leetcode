class Solution {
public:
    vector <int> ans;
    int i=0;
    void dfs(TreeNode *root,TreeNode *parent,vector <int> &pre)
    {
        if(!root)
        {
            i--;
            return;
        }
        if(root->val!=pre[i])
        {
            if(parent&&parent->right&&parent->right->val==pre[i])
            {
                auto temp=parent->left;
                parent->left=parent->right;
                parent->right=temp;
                ans.push_back(parent->val);
                root=parent->left;
            }
            else
            {
                ans={-1};
                return;
            }
        }
        i++;
        dfs(root->left,root,pre);
        i++;
        dfs(root->right,root,pre);
    }
    
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        dfs(root,NULL,voyage);
        return ans;
    }
};