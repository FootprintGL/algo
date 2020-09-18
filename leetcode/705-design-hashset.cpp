
class Bucket {
public:
    vector<int> container;

    void add(int key) {
        for (auto &k : container)
            if (k == key)
                return;
        container.push_back(key);
    }

    void remove(int key) {
        for (int i = 0; i < container.size(); i++)
            if (container[i] == key) {
                container.erase(container.begin() + i);
                return;
            }
    }

    bool contains(int key) {
        for (auto &k : container)
            if (k == key)
                return true;
        
        return false;
    }
};

class MyHashSet {
public:
    vector<Bucket> hashtbl;
    int keyspace;

    /** Initialize your data structure here. */
    MyHashSet() {
        keyspace = 2069;
        hashtbl.resize(keyspace);
    }
    
    void add(int key) {
        hashtbl[key % keyspace].add(key);
    }
    
    void remove(int key) {
        hashtbl[key % keyspace].remove(key);
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return hashtbl[key % keyspace].contains(key);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */


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
