/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        Node* curr = head;
        Node* ans = new Node(0);
        Node* i=ans;

        unordered_map<Node*, Node*> mp;
        while(curr){
            i->next = new Node(curr->val);
            mp[curr] = i->next;

            i = i->next;
            curr = curr->next;
        }
        curr = head;
        i = ans->next;
        while(curr){
            Node* x = curr->random;
            if( x != NULL)  i->random = mp[x];
            else{ i->random = nullptr;}
            i = i->next;
            curr = curr->next;
        }
        return ans->next;
    }
};