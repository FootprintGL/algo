

/*
 * get/put需要移动元素，题目要求常数复杂度，可以考虑哈希表 + 双链表
 */
struct DLinkNode {
    int key;
    int value;
    DLinkNode *prev;
    DLinkNode *next;
    DLinkNode() : key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkNode(int _key, int _value) : key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
    unordered_map<int, DLinkNode*> cache;
    /* 引入dummy指针方便处理 */
    DLinkNode *head;
    DLinkNode *tail;
    int size;
    int capacity;

public:
    LRUCache(int _cap) : capacity(_cap), size(0) {
        head = new DLinkNode();
        tail = new DLinkNode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (!cache.count(key))
            return -1;
        DLinkNode *node = cache[key];
        movetohead(node);
        return node->value;
    }

    void put(int key, int value) {
        if (cache.count(key)) {
            /* key存在 */
            DLinkNode *node = cache[key];
            node->value = value;
            movetohead(node);
        } else {
            /* key不存在 */
            DLinkNode *node = new DLinkNode(key, value);
            cache[key] = node;
            addtohead(node);
            size++;
            if (size > capacity) {
                DLinkNode *removed = removetail();
                cache.erase(removed->key);
                delete(removed);
                size--;
            }
        }
    }

    void addtohead(DLinkNode *node) {
        node->next = head->next;
        node->prev = head;
        head->next = node;
        node->next->prev = node;
    }

    void removenode(DLinkNode *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    DLinkNode* removetail() {
        DLinkNode *node = tail->prev;
        removenode(node);
        return node;
    }

    void movetohead(DLinkNode *node) {
        removenode(node);
        addtohead(node);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
