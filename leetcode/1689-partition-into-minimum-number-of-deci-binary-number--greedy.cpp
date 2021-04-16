

class Solution {
public:
    int minPartitions(string n) {
        /*
         * 贪心
         * 如果位上的数字大于0，则减1，结果为字符串中最大的数字
         */
        char cmax = '0';
        for (auto &c : n) {
            if (c > cmax)
                cmax = c;
        }
        return cmax - '0';
    }
};
