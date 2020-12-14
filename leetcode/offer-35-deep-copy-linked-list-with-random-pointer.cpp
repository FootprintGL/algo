


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
        /* 原地copy */
        if (head == NULL)
            return head;

        /* copy节点放在原节点后面： 1->2->3->... => 1 -> 1' -> 2 -> 2' -> 3 -> 3'-> ... */
        Node *cur, *copy;
        for (cur = head; cur != NULL; cur = cur->next->next) {
            copy = new Node(cur->val);
            copy->next = cur->next;
            cur->next = copy;
        }

        /* 处理copy节点random指针 */
        for (cur = head; cur != NULL; cur = cur->next->next) {
            if (cur->random != NULL) {
                cur->next->random = cur->random->next;
            }
        }

        /* 分离copy节点和原节点 */
        Node *copyhead, *temp;
        copyhead = head->next;
        for (cur = head; cur != NULL && cur->next != NULL;) {
            temp = cur->next;
            cur->next = temp->next;
            cur = temp;
        }

        return copyhead;
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
        if (head == NULL)
            return head;

        /* 哈希表 */
        unordered_map<Node *, Node *> tbl;
        Node *cur;

        /* 复制节点建立映射关系 */
        for (cur = head; cur != NULL; cur = cur->next) {
            tbl[cur] = new Node(cur->val);
        }

        /* 构建链表 */
        for (cur = head; cur != NULL; cur = cur->next) {
            tbl[cur]->next = tbl[cur->next];
            tbl[cur]->random = tbl[cur->random];
        }

        return tbl[head];
    }
};
