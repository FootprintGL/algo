

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        /* 双指针 - 把数组分成奇数和偶数两部分 */
        int odd = 1, even;

        for (even = 0; even < A.size(); even += 2) {
            if (A[even] % 2 == 1) {
                /* 偶数位置为奇数，寻找奇数位置上的偶数做交换 */
                while (A[odd] % 2 == 1)
                    odd += 2;
                int tmp = A[even];
                A[even] = A[odd];
                A[odd] = tmp;
            }
        }

        return A;
    }
};
