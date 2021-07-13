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
    ListNode* reverseKGroup(ListNode* head, int k) {
        unordered_map <int,ListNode*> m;
        
        int i=0;
        auto p=head;
        while(p)
        {
            m[i++]=p;
            p=p->next;
        }
        int n=i;
        ListNode *ans = new ListNode(-1);
        p=ans;
        
        for(int j=0;j<=n-k;j+=k)
        {
            for(int i=k+j-1;i>=j;i--)
            {
                //cout<<i<<" ";
                p->next=m[i];
                p=p->next;
            }
           // cout<<endl;
        }
        p->next=NULL;
        int some = n%k;
        if(some)
        {
            p->next = m[n-some];
        }
        
        
        return ans->next;
        
    }
};