

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
    /* 判断2棵树是否相等 */
    bool issame(TreeNode *s, TreeNode *t) {
        if (s == nullptr && t == nullptr)
            return true;

        if (s == nullptr || t == nullptr)
            return false;

        if (s->val != t->val)
            return false;

        return issame(s->left, t->left) && issame(s->right, t->right);
    }

    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (t == nullptr)
            return true;

        if (s == nullptr)
            return false;

        return issame(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
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
public:
    bool dfs(TreeNode *s, TreeNode *t) {
        //cout << s << " " << t << endl;
        if (s == nullptr && t == nullptr)
            return true;
        
        if ((s == nullptr && t != nullptr) || (s != nullptr && t == nullptr))
            return false;
        
        //cout << s << " " << s->val << " " << t << " " << t->val << endl;
        if (s->val == t->val) {
            return dfs(s->left, t->left) && dfs(s->right, t->right);
        }

        return false;
    }

    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s == nullptr && t == nullptr)
            return true;
        
        if ((s == nullptr && t != nullptr) || (s != nullptr && t == nullptr))
            return false;
        
        if (s->val == t->val) {
            if (dfs(s->left, t->left) && dfs(s->right, t->right))
                return true;
        }

        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};
