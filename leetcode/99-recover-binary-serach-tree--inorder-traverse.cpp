



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
    TreeNode *x;
    TreeNode *y;
    TreeNode *pre;

public:
    void helper(TreeNode *root) {
        if (root == NULL)
            return;
        helper(root->left);
        if (pre != NULL && pre->val > root->val) {
            if (x == NULL)
                x = pre;
            y = root;
        }
        pre = root;
        helper(root->right);
    }

    /*
     * 中序遍历
     * 二叉搜索树的中序遍历为排序数据
     * pre 记录前中序遍历一个节点，如果pre和当前节点构成逆序对则更新x,y
     * 题目指出有两个被交换，则中序遍历会有1个或2个逆序对
     * 中序遍历并检测逆序对位置x,y, 最后交换x，y的值即可
     */
    void recoverTree(TreeNode* root) {
        x = NULL;
        y = NULL;
        pre = NULL;
        helper(root);
        if (x && y) {
            int tmp = x->val;
            x->val = y->val;
            y->val = tmp;
        }
    }
};


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
    vector<int> nums;

public:
    void helper(TreeNode *root, bool gen) {
        if (root == NULL)
            return;
        helper(root->left, gen);
        if (gen) {
            nums.push_back(root->val);
        } else {
            root->val = nums[0];
            nums.erase(nums.begin());
        }
        helper(root->right, gen);
    }

    /*
     * 中序遍历
     * 二叉搜索树的中序遍历结果为有序数组
     * 1. 中序遍历保存数据到nums
     * 2. 对数组进行排序
     * 3. 中序遍历数组，把排序后的数组依次赋值
     */
    void recoverTree(TreeNode* root) {
        helper(root, true);
        sort(nums.begin(), nums.end());
        helper(root, false);
    }
};
