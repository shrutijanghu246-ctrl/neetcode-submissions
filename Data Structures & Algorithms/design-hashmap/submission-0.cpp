struct ListNode {
    int key;
    int val;
    ListNode* next;
    
    ListNode(int k, int v) : key(k), val(v), next(nullptr) {}
};

class MyHashMap {
private:
    static const int SIZE = 1000;        
    vector<ListNode*> table;                

    int hash(int key) {
        return key % SIZE;             
    }

public:
    MyHashMap() {
        table.resize(SIZE, nullptr);     
    }
    
    void put(int key, int value) {
        int idx = hash(key);
        ListNode* curr = table[idx];
        while (curr) {
            if (curr->key == key) {
                curr->val = value;    
                return;
            }
            curr = curr->next;
        }
        ListNode* newNode = new ListNode(key, value);
        newNode->next = table[idx];     
        table[idx] = newNode;
    }
    
    int get(int key) {
        int idx = hash(key);
        ListNode* curr = table[idx];
        while (curr) {
            if (curr->key == key) return curr->val;
            curr = curr->next;
        }
        return -1;                     
    }
    
    void remove(int key) {
    int idx = hash(key);
    ListNode* curr = table[idx];
    ListNode* prev = nullptr;

    while (curr) {
        if (curr->key == key) {
            if (prev) {
                prev->next = curr->next;   // unlink from chain
            } else {
                table[idx] = curr->next;   // removing head node
            }
            delete curr;                   // free memory
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */