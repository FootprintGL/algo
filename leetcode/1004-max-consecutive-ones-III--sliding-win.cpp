

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        /*
         * 滑动窗口
         * maxcnt记录窗口内1的个数
         * 如果窗口长度小于等于maxcnt + K，更新结果并右移right扩大窗口
         * 如果窗口长度大于maxcnt + K, 右移left缩小窗口
         */
        int n = A.size();
        int maxcnt = 0;
        int cnt = 0;
        int left = 0;
        int right = 0;
        int ans = 0;

        while (right < n) {
            if (A[right] == 1)
                maxcnt++;

            while (right - left + 1 > maxcnt + K) {
                if (A[left] == 1)
                    maxcnt--;
                left++;
            }

            ans = max(ans, right - left + 1);
            right++;
        }

        return ans;
    }
};
