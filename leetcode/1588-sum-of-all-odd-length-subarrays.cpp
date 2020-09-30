





class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {

        int n = arr.size(), sum = 0;
        int i, j;

        /* 前缀和 */
        for (i = 1; i < n; i++) {
            arr[i] += arr[i - 1];
        }

        for (j = 1; j <= n; j += 2) {
            for (i = 0; i < n - j + 1; i++) {
                sum += arr[i + j - 1];
                if (i > 0)
                    sum -= arr[i - 1];
            }
        }

        return sum;
    }
};
