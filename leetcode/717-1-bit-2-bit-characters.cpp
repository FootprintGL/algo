


class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        /*
         * 1后面必须要跟一个数字，0可以单独也可以和前面的1配对
         *      1. 如果倒数第二个为0，则返回true
         *      2. 如果倒数第二个为1，假设最后2个配对，看前面剩下的能否顺利解码
         */
        int n = bits.size(), i;

        if (n == 1 || bits[n - 2] == 0)
            return true;

        for (i = 0; i < n - 2; i++) {
            if (bits[i] == 1) {
                if (i == n - 3)
                    return true;
                /* 跳过下一个配对元素 */
                i++;
            }
        }

        return false;
    }
};
