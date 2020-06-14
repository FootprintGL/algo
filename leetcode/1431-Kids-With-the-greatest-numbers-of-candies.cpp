class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> *res = new vector<bool> (candies.size(), false);
        int i, max = 0;

        /* 找到拥有最多糖果的孩子有多少个糖果 */
        for (i = 0; i < candies.size(); i++) {
            if (max < candies[i])
                max = candies[i];
        }

        /* 把额外的糖果全部分给一个孩子，查看是否大于等于max,得出结果 */
        for (i = 0; i < candies.size(); i++) {
            if (candies[i] + extraCandies >= max)
                res->at(i) = true;
            else
                /* res所有元素初始化为false，这条语句可以忽略，加上为了逻辑严谨性 */
                res->at(i) = false;
        }

        return *res;
    }
};
