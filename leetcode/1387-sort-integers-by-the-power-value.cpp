

class Solution {
public:
    unordered_map<int, int> calculated;

    int calweight(int n) {
        /* 记忆化加速 */
        if (calculated.count(n))
            return calculated[n];
        int step = 0;
        while (n != 1) {
            if (n & 1)
                n = 3 * n + 1;
            else
                n /= 2;
            step++;
        }
        calculated[n] = step;
        return step;
    }

    int getKth(int lo, int hi, int k) {
        /*
         * 先算出[lo, hi]每个数的权重，设计比较函数，排序，取第k个数
         */
        /* 存放数字[lo,hi] */
        vector<int> arr(hi - lo + 1, 0);
        /* 存放[lo,hi]权重 */
        vector<int> weight(hi - lo + 1, 0);

        for (int i = lo; i <= hi; i++) {
            weight[i - lo] = calweight(i);
            arr[i - lo] = i;
        }

        /* 排序 */
        sort(arr.begin(), arr.end(), [&](int a, int b){
            return weight[a - lo] == weight[b - lo] ? a < b : weight[a - lo] < weight[b - lo];
        });

        return arr[k - 1];
    }
};

class Solution {
public:
    int calweight(int n) {
        /* 计算权重 - 模拟 */
        int step = 0;
        while (n != 1) {
            if (n & 1)
                n = 3 * n + 1;
            else
                n /= 2;
            step++;
        }
        return step;
    }

    int getKth(int lo, int hi, int k) {
        /*
         * 先算出[lo, hi]每个数的权重，设计比较函数，排序，取第k个数
         */
        /* 存放数字[lo,hi] */
        vector<int> arr(hi - lo + 1, 0);
        /* 存放[lo,hi]权重 */
        vector<int> weight(hi - lo + 1, 0);

        for (int i = lo; i <= hi; i++) {
            weight[i - lo] = calweight(i);
            arr[i - lo] = i;
        }

        /* 排序 */
        sort(arr.begin(), arr.end(), [&](int a, int b){
            return weight[a - lo] == weight[b - lo] ? a < b : weight[a - lo] < weight[b - lo];
        });

        return arr[k - 1];
    }
};
