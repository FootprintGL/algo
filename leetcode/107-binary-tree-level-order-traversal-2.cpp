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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> row;
        list<TreeNode *> qu;
        TreeNode *p;
        int i, n;

        /* BFS - n记录每一层节点数量，一次处理一层 */
        qu.push_back(root);
        p = root;
        while (p && !qu.empty()) {
            /* n记录没一层的节点数量 */
            n = qu.size();

            /* 一次处理一层： 保存当前层节点，下一层节点入队列 */
            for (i = 0; i < n; i++) {
                if (p->left)
                    qu.push_back(p->left);
                if (p->right)
                    qu.push_back(p->right);
                row.push_back(p->val);
                qu.pop_front();
                p = qu.front();
            }

            /* 保存当层数据 - 从头部插入来匹配预期结果 */
            res.emplace(res.begin(), row);

            /* 清空临时队列，准备处理下一层节点 */
            row.clear();
        }

        return res;
    }
};
