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
    pair<int,ListNode*> SizeofLL(ListNode* head){
        ListNode* temp = head;
        int count{0};
        while(temp->next!=NULL){
            temp = temp->next;
            count++;
        }
        count++;
        return {count, temp};
    }
    ListNode* rotateLL(ListNode* head,int cnt){
        int count = 1;
        ListNode* temp =head;
        while(count < cnt){
            temp = temp->next;
            count++;
        }
        
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;
        pair<int,ListNode*> res= SizeofLL(head);
        int LLSize = res.first;
        ListNode* EndNode =res.second;
        k%=LLSize;
        if(k==0) return head;
        EndNode->next = head;
        
        ListNode* newTail = rotateLL(head, LLSize - k);
        ListNode* newHead = newTail->next;
        newTail->next=NULL;
        head = newHead;
        return head;
    }
};