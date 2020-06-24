class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int n = arr.size();
        int i;

        /* 先对数组进行排序 */
        sort(arr.begin(), arr.end());
      
        /*
         * 找到位置i,把i开始所有元素替换成arr[i],sum (arr[i] ~ arr[n - 1])大于等于目标值
         * 此时说明结果处在arr[i - 1]和arr[i]之间
         */
        for (i = 0; i < n; i++) {
            /* 检查下一个元素 */
            if (arr[i] * (n - i) >= target) {
                break;
            } else {
                /* 更新目标值，减去当前元素 */
                target -= arr[i];
            }
        }

        /* 数组arr所有元素的和小于target，返回最大的元素 */
        if (i == n) {
            return arr[n - 1];
        }

        /* 结果为target / (n - i)或target / (n - i), 返回离target较近的值 */
        if (target % (n - i) <= (n - i) / 2)
            return target / (n - i);
        else
            return target / (n - i) + 1;
    }
};

/* 优化-二分法 */
