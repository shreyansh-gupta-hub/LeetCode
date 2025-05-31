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
    ListNode* reverseList(ListNode* head) {
            ListNode* before = NULL;
            ListNode* curr = head;
            ListNode* after = NULL;
            while (curr != NULL) {
                after = curr->next;
                curr->next = before;
                before=curr;
                curr=after;
            }
            return before;
        }
};