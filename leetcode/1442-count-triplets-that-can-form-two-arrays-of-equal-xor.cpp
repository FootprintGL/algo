

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        /*
         * a == b ==> a ^ b == 0
         * 0 <= i < j <= k < length
         * 寻找i -> k区间，使得区间内的元素异或为0，j在(i,k]范围中，共有k - i个三元组
         */
        int res = 0;
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            int tmp = arr[i];
            for (int j = i + 1; j < n; j++) {
                tmp ^= arr[j];
                if (tmp == 0)
                    res += j - i;
            }
        }

        return res;
    }
};
