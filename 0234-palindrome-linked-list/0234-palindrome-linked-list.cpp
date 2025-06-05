class Solution {
public:
    ListNode* reversell(ListNode* head) {
        ListNode* prev = NULL;
        while (head != NULL) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) return true;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* secondHalf = reversell(slow);
        ListNode* copySecond = secondHalf;

        ListNode* firstHalf = head;
        while (secondHalf != NULL) {
            if (firstHalf->val != secondHalf->val) {
                reversell(copySecond);
                return false;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        reversell(copySecond);
        return true;
    }
};