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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode *> st;
        TreeNode *p;
        /* 迭代算法 */

        /* 空树 */
        if (!root)
            return res;

        st.push(root);

        while (!st.empty()) {
            p = st.top();
            res.push_back(p->val);
            st.pop();
            
            if (p->right) {
                st.push(p->right);
            }

            if (p->left) {
                st.push(p->left);
            }
        }

        return res;
        //////////////////////////////////////////////////////
        //递归算法
        /* 局部变量是不行的，递归调用每个函数都有自己的局部变量，
        最上层res只会有一个元素 */
        /*vector<int> res;*/
        /* 递归算法 */
        /*
        struct TreeNode *p = root;
        if (p) {
            res.push_back(p->val);
            if (p->left)
                preorderTraversal(p->left);
            if (p->right)
                preorderTraversal(p->right);
        }
        */

        /* 打印vector res结果 */
        /*
        cout << "res.size " << res.size() << endl;
        for (auto c : res)
            cout << c << endl;
        
        return res;
        */
    }
};
