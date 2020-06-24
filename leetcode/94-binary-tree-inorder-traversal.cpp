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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode *> st;
        TreeNode *p;

        /* 迭代算法 */
        p = root;
        while (p != NULL || !st.empty()) {
            while (p != NULL) {
                /* 入栈 - 直到找到最左侧节点 */
                st.push(p);
                p = p->left;
            }
            /* 出栈 - 访问最左侧节点 */
            p = st.top();
            res.push_back(p->val);
            st.pop();
            p = p->right;
        }

        return res;
        
        /* 递归算法 
        struct TreeNode *p = root;
        if (p) {
            if (p->left)
                inorderTraversal(p->left);
            res.push_back(p->val);
            if (p->right)
                inorderTraversal(p->right);
        }

        return res;
        */
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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode *> st;
        TreeNode *p;

        /* 迭代算法 */
        if (!root)
            return res;
        
        st.push(root);
        while (!st.empty()) {
            p = st.top();
            while (p->left) {
                /* 入栈 - 直到找到最左侧节点 */
                st.push(p->left);
                //cout << "push: " << p->left << endl;
                p = st.top();
            }

            /* 出栈 - 访问最左侧节点 */
            p = st.top();
            res.push_back(p->val);
            st.pop();
            //cout << "pop: " << p << endl;

            if (p->right) {
                /* 入栈 - 如果有右儿子 */
                st.push(p->right);
                //cout << "push: " << p->right << endl;
            } else {
                while (!st.empty()) {
                    /* 出栈 - 直到找到有右儿子的节点 */
                    p = st.top();
                    res.push_back(p->val);
                    st.pop();
                    //cout << "pop: " << p << endl;
                    if (p->right) {
                        /* 入栈 - 找到有右儿子的节点 */
                        st.push(p->right);
                        //cout << "push: " << p->right << endl;
                        break;
                    }
                }
            }
        }

        return res;
        /* 递归算法 
        struct TreeNode *p = root;
        if (p) {
            if (p->left)
                inorderTraversal(p->left);
            res.push_back(p->val);
            if (p->right)
                inorderTraversal(p->right);
        }

        return res;
        */
    }
};
