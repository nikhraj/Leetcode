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
    ListNode* oddEvenList(ListNode* head) {
        if(!head)
            return NULL;
        int i=0;
        unordered_map <int,ListNode *> m;
        
        auto p=head;
        while(p)
        {
            m[i++]=p;
            p=p->next;
        }
        if(i<=2)
            return head;
        p=head;
        int j=2;
        while(j<i)
        {
            p->next=m[j];
            p=p->next;
            j+=2;
        }
        j=1;
        while(j<i)
        {
            p->next=m[j];
            p=p->next;
            j+=2; 
        }
        p->next=NULL;
        return head;
    }
};