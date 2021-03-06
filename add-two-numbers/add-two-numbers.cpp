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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans = new ListNode(-1);
        auto p=ans;
        int carry=0,sum=0;
        while(l1||l2)
        {
            sum=0;
            if(l1)
                sum+=l1->val;
            if(l2)
                sum+=l2->val;
            sum+=carry;
            carry = sum/10;
            sum%=10;
            p->next = new ListNode(sum);
            p=p->next;
            if(l1)
            l1=l1->next;
            if(l2)
            l2=l2->next;
        }
        
        if(carry>0)
            p->next = new ListNode(carry);
        return ans->next;
    }
    
};