

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        /*
         * 哈希表
         * 假设交换的为A中的x和B中的y，则有x + B - y = y + A - x
         * y = (B - A) / 2 + x
         * 对于每一个A[i], 在B查找(B - A) / 2 + x
         */
        vector<int> ans;
        unordered_set<int> myset;
        int asum = accumulate(A.begin(), A.end(), 0);
        int bsum = accumulate(B.begin(), B.end(), 0);

        for (auto b : B)
            myset.insert(b);

        for (auto a : A) {
            if (myset.count((bsum - asum) / 2 + a)) {
                ans.push_back(a);
                ans.push_back((bsum - asum) / 2 + a);
                break;
            }
        }

        return ans;
    }
};
