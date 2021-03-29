

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
    /*
     * 初始化一个空栈，用于模拟二叉树的中序遍历
     * 定义一个辅助函数inorderleft,将给定节点的所有左节点添加到栈中，直到没有左子节点为止
     * 第一次调用next函数，必须返回二叉搜索树的最小元素,然后模拟递归向前移动一步，即移到下一个小的元素
     * 栈的顶部始终包含next需要返回的元素，hasnext需要判断stack是否为空
     */
    stack<TreeNode *> stk;

    void inorderleft(TreeNode *root) {
        while (root != nullptr) {
            stk.push(root);
            root = root->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        inorderleft(root);
    }

    int next() {
        TreeNode *next = stk.top();
        stk.pop();

        if (next->right)
            inorderleft(next->right);

        return next->val;
    }

    bool hasNext() {
        return !stk.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
