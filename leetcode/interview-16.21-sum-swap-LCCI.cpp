

class Solution {
public:
    vector<int> findSwapValues(vector<int>& array1, vector<int>& array2) {
        /*
         * 如果sumA + sumB为奇数，返回空数组
         * 假设交换a, b可以使sumA == sumB, sumA - a + b = sumB - b + a
         * a - b == (sumA - sumB) / 2
         * 在B中查找是否存在a - (sumA - sumB) / 2的值，哈希表优化查找速度
         */
        unordered_set<int> tbl;
        int sumA = 0, sumB = 0, i = 0;
        int m = array1.size(), n = array2.size();

        /* 计算sumA */
        for (i = 0; i < m; i++)
            sumA += array1[i];

        /* 计算sumB, 并把array2中元素放入哈希表 */
        for (i = 0; i < n; i++) {
            sumB += array2[i];
            tbl.insert(array2[i]);
        }

        if ((sumA + sumB) % 2)
        /* 奇数不可能平分 */
            return {};

        /* 在array2中搜索a - (sumA - sumB) / 2 */
        int tmp = (sumA - sumB) / 2;
        for (auto &a : array1) {
            if (tbl.count(a - tmp)) {
                return {a, a - tmp};
            }
        }

        return {};
    }
};
