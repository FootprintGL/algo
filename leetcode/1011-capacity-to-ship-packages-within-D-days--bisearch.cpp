

class Solution {
public:
    /* 检查运载能力为cap时能否在D天内完成运输 */
    bool checkpossible(vector<int> &weights, int D, int cap) {
        /* 贪心 - cap范围内尽可能多运 */
        int cur = 0, cnt = 0;
        int n = weights.size(), i = 0;

        //cout << "cap-" << cap << ":" << endl;
        while (i < n) {
            cur = 0;
            while (i < n && cur + weights[i] <= cap) {
                cur += weights[i];
                i++;
            }
            cnt++;

            //cout << i << " " << cnt << " " << cur << endl;
            //cur = weights[i - 1];

            if (cnt > D) {
                //cout << "n" << endl << endl;
                return false;
            }
        }

        //cout << "y" << endl << endl;;
        return true;
    }

    int shipWithinDays(vector<int>& weights, int D) {
        /* 二分查找: 范围为[max{weights}, sum{weights}] */
        int left = 0, right = 0;

        for (auto &w : weights) {
            right += w;
            if (w > left)
                left = w;
        }

        int ans = right;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (checkpossible(weights, D, mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};
