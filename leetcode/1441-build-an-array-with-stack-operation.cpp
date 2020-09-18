
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;

        /* 相等则push，不想等则先push再pop */
        for (int i = 1, j = 0; i <= n; i++) {
            if (target[j] == i) {
                res.push_back("Push");
                j++;
                if (j == target.size())
                    break;
            } else {
                res.push_back("Push");
                res.push_back("Pop");
            }
        }

        return res;
    }
};
