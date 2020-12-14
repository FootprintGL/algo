


class Solution {
public:
    /* 题目规定有效运算符为"+, -, *" */
    bool isoperation(char c) {
        return c == '+' || c == '-' || c == '*';
    }

    /* 计算 */
    int calculate(int n1, char op, int n2) {
        if (op == '+') {
            return n1 + n2;
        } else if (op == '-') {
            return n1 - n2;
        } else {
            return n1 * n2;
        }
    }

    vector<int> diffWaysToCompute(string input) {
        /*
         * 分治 - 递归
         * 运用运算符把整个式子分成2部分，2部分再递归解决
         * 有了两边的结果，在通过中间的运算符两两计算加入到最终结果即可
         * 如果字符串只有数字，则将字符串转换成数字返回
         */
        int n = input.size();

        if (n == 0)
            return vector<int>{};

        vector<int> res;

        int i = 0;
        int num = 0;
        while(i < n && !isoperation(input[i])) {
            /* 数字 */
            num = num * 10 + input[i] - '0';
            i++;
        }
        if (i == n) {
            /* input全是数字 */
            res.push_back(num);
            return res;
        }

        for (i = 0; i < n; i++) {
            if (isoperation(input[i])) {
                vector<int> res1 = diffWaysToCompute(input.substr(0, i));
                vector<int> res2 = diffWaysToCompute(input.substr(i + 1));
                for (int j = 0; j < res1.size(); j++) {
                    for (int k = 0; k < res2.size(); k++) {
                        res.push_back(calculate(res1[j], input[i], res2[k]));
                    }
                }
            }
        }

        return res;
    }
};
