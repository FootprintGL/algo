

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        /* 前缀和 + 滑动窗口 */
        int res = 0;
        int n = arr.size();

        /* 计算前缀和 */
        vector<int> sum(n + 1, 0);
        for (int i = 1; i <= n; i++)
            sum[i] = sum[i - 1] + arr[i - 1];
        /*
        for (auto t : sum)
            cout << t << " ";
        cout << endl << endl;
        */

        /* 维护一个k大小的窗口向右滑动 */
        int start = 0, end = k;
        while (end <= n) {
            //cout << start << " " << end << " " << sum[start] << " " << sum[end] << endl;
            if ((sum[end] - sum[start]) / k >= threshold)
                res++;
            start++;
            end++;
        }

        return res;
    }
};
