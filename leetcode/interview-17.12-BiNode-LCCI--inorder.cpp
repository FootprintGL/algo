

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* convertBiNode(TreeNode* root) {
        if (root == NULL)
            return root;
        /*
         * 中序遍历
         * pre记录前驱节点, pre->right指向当前节点
         * 当前节点左指针为NULL, pre指向当前节点
         */
        TreeNode *head = new TreeNode(0);
        TreeNode *pre = head;
        stack<TreeNode *> stk;
        TreeNode *cur = root;

        while (cur || !stk.empty()) {
            /* 左儿子入栈 */
            while (cur) {
                stk.push(cur);
                cur = cur->left;
            }
            /* 访问当前节点 */
            cur = stk.top();
            stk.pop();
            /* 当前节点左儿子设为NULL */
            cur->left = NULL;
            /* 当前节点链入链表 */
            pre->right = cur;
            /* 更新pre为当前节点 */
            pre = cur;
            /* 处理右子树 */
            cur = cur->right;
        }

        return head->right;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* dfs(TreeNode *root, TreeNode *prev) {
        //cout << root << " " << prev << endl;
        if (root) {
            prev = dfs(root->left, prev);
            root->left = NULL;
            prev->right = root;
            prev = root;
            prev = dfs(root->right, prev);
        }

        return prev;
    }

    TreeNode* convertBiNode(TreeNode* root) {
        /*
         * 中序遍历
         * 引入哨兵指针
         * pre记录前驱节点, pre->right指向当前节点
         * 当前节点左指针为NULL, pre指向当前节点
         */
        TreeNode *head = new TreeNode(0);
        dfs(root, head);
        return head->right;
    }
};
