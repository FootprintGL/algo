

class Solution {
public:
    unordered_map<string, unordered_map<string, bool>> memo;

    bool isScramble(string s1, string s2) {
        /*
         * 记忆化递归
         * 两个随机操作，切割和交换，讨论两种情况
         * 1 s1[0,i]和s2[0,i]可转换，s1[i,n - i]和s2[i,n-i]可转换
         * 2 s1[0,i]和s2[n - i,i]可转换，s1[n - i, i]和s2[0,i]可转换
         * 终止条件 - 长度为0/1时两个字符串是否相等进行判断。如果两个字符串
         * 长度不同或包含的字母不同,一定不能相互转换
         */
        if (memo.count(s1) && memo[s1].count(s2))
            return memo[s1][s2];

        if (s1 == s2)
            return memo[s1][s2] = 1;

        for (int i = 1, n = s1.size(); i < n; i++) {
            bool t1 = isScramble(s1.substr(0,i), s2.substr(0,i)) && isScramble(s1.substr(i, n - i), s2.substr(i, n - i));
            bool t2 = isScramble(s1.substr(0,i), s2.substr(n - i,i)) && isScramble(s1.substr(i, n - i), s2.substr(0, n - i));
            if (t1 || t2)
                return memo[s1][s2] = 1;
        }

        return memo[s1][s2] = 0;
    }
};
