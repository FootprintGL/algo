

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
    void countdepth(TreeNode *root, int depth, vector<int> &list) {
        if (root == nullptr)
            return;

        if (root->left == nullptr && root->right == nullptr) {
            /* 叶子节点 */
            list.push_back(depth);
            return;
        }
        countdepth(root->left, depth + 1, list);
        countdepth(root->right, depth + 1, list);
    }

    int countPairs(TreeNode* root, int distance) {
        /*
         * 后序遍历
         * 分别求所有叶子深度并保存到lefts和rights里，再计算左右子树的叶子和root
         * 连接起来的长度是否小于等于distance,是的话更新结果
         * 1 父节点到字节点的距离为1
         * 2 后序遍历, 返回这个节点到其下方所有叶子节点的距离
         * 3 将该节点左子树所有叶子节点和右子树所有叶子节点都凑个对
         * 4 然后将所有叶子节点不超过距离的返回
         */
        if (root == nullptr)
            return 0;

        vector<int> lefts;
        countdepth(root->left, 0, lefts);
        vector<int> rights;
        countdepth(root->right, 0, rights);

        int res = 0;
        for (auto &l : lefts) {
            for (auto &r : rights) {
                if (l + r + 2 <= distance)
                    res++;
            }
        }

        res += countPairs(root->left, distance);
        res += countPairs(root->right, distance);

        return res;
    }
};
