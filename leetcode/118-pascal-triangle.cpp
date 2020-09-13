

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        vector<int> tmp;

        for (int i = 0; i < numRows; i++) {
            tmp.push_back(1);
            for (int j = 1; j < i; j++)
                tmp[j] = res[i - 1][j] + res[i - 1][j - 1];
            res.push_back(tmp);
        }

        return res;
    }
};
