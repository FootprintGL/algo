

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        /*
         * 我那不到剩下的最大的一堆，最大的会被A拿走，我可以拿第二大的，把最小的给B
         * 每次拿[max, secmax, min]，这样可以保证我能拿到最多的硬币
         */
        int res = 0;
        int left = 0, right = piles.size() - 1;

        sort(piles.begin(), piles.end());

        while (left <= right) {
            right--;
            res += piles[right];
            right--;
            left++;
        }

        return res;
    }
};
