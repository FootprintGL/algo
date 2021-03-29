

class Solution {
public:
    vector<int> grayCode(int n) {
        /*
         * 镜像反射法
         * 设n阶格雷编码为G(n), 则G(n + 1)阶格雷编码为
         *      给G(n)每个元素前面加0，得到G'(n)
         *      设G(n)倒序为R(n), 给R(n)每个元素二进制形式前面加1得到R'(n)
         * G(n + 1) = G'(n) U R'(n)拼接两个集合即可得到下一阶格雷码
         */
        vector<int> res;
        res.push_back(0);
        int head = 1;

        for (int i = 0; i < n; i++) {
            for (int j = res.size() - 1; j >= 0; j--) {
                res.push_back(head + res[j]);
            }
            head <<= 1;
        }

        return res;
    }
};
