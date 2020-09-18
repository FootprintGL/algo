

class Solution {
public:
    string generateTheString(int n) {
        /*
         * n为偶数，第一个位置放b，其他位置放a
         * n为奇数，全部放a
         */
        string res;

        if (n % 2)
            res.push_back('a');
        else
            res.push_back('b');

        for (int i = 2; i <= n; i++)
            res.push_back('a');

        return res;
    }
};
