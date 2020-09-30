

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        /* 暴力算法 */
        int i, j;

        for (i = 0; i < prices.size() - 1; i++) {
            for (j = i + 1; j < prices.size(); j++) {
                if (prices[i] >= prices[j])
                    break;
            }
            if (j != prices.size())
                prices[i] -= prices[j];
        }

        return prices;
    }
};
