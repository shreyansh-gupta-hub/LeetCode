class MyLinkedList{
public:
    struct Node{
        int val;
        Node *next;
        Node(int newVal){
            val = newVal;
            next = nullptr;
        }

        Node(int newVal, Node *ptr){
            val = newVal;
            next = ptr;
        }
    };
    Node *head;
    Node *tail;
    int listLen;
    MyLinkedList(){
        head = nullptr;
        tail = head;
        listLen = 0;
    }
    int get(int index){
        if (index < 0 || index > (listLen - 1))
            return -1;
        Node *currN = head;
        int idx = 0;
        while (currN != nullptr){
            if (idx == index)
                return currN->val;
            currN = currN->next;
            idx++;
        }
        return -1;
    }
    void addAtHead(int val){
        Node *newN = new Node(val, head);
        head = newN;
        if (listLen == 0)
            tail = newN;
        listLen++;
    }
    void addAtTail(int val){
        Node *newN = new Node(val);
        if (listLen > 0) tail->next = newN;
        tail = newN;
        if (listLen == 0){
            head = newN;
        }
        listLen++;
    }
    void addAtIndex(int index, int val){
        if (index < 0 || index > listLen) return;
        if (index == listLen) addAtTail(val);
        else if (index == 0) addAtHead(val);
        else{
            Node *ptr = head;
            Node *indexedNode = nullptr;
            Node *indexedPrevNode = nullptr;
            int countIdx = 0;
            while (ptr != nullptr){
                indexedPrevNode = indexedNode;
                indexedNode = ptr;
                if (countIdx == index)
                    break;
                ptr = ptr->next;
                countIdx++;
            }
            Node *newN = new Node(val, indexedNode);
            indexedPrevNode->next = newN;
            listLen++;
        }
    }
    void deleteAtIndex(int index){
        if (index < 0 || index > (listLen - 1)) return;
        if (index == 0){
            Node *curr = head;
            head = head->next;
            delete (curr);
            listLen--;
            return;
        }
        Node *ptr = head;
        Node *indexedNode = nullptr;
        Node *indexedPrevNode = nullptr;
        int countIdx = 0;
        while (ptr != nullptr){
            indexedPrevNode = indexedNode;
            indexedNode = ptr;
            if (countIdx == index) break;
            ptr = ptr->next;
            countIdx++;
        }
        indexedPrevNode->next = indexedNode->next;
        if (index == (listLen - 1)) tail = indexedPrevNode;
        delete (indexedNode);
        listLen--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

 /*
int main()
{
    MyLinkedList *obj = new MyLinkedList();
    obj->addAtHead(0);

    obj->addAtIndex(1, 4);

    obj->addAtTail(8);

    obj->addAtHead(5);

    obj->addAtIndex(4, 3);

    obj->addAtTail(0);

    obj->addAtTail(5);

    obj->addAtIndex(6, 3);

    obj->deleteAtIndex(7);

    obj->deleteAtIndex(5);

    obj->addAtTail(4);

    while (obj->head != nullptr)
    {
        cout << (obj->head->val) << " ";
        obj->head = obj->head->next;
    }
    cout << endl;
    return 0;
}
*/