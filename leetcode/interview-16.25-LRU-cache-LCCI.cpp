



class LRUCache {
public:
    /* LRU容量 */
    int cap;
    /* 存放缓存数据 - 头部放最新访问元素，尾部放最早访问元素 */
    list<pair<int, int>> cache;
    /* 哈希表用来查找key在缓存中的位置 */
    unordered_map<int, list<pair<int, int>>::iterator> tbl;

    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        auto it = tbl.find(key);

        if (it == tbl.end())
        /* 不再缓存中 */
            return -1;

        auto target_pair_it = it->second;
        pair<int, int> tmp = {target_pair_it->first, target_pair_it->second};
        /* 移除缓存中key，再加到链表头部 */
        cache.erase(target_pair_it);
        cache.push_front(tmp);
        /* 更新哈希表中key的位置 */
        tbl[key] = cache.begin();

        return it->second->second;
    }

    void put(int key, int value) {
        auto it = tbl.find(key);

        if (it == tbl.end()) {
            /* 新key - 加到链表头部 */
            cache.push_front({key, value});
            tbl[key] = cache.begin();
            if (cache.size() > cap) {
                /* 超出缓存容量，删除尾部的元素 */
                auto tmppair = cache.back();
                int tmpkey = tmppair.first;
                cache.pop_back();
                tbl.erase(tmpkey);
            }
        } else {
            /* 老key */
            auto target_pair_it = it->second;
            pair<int, int> tmp = {target_pair_it->first, value};
            /* 移除缓存中key，再加到链表头部 */
            cache.erase(target_pair_it);
            cache.push_front(tmp);
            /* 更新哈希表中key的位置 */
            tbl[key] = cache.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
