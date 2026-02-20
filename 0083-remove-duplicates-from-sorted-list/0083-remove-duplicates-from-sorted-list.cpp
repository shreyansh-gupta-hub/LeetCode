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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp  = head;
        ListNode* prev  = new ListNode(0);
        prev->next = head;
        if(head==NULL || head->next==NULL) return head;
        while(temp!=NULL){
            ListNode* curr = temp;
            while(curr!=NULL && curr->next!=NULL && curr->next->val == curr->val){
                curr = curr->next;
                if(temp == head){
                    ListNode* newHead = new ListNode(0);
                    newHead->next = curr;
                    head = newHead->next;
                }
                prev->next = curr;
            }
            if(prev->next ==temp) prev= prev->next;
            temp = temp->next;
            
        }
        return head;
    }
};