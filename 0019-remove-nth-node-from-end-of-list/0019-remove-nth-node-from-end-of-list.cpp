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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr) return nullptr;
        if (head->next == nullptr) return nullptr;
        ListNode* temp = head;
        int count = 0;
        while(temp!=nullptr){
            count++;
            temp = temp->next;
        }
        temp = head;
        int idx = count-n;
        
        if(idx == 0){
            if(head->next != nullptr){
                head = head->next;
                return head;
            }else{
                return nullptr;
            }
        }
        for(int i{1};i<idx;i++){
            temp = temp->next;
        }
        if(idx>0 && temp->next != nullptr && temp != nullptr){
            temp->next= temp->next->next;
        }
        return head;
    }
};