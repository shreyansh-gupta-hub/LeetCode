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
    ListNode * deleteAllOccurOfX(ListNode* head_ref, int x) {
        while(head_ref != nullptr && head_ref->val == x) {
            ListNode* temp = head_ref;
            head_ref = head_ref->next;
            delete temp;
        }
        ListNode* current = head_ref;
        ListNode* prev = nullptr;

        while(current != nullptr) {
            if(current->val == x) {
                prev->next = current->next;
                delete current;
                current = prev->next;  // move forward
            } else {
                prev = current;
                current = current->next;
            }
        }
            return head_ref;
        }

    ListNode* removeElements(ListNode* head, int val) {
        return deleteAllOccurOfX(head,val);
    }
};