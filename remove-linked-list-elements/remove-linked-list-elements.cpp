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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *head2 = new ListNode(-1);
        
        auto p = head2;
        auto q = head;
        while(p&&q)
        {
            while(q&&q->val==val)
            {
                q=q->next;
            }
                p->next = q;
            
            p = p->next;
            if(p)
            q = p->next;
        }
        
        
        
        return head2->next;
    }
};