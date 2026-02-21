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
    int SizeofLL(ListNode* head){
        ListNode* temp = head;
        int count{0};
        while(temp!=NULL){
            temp = temp->next;
            count++;
        }
        return count;
    }
    ListNode* rotateonce(ListNode* head){
        ListNode* temp =head;
        ListNode* prev = NULL;
        while(temp->next!=NULL){
            ListNode* next = temp->next;
            prev = temp;
            temp = next;
        }
        prev->next=NULL;
        temp->next = head;
        head = temp;
        return head;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;
        int LLSize = SizeofLL(head);
        k%=LLSize;
        for (int i{0};i<k;i++){
            head = rotateonce(head);
        };
        return head;
    }
};