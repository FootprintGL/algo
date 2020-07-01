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
    /* 字符串转整数 */
    int stoi(string s) {
        int n = s.size();
        int res = 0;
        int i;

        for (i = 0; i < n; i++) {
            res = res * 10 + (s[i] - '0');
        }

        return res;
    }

    TreeNode* recoverFromPreorder(string S) {
        stack<TreeNode *> stk;
        TreeNode *p, *q, *root = NULL;
        int cur = 0, dep, n = S.size();
        int i = 0, j = 0;

        if (n == 0)
            return NULL;

        /* 提取根节点数据，创建根节点并入栈 */        
        for (j = 0; j < n; j++) 
            if (S[j] == '-')
                break;
        root = (TreeNode *) new (TreeNode);
        root->val = stoi(S.substr(0, j));;
        stk.push(root);
        cur = 0;

        i = j;
        while (j < n) {
            /* 统计下一个节点深度 */
            i = j;
            dep = 0;
            while (j < n && S[j] == '-') {
                dep++;
                j++;
            }

            /* 提取数据建立节点，建立节点 */
            i = j;
            while (j < n && S[j] != '-') {
                j++;
            }
            q = (TreeNode *) new (TreeNode);
            q->val = stoi(S.substr(i, j - i));
            
            if (cur < dep) {
                /* 如果节点深度大于当前深度，节点为左儿子，压栈并更新当前深度 */
                stk.top()->left = q;
                stk.push(q);
                cur++;
            } else {
                /* 
                 * 如果节点深度小于等于当前深度，节点为右儿子，寻找父节点，持续弹栈
                 * 直到找到深度比dep小1的节点，即为父节点
                 */
                while (dep <= cur) {
                    stk.pop();
                    cur--;
                }
                /* 更新右儿子，入栈 */
                stk.top()->right = q;
                stk.push(q);
                cur++;
            }
        }

        return root;
    }
};
