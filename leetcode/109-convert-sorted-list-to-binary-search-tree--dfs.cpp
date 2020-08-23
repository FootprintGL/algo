

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode *helper(vector<int> &nums, int left, int right) {
        if (left == right)
            return new TreeNode(nums[left]);
        else if (left > right)
            return nullptr;
        
        int mid = left + (right - left) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = helper(nums, left, mid - 1);
        root->right = helper(nums, mid + 1, right);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr)
            return nullptr;

        vector<int> nums;
        /* 转化有序为有序数组 */
        ListNode *p = head;
        while (p != nullptr) {
            nums.push_back(p->val);
            p = p->next;
        }

        TreeNode *root = helper(nums, 0, nums.size() - 1);

        return root;
    }
};
