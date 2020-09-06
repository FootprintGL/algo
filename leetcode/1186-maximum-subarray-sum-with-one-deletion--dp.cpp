
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        /* 
         * 动态规划
         * f(i) - 以arr[i]结尾的子数组的最大和
         * g(i) - 以arr[i]结尾的删除一个元素的子数组最大和
         * f(i) = max(f(i - 1) + arr[i], arr[i])
         * g(i) = max(g(i - 1) + num[i], f(i - 1)), f(i - 1) -> 删除arr[i], g(i - 1) + arr[i] -> 删除0 ～ i - 1
         * f(0) = arr[0], g(0) = 0 -> g(1) = max(g(0) + arr[i], f(0)) = max(0 + arr[1], arr[0]) = max(arr[0], arr[1])
         * 边计算边更新结果ans
         */
        int n = arr.size();
        if (n == 1)
            /* 非空子数组 */
            return arr[0];

        vector<int> f(n, 0);
        vector<int> g(n, 0);
        int ans = f[0] = arr[0];
        g[0] = 0;

        for (int i = 1; i < n; i++) {
            f[i] = max(f[i - 1] + arr[i], arr[i]);
            g[i] = max(g[i - 1] + arr[i], f[i - 1]);
            ans = max(max(f[i], g[i]), ans);
        }

        return ans;
    }
};
