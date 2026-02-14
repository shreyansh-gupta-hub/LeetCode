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
    ListNode* deleteMiddle(ListNode* head){
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* vslow = NULL;
        if(head == NULL) return head;
        if (head->next  == NULL) return NULL;
        if (head->next->next  == NULL){
            head->next=NULL;
            return head;
        };
        if(fast->next==NULL || fast->next->next==NULL ){
            ListNode* newhead = head->next;
            return newhead;
        }
        while(fast != NULL && fast->next != NULL && fast->next->next!=NULL){
            if(vslow == NULL){
                vslow= head;
            }else{
                vslow = vslow->next;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast!=NULL && fast->next==NULL){
            vslow->next = vslow->next->next;
            return head;
        }

        slow->next = slow->next->next;
        return head;
    }
};