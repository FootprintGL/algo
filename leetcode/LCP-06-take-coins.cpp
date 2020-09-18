
class Solution {
public:
    int helper(int coin) {
        return coin % 2 ? coin / 2 + 1 : coin / 2;
    }

    int minCount(vector<int>& coins) {
        int res = 0;

        for (auto const &coin : coins)
            res += helper(coin);

        return res;
    }
};
