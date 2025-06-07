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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
         ListNode* temp=head;
         int len=0;
         while(temp){
            temp=temp->next;
            len++;
         }
         if(len==1 && n==len) return NULL;
         ListNode* curr=head;   
         ListNode* prev=curr;  
         while(curr){
            if(len==n){
                prev->next=curr->next;
                break;
            }
            if(prev!=curr)
             prev=prev->next;
             curr=curr->next;
             len--;
         }
       if(prev==curr) return head->next;
        return head;








    }
};
