

class Solution {
public:
    struct Node {
        Node *next[2] = {nullptr};
    };

    int findMaximumXOR(vector<int>& nums) {
        /* 前缀树 */
        Node *root = new Node();
        Node *p;

        /* 插入构造前缀树 */
        for (auto &num : nums) {
            p = root;
            for (int i = 30; i >= 0; i--) {
                int t = (num >> i) & 1;
                if (!p->next[t])
                    p->next[t] = new Node();
                p = p->next[t];
            }
        }

        /* 搜索最大异或值 */
        int res = 0;
        for (auto &num : nums) {
            int tmp = 0;
            p = root;
            for (int i = 30; i >= 0; i--) {
                int t = (num >> i) & 1;
                if (p->next[!t]) {
                    p = p->next[!t];
                    tmp += (1 << i);
                } else {
                    p = p->next[t];
                }
            }
            res = max(res, tmp);
        }

        return res;
    }
};



class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        /*
         * 贪心
         * 从左向右依次尝试尽可能使每一位为1
         * 如果a ^ b = c, 则有a ^ c = b
         */
        unordered_set<int> prefix;
        int res = 0, mask = 0;

        for (int i = 30; i >= 0; i--) {
            /* 计算前缀掩码 */
            mask = mask | (1 << i);
            /* 前缀放入哈希表 */
            prefix.clear();
            for (auto &num : nums) {
                prefix.insert(num & mask);
            }

            /* 假设第i位为1 */
            int temp = res | (1 << i);
            for (auto &p : prefix) {
                if (prefix.count(p ^ temp)) {
                    /* 第i位有可能为1 */
                    res = temp;
                    break;
                }
            }
        }

        return res;
    }
};
