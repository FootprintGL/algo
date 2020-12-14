

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        /*
         * 贪心
         * 令牌朝上选能量最小的令牌，反面朝上选能量最大的令牌
         * 只要还有能量，就一直让令牌朝上，直到没有能量的时候，让一个领跑反面朝上获得能量
         * 结果一定是令牌朝上时产生的
         */
        sort(tokens.begin(), tokens.end());
        int left = 0, right = tokens.size() - 1;
        int score = 0, p = P;

        while (left <= right) {
            while (left <= right && p >= tokens[left]) {
                /* 能量足够，能量换令牌分 */
                p -= tokens[left];
                left++;
                score++;
            }

            if (score == 0 || left >= right)
                break;

            /* 能量不够，令牌分换能量 */
            p += tokens[right];
            right--;
            score--;
        }

        return score;
    }
};
