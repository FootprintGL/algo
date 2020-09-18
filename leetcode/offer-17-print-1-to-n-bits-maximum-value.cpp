
class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> res;
        int num = 1;

        while (n) {
            num *= 10;
            n--;
        }

        for (int i = 1; i < num; i++)
            res.push_back(i);

        return res;
    }
};
