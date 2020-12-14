

class Solution {
public:
    int findNthDigit(int n) {
        /*
         * 找规律
         * 数字范围     位数        数字数量        数位数量
         * 1 - 9        1           9               9
         * 10 - 99      2           90              180
         * 100 - 999    3           900             2700
         * ... ...
         * start - end  digit       9 * start       9 * start * digit
         * digit = digit + 1
         * start = start * 10
         * count= 9 * start * digit
         * 1. 确定n所在数字的位数digit
         *      循环执行n减去一位数，二位数，..., digit - 1位数的数位数量count
         *      直到n <= count时退出，此时的n是从起始数字start开始计数的
         *      结论：所求数位在某个digit中，所求数字为从start开始的第n个数位
         * 2. 确定所求数位所在的数字 - 所求数位在从数字start开始的第[(n - 1) / digit]个数字中(start为第0个)
         *      num = start + (n - 1) / digit
         * 3. 确定所求数位在num的哪一个数位 - 所求数位为数字num的第(n - 1) % digit位 (数字首个数位为第0位)
         *      s = str(num) //转换为string
         *      res = int(s[(n - 1) % digit]) //获得num的第[(n - 1) % digit]位，并转换为int
         * 例子：2901 = 9 + 180 + 2700 + 12，一定是4位数，第12位n = 12
         *      数据为1000 + (12 - 1) / 4 = 1002
         *      定位1002中的位置 = (n - 1) % 4 = 3, res = 2
         */
        long digit = 1;
        long start = 1;
        long count = 9;

        while (n > count)  {
            n -= count;
            digit += 1;
            start *= 10;
            count = 9 * start * digit;
        }

        long num = start + (n - 1) / digit;
        string s = to_string(num);

        return s[(n - 1) % digit] - '0';
    }
};
