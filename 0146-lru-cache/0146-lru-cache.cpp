class LRUCache {
public:

    struct ListNode{
        int key;
        int val;
        ListNode* next;
        ListNode* prev;
        ListNode(int key,int val) : key(key), val(val),next(nullptr),prev(nullptr){}
    };

    void remove(ListNode* node){
        ListNode* pre = node->prev;
        ListNode* nex = node->next;
        pre->next = nex;
        nex->prev = pre; 
    }

    void insert(ListNode* node){
        ListNode* pre = right->prev;
        pre->next = node;
        right->prev = node;
        node->prev = pre;
        node->next = right;

    }

    int size;
    unordered_map<int,ListNode*> mp;
    ListNode* left;
    ListNode* right;

    LRUCache(int capacity) {
        size = capacity;
        left = new ListNode(0, 0);
        right = new ListNode(0, 0);
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if(mp.find(key)!= mp.end()){
            ListNode* node = mp[key];
            int value = node->val;
            remove(node);
            insert(node);
            return value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!= mp.end()){
            ListNode* node = mp[key];
            node->val = value;
            remove(node);
            insert(node);
        }
        else{
            ListNode* node = new ListNode(key,value);
            mp[key] = node;
            insert(node);
            if(mp.size()>size){
            mp.erase(left->next->key);
            remove(left->next);
            }
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */