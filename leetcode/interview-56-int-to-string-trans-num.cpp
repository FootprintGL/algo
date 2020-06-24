#include <stdlib.h> 

class Solution {
public:
    int translateNum(int num) {
        string str, str1;
        int tmp, len;
        int f, f1, f2;
        int i;

        str = to_string(num);
        len = str.size();

        /*
         * 动态规划
         * f(i)表示从起始位置到i有多少种翻译方法
         * 如果str[i - 1]str[i]组成的整数是非法字符(>25)，则f(i) = f(i - 1)
         * 如果str[i - 1]str[i]组成的整数是有效字符(0 ~ 25)，则f(i) = f(i - 1) + f(i)
         * 初始状态f(-1) = 1, f(0) = 1, 循环计算f(1)到f(n - 1), 最后返回f(n - 1)
         * f(i)之和前两个位置的结果有关系，采用循环数字方法优化空间
         * f2 -> i - 2位置的翻译方法数
         * f1 -> i - 1位置的翻译方法数
         * f -> i位置的翻译方法数
         */
        f = f1 = f2 = 1;
        for (i = 1; i < len; i++) {
            f = f1;
            /* calculate f2 */
            str1 = str.substr(i - 1, 2);
            if (str1 <= "25" && str1 >= "10")
                f += f2;
            f2 = f1;
            f1 = f;
        }

        return f;
    }
};

