
class Solution {
public:
    void dump(vector<int> &tmp) {
        for (auto &t : tmp)
            cout << t << " ";
        cout << endl;
    }

    /* 计算v1,v2公共前缀的长度 */
    int getlen(vector<int> &v1, vector<int> &v2) {
        for (int i = 0; i < v1.size(); i++) {
            if (v1[i] != v2[i])
                return i;
        }

        return v1.size();
    }

    /* 过程模拟 */
    void magic(vector<int> &tmp, int start, int k) {
        /* 辅助数组 */
        vector<int> up(tmp.begin() + start, tmp.end());
        int j = start;
/*
        cout << start << " " << k << endl;
        dump(tmp);
        cout << endl;
*/
        for (int i = 0; i < up.size(); i++) {
            /* 提取偶数部分 - 1，3，5，... */
            if (i % 2)
                tmp[j++] = up[i];
        }

        for (int i = 0; i < up.size(); i++) {
            /* 提取奇数部分 - 0，2，4，...*/
            if (i % 2 == 0)
                tmp[j++] = up[i];
        }

        if (tmp.size() - start + 1 <= k)
        /* 剩下牌数小于等于k, 全部拿走 */
            return;
        else
        /* 拿走k张，继续处理 */
            magic(tmp, start + k, k);
    }

    bool isMagic(vector<int>& target) {
        int n = target.size(), k;
        vector<int> tmp(n, 0);

        /*
         * 第一次模拟后和target相比，k的值只能为公共前缀的长度len
         * 取k=len进行模拟，检查结果是否为target
         */
        for (int i = 0; i < n; i++)
            tmp[i] = i + 1;
            
        /* 第一次洗牌 */
        magic(tmp, 0, tmp.size());
        /* 找出公共前缀长度k */
        k = getlen(tmp, target);

        if (k == 0)
        /* 没有公共前缀 */
            return false;
        /* 并模拟洗牌全过程 */
        magic(tmp, k, k);

        if (getlen(tmp, target) == target.size())
        /* 公共前缀长度等于target的长度 - 找到k可以获得魔术取数排列 */
            return true;

        return false;
    }
};



/* 超时 */
class Solution {
public:
    bool same(vector<int> &v1, vector<int> &v2) {
        for (int i = 0; i < v1.size(); i++) {
            if (v1[i] != v2[i])
                return false;
        }

        return true;
    }

    void dump(vector<int> &tmp) {
        for (auto &t : tmp)
            cout << t << " ";
        cout << endl;
    }

    /* 过程模拟 */
    void magic(vector<int> &tmp, int start, int k) {
        /* 辅助数组 */
        vector<int> up(tmp.begin() + start, tmp.end());
        int j = start;
/*
        cout << start << " " << k << endl;
        dump(tmp);
        cout << endl;
*/
        for (int i = 0; i < up.size(); i++) {
            /* 提取偶数部分 - 1，3，5，... */
            if (i % 2)
                tmp[j++] = up[i];
        }

        for (int i = 0; i < up.size(); i++) {
            /* 提取奇数部分 - 0，2，4，...*/
            if (i % 2 == 0)
                tmp[j++] = up[i];
        }

        if (tmp.size() - start + 1 <= k)
        /* 剩下牌数小于等于k, 全部拿走 */
            return;
        else
        /* 拿走k张，继续处理 */
            magic(tmp, start + k, k);
    }

    bool isMagic(vector<int>& target) {
        int n = target.size();
        vector<int> tmp(n, 0);

        for (int i = 0; i < n; i++)
            tmp[i] = i + 1;

        /* 尝试k: 1 -> n */
        for (int i = 1; i <= n; i++) {
            vector<int> t = tmp;
            magic(t, 0, i);
            if (same(t, target))
            /* 找到k可以获得魔术取数排列 */
                return true;
        }

        return false;
    }
};
