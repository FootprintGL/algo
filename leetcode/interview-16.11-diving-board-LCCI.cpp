
class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        vector<int> res;
        if (k == 0) {
            return res;
        }
        /* 先全部用shorter木板，然后一次替换一个longer木板 */
        res.push_back(k * shorter);
        if (shorter != longer) {
            for (int i = 0; i < k; i++)
                res.push_back(res[0] + (i + 1) * (longer - shorter));
        }

        return res;
    }
};


class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        vector<int> res;
        if (k == 0) {
            return res;
        }
        if (shorter == longer) {
            res.push_back(k * shorter);
            return res;
        }
        /* 先全部用shorter木板，然后一次替换一个longer木板 */
        res.push_back(shorter * k);
        if (shorter != longer) {
            for (int i = 0; i < k; i++)
                res.push_back(res[0] + (i + 1) * (longer - shorter));
        }

        return res;
    }
};
