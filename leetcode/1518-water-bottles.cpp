

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        int empty = numBottles;

        while (empty >= numExchange) {
            int cur = empty / numExchange;
            empty %= numExchange;
            empty += cur;
            ans += cur;
        }

        return ans;
    }
};
