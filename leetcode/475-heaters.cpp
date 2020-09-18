

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int ans = 0, cur;
        sort(heaters.begin(), heaters.end());

        /* 每个房子去前后近的加热站加热，所有的房子取最大的 */
        for (auto &house : houses) {
            cur = INT_MAX;
            auto larger = lower_bound(heaters.begin(), heaters.end(), house);
            if (larger != heaters.end()) {
                /* 右边有加热站 */
                cur = *larger - house;
            }
            if (larger != heaters.begin()) {
                auto smaller = larger - 1;
                cur = min(cur, house - *smaller);
            }
            ans = max(ans, cur);
        }

        return ans;
    }
};
