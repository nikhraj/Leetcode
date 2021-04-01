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
    bool isPalindrome(ListNode* head) {
        unordered_map <int,int> m;
        
        int i=0;
        while(head)
        {
            m[i++]=head->val;
            head=head->next;
        }
        int j=i-1;
        i=0;
        
        while(i<j)
        {
            if(m[i++]!=m[j--])
                return false;
        }
        return true;
    }
    
};