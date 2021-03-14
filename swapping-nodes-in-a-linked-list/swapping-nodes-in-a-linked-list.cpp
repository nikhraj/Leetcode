/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        if(!head)
            return NULL;
        map <int,ListNode*> m;
        int c=1;
        auto p=head;
        while(p)
        {
            m[c++]=p;
            p=p->next;
        }
        int temp=m[c-k]->val;
        m[c-k]->val=m[k]->val;
        m[k]->val=temp;
        
        
        return head;
    }
};