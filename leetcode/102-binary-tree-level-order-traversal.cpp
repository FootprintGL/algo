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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> row;
        list<TreeNode *> qu;
        TreeNode *p;

        /*
         * BFS - 迭代算法
         * 常规BFS用一位数组存放遍历结果，该题用二维数组存放每一层的数据
         * 需要在每一层最后push一个空指针，用来标记该层结束，进入下一层
         */
        qu.push_back(root);
        qu.push_back(NULL);
        p = root;

        while (p && !qu.empty()) {
            /* 左右孩子分别入队 */
            if (p != NULL) {
                if (p->left)
                    qu.push_back(p->left);
                if (p->right)
                    qu.push_back(p->right);
            }

            /* 保存当前节点数据 */
            row.push_back(p->val);
            qu.pop_front();
            p = qu.front();

            /* 当前层结束 */
            if (p == NULL) {
                /* 移除队列头部标记NULL指针 */
                qu.pop_front();
                /* 添加标记NULL指针到队列尾部 */
                qu.push_back(NULL);
                if (row.size()) {
                    /* 保存当前层数据 */
                    res.push_back(row);
                    /* 清空临时变量row，准备处理下一层数据 */
                    row.clear();
                }
                /* 结束条件 - 如果队列中有且只有一个NULL，表示遍历完成，结束循环 */
                p = qu.front();
            }
        }

        return res;
    }
};
