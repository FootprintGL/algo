

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        /*
         * 1 每个节点后面创建一个新节点
         * 2 设置新节点的random指针
         * 3 分离两个链表
         */

        Node *cur = head, *clone;

        /* 每个节点后面添加一个clone节点 */
        while (cur) {
            clone = new Node(cur->val);
            clone->next = cur->next;
            cur->next = clone;
            cur = clone->next;
        }

        /* 设置random指针 */
        cur = head;
        while (cur) {
            if (cur->random) {
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }

        /* 分离链表 */
        Node *dummy = new Node(-1);
        cur = head;
        clone = dummy;
        while (cur) {
            clone->next = cur->next;
            clone = cur->next;
            cur->next = clone->next;
            cur = cur->next;
        }

        return dummy->next;
    }
};


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        /*
         * 哈希表
         * 哈希表维护元节点到复制节点的映射
         * 如果random指向的节点已经创建复制节点，直接更新random指针，否则创建新节点并更新哈系表
         */
        if (head == nullptr)
            return nullptr;

        /* 创建新的clone节点并放入哈希表 */
        unordered_map<Node *, Node *> tbl;
        Node *cur = head;
        while (cur) {
            tbl[cur] = new Node(cur->val);
            cur = cur->next;
        }

        /* 初始化clone节点的next和random指针 */
        cur = head;
        while (cur) {
            if (cur->next)
                tbl[cur]->next = tbl[cur->next];

            if (cur->random)
                tbl[cur]->random = tbl[cur->random];

            cur = cur->next;
        }

        return tbl[head];
    }
};


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    unordered_map<Node *, Node *> tbl;

public:
    Node *getnodecopy(Node *head) {
        if (head == nullptr)
            return nullptr;

        if (!tbl.count(head))
        /* 不存在clone节点，创建一个 */
            tbl[head] = new Node(head->val);

        return tbl[head];
    }

    Node* copyRandomList(Node* head) {
        /*
         * 哈希表
         * 哈希表维护元节点到复制节点的映射
         * 如果random指向的节点已经创建复制节点，直接更新random指针，否则创建新节点并更新哈系表
         */
        if (head == nullptr)
            return nullptr;

        /* 创建新的头节点 */
        Node *cur = head;
        Node *copy = new Node(head->val);
        tbl[cur] = copy;

        while (cur) {
            /* 获得next和random的clone节点 */
            copy->next = getnodecopy(cur->next);
            copy->random = getnodecopy(cur->random);
            /* 移到下一个节点 */
            cur = cur->next;
            copy = copy->next;
        }

        return tbl[head];
    }
};
