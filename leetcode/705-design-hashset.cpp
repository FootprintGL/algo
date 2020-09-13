

class MyHashSet {
public:
    int data[1000001];

    /** Initialize your data structure here. */
    MyHashSet() {
        for (auto &d : data)
            d = -1;
    }

    void add(int key) {
        data[key] = 0;
    }

    void remove(int key) {
        data[key] = -1;
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return data[key] == 0;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
