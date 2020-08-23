


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
class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == nullptr)
            return ;
        stack<TreeNode *> stk;
        TreeNode *prev = nullptr, *curr = nullptr;

        /*
         * 前序遍历 - 迭代算法
         * prev记录前一个节点，curr记录当前节点
         * 如果有左右字节点，先入栈右子节点，再入栈左字节点
         * prev为非空时，更新left指针为空指针，right为当前指针
         * 更新prev为curr，处理下一个节点
         */
        stk.push(root);
        while (!stk.empty()) {
            curr = stk.top();
            //cout << "pop: " << curr << endl;
            stk.pop();
            if (prev) {
                prev->left = nullptr;
                prev->right = curr;
            }
            if (curr->right) {
                stk.push(curr->right);
                //cout << "r-push: " << curr->right << endl;
            }
            if (curr->left) {
                stk.push(curr->left);
                //cout << "l-push: " << curr->left << endl;
            }
            //cout << prev << " " << curr << endl;
            prev = curr;
        }
    }
};
