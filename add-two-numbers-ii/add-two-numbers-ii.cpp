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
    ListNode *reverse(ListNode *head)
    {
        auto p=head;
        auto q=p->next;
        int c=1;
        while(q)
        {
            auto temp = q->next;
            if(c==1)
            p->next = NULL;
            q->next = p;
            p=q;
            q=temp;
            c++;
        }
        head = p;
        return head;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        auto ans = new ListNode(-1);
        auto p=ans;
        int sum=0,carry=0;
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
        if(carry)
            p->next = new ListNode(carry);
        return reverse(ans->next);
    }
};