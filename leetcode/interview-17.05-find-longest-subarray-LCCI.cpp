

class Solution {
public:
    vector<string> findLongestSubarray(vector<string>& array) {
        vector<string> res;
        unordered_map<int, int> tbl;
        int n = array.size(), i;
        int start = -2, end = -2, pre = 0;

        /* array为空 */
        if (n == 0)
            return res;
        
        /*
         * 前缀和 - 数字看成-1，字母看成1
         * 求最长子数组，tbl存放第一次出现某个前缀和的坐标
         * 如果i, j位置的前缀和相等，则(i,j]区间字母和数字相等
         * 为了方便处理，引入哨兵tbl[0] = -1
         */
        tbl[0] = -1;
        for (i = 0; i < n; i++) {
            if ((array[i][0] >= 'a' && array[i][0] <= 'z') ||
                (array[i][0] >= 'A' && array[i][0] <= 'Z')) {
                /* 字母+1 */
                pre += 1;
            } else {
                /* 数字-1 */
                pre -= 1;
            }

            if (tbl.count(pre) == 0) {
                /* 第一次出现 - 保存index */
                tbl[pre] = i;
            } else {
                /* 计算并更新最大子数组区间 */
                if (i - tbl[pre] > end - start) {
                    start = tbl[pre];
                    end = i;
                }
            }
        }

        //cout << start << " " << end << endl;

        /* 构建结果 */
        if (start != -2) {
            for (int i = start + 1; i <= end; i++)
                res.push_back(array[i]);
        }

        return res;
    }
};


/* 超时 - O(n^2) */
class Solution {
public:
    vector<string> findLongestSubarray(vector<string>& array) {
        vector<string> res;
        int start, maxlen = 0, cnt = 0;
        int lcnt = 0, dcnt = 0;
        int n = array.size(), i, j;
        vector<int> lettercnt(n, 0);

        /* array为空 */
        if (n == 0)
            return res;

        /* lettercnt[i]表示array中0～i元素里字母的个数 - 前缀和 */
        for (i = 0; i < n; i++) {
            if ((array[i][0] >= 'a' && array[i][0] <= 'z') ||
                (array[i][0] >= 'A' && array[i][0] <= 'Z')) {
                    cnt++;
            }
            lettercnt[i] = cnt;
        }

        /* 暴力搜索字母和数字相等的子数组 */
        for (i = 0; i < n - 1; i++) {
            /* 只有长度为偶数的子数组才能满足条件 */
            for (j = i + 1; j < n; j += 2) {
                /* lcnt - i~j中字母的个数 */
                lcnt = lettercnt[j];
                if (i - 1 >= 0)
                    lcnt -= lettercnt[i - 1];
                /* dcnt - i~j中数字的个数 */
                dcnt= j - i + 1 - lcnt;
                if (lcnt == dcnt) {
                    if (maxlen < lcnt + dcnt) {
                        maxlen = lcnt + dcnt;
                        start = i;
                    }
                }
            }
        }

        /* 构建结果 */
        if (maxlen != 0) {
            for (int i = start; i < start + maxlen; i++)
                res.push_back(array[i]);
        }

        return res;
    }
};
