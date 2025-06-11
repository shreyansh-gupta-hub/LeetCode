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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);  // Dummy node to simplify head management
        ListNode* current = dummyHead;
        int carry = 0;

        // Loop until both lists are exhausted and carry is 0
        while (l1 != nullptr || l2 != nullptr || carry > 0) {
            int sum = carry;

            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            int digit = sum % 10;

            current->next = new ListNode(digit);
            current = current->next;
        }

        return dummyHead->next;
    }
};