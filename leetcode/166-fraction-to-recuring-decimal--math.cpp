

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        /*
         * 当余数出现循环的时候，对应的商也循环
         * 哈希表记录余数出现在小数的位置，当发现已经出现的余数，将重复的部分用括号括起来
         * 余数为0时，停止计算
         * 需要考虑负分数以及极端情况，比如−2147483648/−1 - 整数范围(-2 ^ 31, 2 ^ 31 - 1
         */
        if (numerator == 0)
            return "0";

        /* long - 防止整型溢出 */
        long num = (long) numerator;
        long denom = (long) denominator;
        string res;

        /* 负数转化为正数 */
        if ((num > 0) ^ (denom > 0))
            res += '-';
        /* 求绝对值 */
        num = labs(num);
        denom = labs(denom);

        /* 整数部分 */
        res += to_string(num / denom);

        /* 小数部分 */
        num %= denom;

        if (num == 0)
        /* 余数为0能整除，直接返回结果 */
            return res;

        /* 添加小数点 */
        res += '.';
        /* 小数点的坐标 */
        int index = res.length() - 1;
        /* 记录余数和对应坐标 - 便于插入括号包围循环元素 */
        unordered_map<int, int> record;

        while (num && record.count(num) == 0) {
            /* 余数不为0且余数还没有出现重复数字 */
            record[num] = ++index;
            /* 后面补一个0 - 余数乘以10，求商 */
            num *= 10;
            res += to_string(num / denom);
            num %= denom;
        }

        if (record.count(num) == 1) {
            /* 出现循环数，插入括号包围循环小数部分 */
            res.insert(record[num], "(");
            res += ')';
        }

        return res;
    }
};
