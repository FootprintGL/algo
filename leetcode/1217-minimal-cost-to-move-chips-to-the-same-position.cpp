
class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        /*
         * 脑筋急转弯
         * 奇数位移到奇数位没有代价，偶数位移到偶数位代价为0
         * 结果为min{奇数位的个数，偶数位的个数}
         */
        int cnt = 0, n = position.size();
        for (auto pos : position)
            if (pos % 2)
                cnt++;

        return min(cnt, n - cnt);
    }
};
