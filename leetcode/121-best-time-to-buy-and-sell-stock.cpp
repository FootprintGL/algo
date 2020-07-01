class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int min, res = 0;
        int i;

        if (n == 0)
            return 0;

        min = prices[0];
        for (i = 1; i < n; i++) {
            if (prices[i] < min)
                min = prices[i];
            else
                res = max(res, prices[i] - min);
        }

        return res;
    }
};
