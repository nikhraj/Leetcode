/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        auto p=head;
        
        
        while(p)
        {
            auto q=p->next;
            p->next=new Node(p->val,q,NULL);
            p=q;
        }
        
        p=head;
        while(p)
        {
            //cout<<p->val<<" ";
            p=p->next;
        }
        
        p=head;
        
        while(p)
        {
            if(p->random)   
                p->next->random = p->random->next;
            p=p->next->next;
        }
        p=head;
        auto head2 = new Node(-1,NULL);
        auto q=head2;
        while(p)
        {
            //cout<<p->val<<" ";
            auto prev=p;
            p=p->next;
            q->next=p;
            prev->next=p->next;
            q=q->next;
            p=p->next;
        }
        q=head2;
        while(q)
        {
            //cout<<q->val<<" ";
            q=q->next;
        }
        
        return head2->next;
    }
};