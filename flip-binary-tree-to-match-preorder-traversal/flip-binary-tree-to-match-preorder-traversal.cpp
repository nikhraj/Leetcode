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
    vector <int> ans;
    vector <int> pre;
    int i=0;
    void dfs(TreeNode *root,TreeNode *parent)
    {
        if(!root)
        {
            i--;
            return;
        }
        if(root->val!=pre[i])
        {
            //cout<<root->val<<" "<<pre[i]<<endl;
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
        dfs(root->left,root);
        i++;
        dfs(root->right,root);
    }
    
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        pre=voyage;
        dfs(root,NULL);
        return ans;
    }
};