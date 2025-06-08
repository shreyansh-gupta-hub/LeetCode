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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *tail = head;
        int size=0;
        while(tail != nullptr){
            tail = tail->next;
            size++;
        }
        size /= 2;
        ListNode *idx = head;
        for(int i=1; i< size; i++){
            idx = idx->next;
            
        }
        if(size ==0){
            return nullptr;
        }
        ListNode *temp2 = idx->next->next;
        idx->next = temp2;
        return head;
    }
};