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
    bool isCousins(TreeNode* root, int x, int y) {
        queue <TreeNode *>q;
        q.push(root);
        while(!q.empty())
        {
            int s=q.size();
            bool c1=false;
            bool c2=false;
            while(s--)
            {
                auto p=q.front();
                q.pop();
                
                if(p->left&&p->right)
                {
                    if(p->left->val==x&&p->right->val==y||p->left->val==y&&p->right->val==x)
                        return false;
                }
                if(p->left)
                {
                    if(p->left->val==x)
                        c1=true;
                    if(p->left->val==y)
                        c2=true;
                    q.push(p->left);
                }
                if(p->right)
                {
                    if(p->right->val==x)
                        c1=true;
                    if(p->right->val==y)
                        c2=true;
                    q.push(p->right);
                }
            }
            if(c1&&c2)
                return true;
            
        }
        
        return false;
    }
};