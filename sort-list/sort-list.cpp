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
    ListNode* sortList(ListNode* head) {
        if(!head)
            return NULL;
        multiset <pair<int,ListNode *>> m;
        
        while(head)
        {
            m.insert({head->val,head});
            head=head->next;
        }
        ListNode * p=new ListNode(-1);
        head=p;
        for(auto [x,y]:m)
        {
            p->next=y;
            p=p->next;
        }
        p->next=NULL;
        return head->next;
    }
};