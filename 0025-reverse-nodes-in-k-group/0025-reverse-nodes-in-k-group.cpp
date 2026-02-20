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
    ListNode* reverse(ListNode*& head, ListNode* temp, int x){
        ListNode* sve = temp;
        ListNode* curr = temp;
        ListNode* prev = NULL;
        for (int i{0};i<x;i++){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        if(temp == head){
            head = prev;
        }
        sve->next = curr;
        
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* temp = head;
        ListNode* prevGroupTail = NULL;
        ListNode* nextGroupStart = NULL;
        while(temp!=NULL){
            ListNode* check = temp;
            int count = 0;
            while(count < k && check){
                check = check->next;
                count++;
            }
            if(count < k) break; 
            nextGroupStart = reverse(head, temp, k);
            if(prevGroupTail){
                prevGroupTail->next = nextGroupStart;
            }
            prevGroupTail = temp;
            temp = temp->next;
        }
        return head;
    }
};