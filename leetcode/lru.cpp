using namespace std;

#include<iostream>
#include<unordered_map>

typedef class LRUCache LRUCache;

class LRUCache {
public:
    LRUCache(int capacity) {
        max = capacity;
	cout << "max ";
        cout << max << endl;
    }

    int get(int key) {
	int res = -1;
	cout << "get - key ";
        cout << key << endl;
        if (cache.find(key) == cache.end()) {
	    res = cache[key];
            /* move to the tail */
	    cache.erase(key);
	    cashe.emplace(key, res);
        }

	return res;
    }

    void put(int key, int value) {
	cout << "put key ";
        cout << key << endl;
	cout << "put value ";
	cout << value << endl;
        /* new key */
        if (cache.find(key) == cache.end()) {
            if (cache.size() <= max)
                /* space available */
                cache.emplace(key, value);
            else {
                /* remove the first and add to the tail */
                cache.erase(cache.begin());
                cache.emplace(key, value);
            }
        } else {
            /* key exist */
            cache[key] = value;
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

int main()
{
    LRUCache *cache = new LRUCache(2);
    cache->put(1, 1);
    cache->put(2, 2);
    cache->get(1);       // 返回  1
    /*
    cache->put(3, 3);    // 该操作会使得密钥 2 作废
    cache->get(2);       // 返回 -1 (未找到)
    cache->put(4, 4);    // 该操作会使得密钥 1 作废
    cache->get(1);       // 返回 -1 (未找到)
    cache->get(3);       // 返回  3
    cache->get(4);       // 返回  4
*/
    return 0;
}

