/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> listOfDepth(TreeNode* tree) {
        vector<ListNode *> res;
        queue<TreeNode *> qu;
        /* 引入dummp头节点，方便处理 */
        ListNode *dummy = new ListNode(0), *p;
        TreeNode *cur;
        int size;

        if (tree == NULL)
            return res;
        
        /* 广度优先搜索 */
        qu.push(tree);
        while (!qu.empty()) {
            size = qu.size();
            p = dummy;
            for (int i = 0; i < size; i++) {
                cur = qu.front();
                qu.pop();
                p->next = new ListNode(cur->val);
                p = p->next;
                if (cur->left)
                    qu.push(cur->left);
                if (cur->right)
                    qu.push(cur->right);
            }
            res.push_back(dummy->next);
        }

        return res;
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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> listOfDepth(TreeNode* tree) {
        vector<ListNode *> res;
        queue<TreeNode *> qu;
        ListNode *head, *p;
        TreeNode *cur;
        int size;

        if (tree == NULL)
            return res;

        /* 广度优先搜索 */
        qu.push(tree);
        while (!qu.empty()) {
            size = qu.size();
            for (int i = 0; i < size; i++) {
                cur = qu.front();
                qu.pop();
                if (i == 0) {
                    head = new ListNode(cur->val);
                    p = head;
                } else {
                    p->next = new ListNode(cur->val);
                    p = p->next;
                }
                if (cur->left)
                    qu.push(cur->left);
                if (cur->right)
                    qu.push(cur->right);
            }
            res.push_back(head);
        }

        return res;
    }
};
