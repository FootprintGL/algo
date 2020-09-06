
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    bool dfs(ListNode *head, TreeNode *root) {
        if (head == NULL)
            return true;

        if (root == nullptr || head->val != root->val)
            return false;

        return dfs(head->next, root->left) || dfs(head->next, root->right);

    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        if (root == nullptr)
            return false;
        return dfs(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    bool dfs(ListNode *head, TreeNode *root) {
        if (head == NULL)
            return true;

        if (root == nullptr || head->val != root->val)
            return false;

        return dfs(head->next, root->left) || dfs(head->next, root->right);

    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        if (root->val == head->val && dfs(head, root))
            return true;

        if (root->left && isSubPath(head, root->left))
            return true;

        if (root->right && isSubPath(head, root->right))
            return true;
        
        return false;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    bool dfs(ListNode *head, TreeNode *root) {
        if (head == NULL) {
            cout << "find" << endl;
            return true;
        }

        if (root == nullptr || head->val != root->val) {
            return false;
        }

        //cout << "dfs: " << head->val << " " << root->val << endl;

        if (dfs(head->next, root->left))
            return true;

        if (dfs(head->next, root->right))
            return true;

        return false;
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        //cout << "ispath: " << head->val << " " << root->val << endl;
        if (root->val == head->val && dfs(head, root)) {
            return true;
        }

        if (root->left && isSubPath(head, root->left))
            return true;

        if (root->right && isSubPath(head, root->right))
            return true;

        return false;
    }
};
