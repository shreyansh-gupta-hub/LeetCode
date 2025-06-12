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
private:
static bool DoInvert3(ListNode* previous, ListNode* current, const int i, const int k, ListNode** lastNode, ListNode** nextNode){
        if (i == k){
            *lastNode = previous;
            *nextNode = current;
            return true;
        }
        if (current->next == nullptr && i < k - 1){
            *lastNode = nullptr;
            *nextNode = nullptr;
            return false;
        }
        const auto tmp = current->next == nullptr
            ? DoInvert3(current, nullptr, i + 1, k, lastNode, nextNode)
            : DoInvert3(current, current->next, i + 1, k, lastNode, nextNode);
        if (!tmp){
            return false;
        }
        current->next = previous;
        return true;
    }
    static bool DoInvert3FirstRun(ListNode* previous, const int k, ListNode** next_node){
        if (previous->next->next == nullptr && k >= 2){
            next_node = nullptr;
            return false;
        }
        ListNode* lastNode = nullptr;
        if (!DoInvert3(previous->next, previous->next->next, 1, k, &lastNode, next_node)){
            return false;
        }
        previous->next->next = *next_node;
        previous->next = lastNode;
        return true;
    }
public:
    ListNode* reverseKGroup(ListNode* beg, int k) {
        if (k == 1){
            return beg;
        }
        ListNode n0(-1, beg);
        auto node = &n0;
        while (true){
            const auto nodeToUseForTheNextRun = node->next;
            ListNode* nextNode = nullptr;
            const auto res = DoInvert3FirstRun(node, k, &nextNode);

            if (!res || nextNode == nullptr)
            {
                break;
            }
            node = nodeToUseForTheNextRun;
        }
        return n0.next;
    }
};