

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FindElements {
public:
    /* 哈希表加速查找 */
    unordered_set<int> cache;

    void dfs(TreeNode *root) {
        //cout << root->val << endl;
        cache.insert(root->val);

        if (root->left) {
            root->left->val = 2 * root->val + 1;
            dfs(root->left);
        }

        if (root->right) {
            root->right->val = 2 * root->val + 2;
            dfs(root->right);
        }
    }

    FindElements(TreeNode* root) {
        root->val = 0;
        dfs(root);
    }

    bool find(int target) {
        return cache.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
