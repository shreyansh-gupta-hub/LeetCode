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
    ListNode* findMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow= slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    int pairSum(ListNode* head) {
        if (!head) return 0;
        if(head->next->next == NULL) return (head->val + head->next->val);
        ListNode* left = head;
        ListNode* mid = findMid(head);
        ListNode* right = reverseList(mid);
        int sum{0};
        int max{INT_MIN};
        while (left != NULL && right != NULL && left != right && right->next != left) {
            sum = left->val + right->val;
            if(sum>max){
                max = sum;
            }
            left = left->next;
            right = right->next;
        }
        return max;
    }
};