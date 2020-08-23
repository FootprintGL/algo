


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node *, Node *> lookup;
    void dump(Node *node) {
        queue<Node *> qu;
        unordered_set<Node *> myset;
        Node *p;

        qu.push(node);
        myset.insert(node);
        while (!qu.empty()) {
            p = qu.front();
            qu.pop();
            cout << p << ": " << endl;
            for (auto nei : p->neighbors) {
                cout << nei << " ";
                if (myset.find(nei) == myset.end()) {
                    myset.insert(nei);
                    qu.push(nei);
                }
            }
            cout << endl;
        }
    }

    Node* cloneGraph(Node* node) {
        if (node == NULL)
            return node;
        /*
         * DFS
         * 哈希表维护原图节点和copy节点的映射关系
         */
        if (lookup.find(node) != lookup.end())
            return lookup[node];

        lookup[node] = new Node(node->val);
        for (auto nei : node->neighbors) {
            lookup[node]->neighbors.push_back(cloneGraph(nei));
        }

        return lookup[node];
    }
};



/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dump(Node *node) {
        queue<Node *> qu;
        unordered_set<Node *> myset;
        Node *p;

        qu.push(node);
        myset.insert(node);
        while (!qu.empty()) {
            p = qu.front();
            qu.pop();
            cout << p << ": " << endl;
            for (auto nei : p->neighbors) {
                cout << nei << " ";
                if (myset.find(nei) == myset.end()) {
                    myset.insert(nei);
                    qu.push(nei);
                }
            }
            cout << endl;
        }
    }

    Node* cloneGraph(Node* node) {
        unordered_map<Node *, Node *> lookup;
        queue<Node *>qu;
        Node *p;

        if (node == NULL)
            return node;
        //dump(node);
        //cout << endl << endl;
        /*
         * BFS
         * 哈希表维护原图节点和copy节点的映射关系
         */
        qu.push(node);
        lookup[node] = new Node(node->val);
        while (!qu.empty()) {
            p = qu.front();
            qu.pop();
            for (auto nei : p->neighbors) {
                if (lookup.find(nei) == lookup.end()) {
                    lookup[nei] = new Node(nei->val);
                    qu.push(nei);
                }
                lookup[p]->neighbors.push_back(lookup[nei]);
            }
        }

        //dump(lookup[node]);
        return lookup[node];
    }
};
