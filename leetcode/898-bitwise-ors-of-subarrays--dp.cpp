/* 超时 - myset改为unordered_set能通过 */
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        unordered_set<int> myset;
        int i, j, curmask = 0, premask = 0;
        
        /* 暴力循环 + 减枝 - 或操作只会增加结果中二进制1的个数 */
        for (i = 0; i < A.size(); i++) {
            curmask = 0;
            for (j = i; j >= 0; j--) {
                curmask |= A[j];
                myset.insert(curmask);
                /* ==优先级比&优先级高 */
                if ((curmask & premask) == premask)
                    break;
            }
            premask |= A[i];
        }

        return myset.size();
    }
};


/* 官方题解c++版也超时 */
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        /*
         * 动态规划
         * dp[i][j] - A[i] | A[i + 1] | ... | A[j]的结果
         * dp[i][j] = dp[i][j - 1] | A[j]
         * 对于固定的j，dp[j][j], dp[j - 1][j], ..., dp[1][j]结果是递增的，每个比前面的多添加一些1
         * 维护一个以j结尾的result的set，A[i] <= 10^9, set最多32个
         * 求j + 1时，只需要将set里的值和A[j + 1]按位或，并得到新的set值
         */
        unordered_set<int> ans;
        unordered_set<int> res;
        unordered_set<int> tmp;
        unordered_set<int> test;

        for (auto a : A) {
            tmp = test;
            for (auto t : res) {
                tmp.insert(t | a);
            }
            tmp.insert(a);
            ans.insert(tmp.begin(), tmp.end());
            res = tmp;
        }

        return ans.size();
    }
};

/* 超时 - myset改为unordered_set可通过 */
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        unordered_set<int> myset;
        int i, j, tmp, mask;
        
        /* 暴力循环 - 或操作会增加结果中二进制1的个数，先计算出最大的数的mask，result(i,j)达到mask时跳出内层循环 */
        mask = 0;
        for (i = 0; i < A.size(); i++)
            mask |= A[i];

        //cout << mask << endl;

        for (i = 0; i < A.size(); i++) {
            tmp = A[i];
            myset.insert(tmp);
            for (j = i - 1; j >= 0 && tmp != mask; j--) {
                tmp |= A[j];
                myset.insert(tmp);
            }
        }

        return myset.size();
    }
};

/* O(n^2)超时 */
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        unordered_set<int> myset;
        int i, j, tmp;

        /* 暴力循环 */
        for (i = 0; i < A.size(); i++) {
            tmp = A[i];
            myset.insert(tmp);
            for (j = i + 1; j < A.size(); j++) {
                tmp |= A[j];
                myset.insert(tmp);
            }
        }

        return myset.size();
    }
};
