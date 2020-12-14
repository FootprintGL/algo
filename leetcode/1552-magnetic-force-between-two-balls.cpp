

class Solution {
public:
    /* 检查最小磁力x能否成功放置 - 贪心算法 */
    bool check(vector<int> &position, int m, int x) {
        int cnt = 0;
        int target = position[0] + x;
        for (int i = 0; i < position.size(); i++) {
            if (position[i] >= target) {
                cnt++;
                if (cnt == m - 1)
                    return true;
                target = position[i] + x;
            }
        }

        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        /*
         * 二分 + 贪心
         * 二分搜索最小值为2个位置的最小间距
         * 二分搜索最大值为 最大间距 / m - 1
         * 确定好边界后每次去中间值进行验证，验证过程使用贪心算法
         * 遍历数组，如果找到两个位置之间的距离大于等于最小磁力，则计数器+1
         * 最后判断计数器是否大于等于m - 1即可
         * 最大化最小磁力
         *      如果当前最小磁力满足条件，左边界右移
         *      如果不满足，右边界左移
         * 每次满足条件左边界右移，左边界左边一个数值一定是满足条件的，结果为l - 1
         */

        /* 先排序 */
        sort(position.begin(), position.end());

        /* 求左边界 */
        int left = INT_MAX;
        for (int i = 0; i < position.size() - 1; i++) {
            if (position[i + 1] - position[i] < left)
                left = position[i + 1] - position[i];
        }

        /* 求右边界 */
        int right = (position[position.size() - 1] - position[0]) / (m - 1);

        //cout << left << " " << right << endl;

        /* 二分搜索 */
        while (left <= right) {
            int mid = left + (right - left) / 2;
            //int mid = (left + right) / 2;
            if (check(position, m, mid)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return left - 1;
    }
};
