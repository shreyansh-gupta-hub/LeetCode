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
    ListNode *removeDuplicates(ListNode *head) {
        // Your code here
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        if(head == NULL || head->next==NULL) return head;
        ListNode* prev = dummy;
        ListNode* curr = head; 
        while (curr != NULL) {
            if (curr->next != NULL && curr->val == curr->next->val) {
                int duplicateVal = curr->val;
                while (curr != NULL && curr->val == duplicateVal) {
                    ListNode* temp = curr;
                    curr = curr->next;
                    delete temp;
                }
                prev->next = curr;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        ListNode* newHead = dummy->next;
        delete dummy; 
        return newHead;
    }
    ListNode* deleteDuplicates(ListNode* head) {
        return removeDuplicates(head);
    }
};