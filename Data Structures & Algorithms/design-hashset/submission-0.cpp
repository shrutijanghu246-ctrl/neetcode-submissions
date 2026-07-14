class MyHashSet {
public:
    vector<bool> nums;
    MyHashSet() {
        nums = vector<bool>(1000001, false);
    }
    
    void add(int key) {
        nums[key] = true;
    }
    
    void remove(int key) {
        nums[key] = false;
    }
    
    bool contains(int key) {
        if(nums[key]) return true;
        else return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */