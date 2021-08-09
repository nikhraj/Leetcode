/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map <ListNode *,int> m;
        
        auto p = headA;
        while(p)
        {
            m[p]++;
            p=p->next;
        }
        p=headB;
        while(p)
        {
            if(m.count(p))
                return p;
            p=p->next;
        }
        
        
        return NULL;
    }
};