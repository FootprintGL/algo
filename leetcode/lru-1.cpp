class LRUCache {
public:
    LRUCache(int capacity) {
        max = capacity;
    }
    
    int get(int key) {
        int tmp = -1;
        unordered_map<int, int>::const_iterator got = cache.find(key);
        if (got != cache.end()) {
            /* move to the tail */
            tmp = got->second;
            cache.erase(key);
            cache.insert({key, tmp});
        }
        cout << "get " << endl;
        for (auto &x: cache) {
            cout << x.first << ": " << x.second << endl;
        }
        return tmp;
    }
    
    void put(int key, int value) {
        unordered_map<int, int>::const_iterator got = cache.find(key);
        
        if (got != cache.end()) {
            /* key exist */
            cache[key] = value;            
        } else {
            /* new key */
            if (cache.size() < max)
                /* space available */
                cache.insert({key, value});
            else {
                /* remove the first and add to the tail */
                cache.erase(cache.begin());
                cache.insert({key, value});
            }
        }
        cout << "put " << endl;
        for (auto &x: cache) {
            cout << x.first << ": " << x.second << endl;
        }
    }
private:
    /* max num of key */
    int max;
    /* cache with unordered_map */
    unordered_map<int, int> cache;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
