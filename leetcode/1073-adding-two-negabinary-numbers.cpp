

class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        /*
         * -2为基数，(-2) ^ (n + 1) = -2 * (-2) ^ (n), 进位为-1
         * (-2) ^ (n) + (-2) ^ (n) = -1 * (-2) ^ (n + 1) = ...
         * ... = -2 * (-2) ^ (n + 1) + (-2) ^ (n + 1) = (-2) ^ (n + 2) + (-2) ^ (n + 1)
         * ==> 1 + 1 = -1 0 = 110
         * 用car保存进位，num保存当前位相加的结果 num = arr[i] + arr[j] + car
         * num有以下集中情况:
         *      num     解释               pre        cur
         *      -1      向前结尾            1           1
         *      0       刚好抵消            0           0
         *      1       多余1位             0           1
         *      2       过多需要进位        -1          0
         *      3       过多需要进位        -1          1
         *  去掉前导0，从后往前得到最终结果
         */
        vector<int> res;
        int n1 = arr1.size(), n2 = arr2.size();
        int i = n1 - 1, j = n2 - 1;
        int car = 0;

        while (i >= 0 || j >= 0) {
            int num = car;
            if (i < 0) {
                num += arr2[j--];
            } else if (j < 0) {
                num += arr1[i--];
            } else {
                num += arr1[i--] + arr2[j--];
            }

            switch (num) {
                case -1:
                    car = 1;
                    res.insert(res.begin(), 1);
                    break;
                case 0:
                    car = 0;
                    res.insert(res.begin(), 0);
                    break;
                case 1:
                    car = 0;
                    res.insert(res.begin(), 1);
                    break;
                case 2:
                    car = -1;
                    res.insert(res.begin(), 0);
                    break;
                case 3:
                    car = -1;
                    res.insert(res.begin(), 1);
                    break;
                default:
                    /* 不会到这里 */
                    break;
            }
        }

        if (car == -1) {
            /* 处理进位 */
            res.insert(res.begin(), 1);
            res.insert(res.begin(), 1);
        }

        /* 去掉先导0 */
        while (res.size() > 0 && res[0] == 0) {
            res.erase(res.begin());
        }

        return res.size() > 0 ? res : vector<int>{0};
    }
};
