


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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> res;
        TreeNode *p;

        /* 空树 */
        if (!root)
            return {};
        /*
         * 迭代算法
         * 压入父节点后压入null节点用来判断父节点
         */
        st.push(root);
        while (!st.empty()) {
            p = st.top();
            if (!p) {
                /* NULL弹栈 */
                st.pop();
                /* 保存父节点元素 */
                p = st.top();
                res.push_back(p->val);
                st.pop();
            } else {
                /* NULL入栈 - 标记父节点 */
                st.push(NULL);
                /* 右儿子入栈 */
                if (p->right)
                    st.push(p->right);
                /* 左儿子入栈 */
                if (p->left)
                    st.push(p->left);
            }
        }

        return res;

        /* 递归算法
        struct TreeNode *p = root;
        if (p) {
            if (p->left)
                postorderTraversal(p->left);
            if (p->right)
                postorderTraversal(p->right);
            res.push_back(p->val);
        }

        return res;*/
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
    vector<int> res;
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode *p;

        /* 错误解法，无法判断父节点 - 会造成死循环
        p = root;
        while (p || !st.empty()) {
            while (p) {
                st.push(p);
                p = p->left;
            }

            p = st.top();
            if (p->right) {
                p = p->right;
            } else {
                res.push_back(p->val);
                st.pop();
                while (!st.empty()) {
                    p = st.top();
                    if (p->right) {
                        p = p->right;
                        break;
                    } else {
                        res.push_back(p->val);
                        st.pop();
                    }
                }
            }
        }

        return res;
        */

        /* 递归算法
        struct TreeNode *p = root;
        if (p) {
            if (p->left)
                postorderTraversal(p->left);
            if (p->right)
                postorderTraversal(p->right);
            res.push_back(p->val);
        }

        return res;*/
    }
};
