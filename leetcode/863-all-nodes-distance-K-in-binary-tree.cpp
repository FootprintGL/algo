

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
    vector<int> res;
    int k;
    TreeNode *target;

    /* 把子树深度为depth的节点加入结果 */
    void addsubtree(TreeNode *root, int depth) {
        if (root == nullptr)
            return;

        if (depth == 0)
            res.push_back(root->val);

        //cout << root << " " << root->val << " " << depth << " " << res.size() << endl;

        addsubtree(root->left, depth - 1);
        addsubtree(root->right, depth - 1);
    }

    /* 计算root到target的距离 */
    int dfs(TreeNode *root) {
        if (root == nullptr) {
            return -1;
        }
        /*
         * 如果target是根节点，则结果为深度为K的节点
         * 如果target在左子树且深度为L，结果为右子树上深度为K - L - 2的节点
         * 如果target在右子树且深度为L，结果为左子树上深度为K - L - 2的节点
         */
        if (root == target) {
            addsubtree(root, k);
            return 0;
        } else {
            int left = dfs(root->left);
            int right = dfs(root->right);
            //cout << root << " : " << root->val << " " << left << " " << right << endl;

            if (left != -1) {
                /* target在左子树 */
                if (left + 1 == k)
                /* 到左儿子的距离为left，则到当前节点的距离为left + 1 */
                    res.push_back(root->val);
                /* 到左儿子的距离为left，结果为到右儿子深度为k - left - 2的节点，跨国当前节点和右儿子两个节点 */
                addsubtree(root->right, k - left - 2);
                return left + 1;
            } else if (right != -1) {
                /* target在右子树 */
                if (right + 1 == k)
                /* 到左儿子的距离为right，则到当前节点的距离为right + 1 */
                    res.push_back(root->val);
                /* 到右儿子的距离为left，结果为到左儿子深度为k - left - 2的节点，跨国当前节点和左儿子两个节点 */
                addsubtree(root->left, k - right - 2);
                return right + 1;
            } else {
                return -1;
            }
        }

        return -1;
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        k = K;
        this->target = target;
        dfs(root);
        return res;
    }
};
