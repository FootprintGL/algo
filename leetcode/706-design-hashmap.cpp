


class Bucket {
public:
    vector<pair<int, int>> container;

    Bucket() {
    }

    int get(int key) {
        for (auto &[k, v] : container) {
            if (k == key)
                return v;
        }

        return -1;
    }

    void update(int key, int value) {
        //cout << key << " " << value << endl;
        for (auto &[k, v] : container) {
            if (k == key) {
                //cout << k << "-" << v << endl;
                v = value;
                return;
            }
        }

        container.push_back({key, value});
    }

    void del(int key) {
        for (int i = 0; i < container.size(); i++) {
            if (container[i].first == key)
                container.erase(container.begin() + i);
        }
    }
};

class MyHashMap {
public:
    int keyspace;
    vector<Bucket> hashtbl;

    /** Initialize your data structure here. */
    MyHashMap() {
        /* 质数且每个Bucket不能映射太多 */
        keyspace = 2069;
        hashtbl.resize(keyspace);
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        return hashtbl[key % keyspace].update(key, value);
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        return hashtbl[key % keyspace].get(key);
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        return hashtbl[key % keyspace].del(key);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
