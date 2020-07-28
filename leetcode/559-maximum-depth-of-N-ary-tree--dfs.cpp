

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if (root == NULL)
            return 0;
        int size = root->children.size();
        vector<int> depth(size, 0);
        int maxdep = 0;
        //cout << "root: " << root << " size: " << size << endl;
        //cout << "children: " << endl;
        for (int i = 0; i < size; i++) {
            depth[i] = maxDepth(root->children[i]);
            //cout << i << ": " << depth[i] << " " << maxdep << endl;
            if (depth[i] > maxdep)
                maxdep = depth[i];
        }
        return maxdep + 1;
    }
};
