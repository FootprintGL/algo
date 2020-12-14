
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        /*
         * 基数排序
         * 分别针对没个位上的数排序，比如个位，十位，百位...
         * https://baike.baidu.com/item/%E5%9F%BA%E6%95%B0%E6%8E%92%E5%BA%8F
         */
        int n = nums.size();

        if (n < 2)
            return 0;

        int ans = 0;
        int exp = 1, i;
        int maxv = *max_element(nums.begin(), nums.end());
        vector<int> buf(n);        

        /* 从低到高依次按各位排序 */
        while (maxv >= exp) {
            /* 统计个数 */
            vector<int> cnt(10);
            for (int i = 0; i < n; i++) {
                int digit = nums[i] / exp % 10;
                cnt[digit]++;
            }

            /* 计算起始index */
            for (i = 1; i < 10; i++)
                cnt[i] += cnt[i - 1];

            /* 按指定位排序 */
            /*
            for (i = 0; i < n; i++) {
                int digit = nums[i] / exp % 10;
                buf[cnt[digit] - 1] = nums[i];
                cnt[digit]--;
            }
            */
            /* 需从右往左处理 */
            for (i = n - 1; i >= 0; i--) {
                int digit = nums[i] / exp % 10;
                buf[cnt[digit] - 1] = nums[i];
                cnt[digit]--;
            }

            /* 该轮结果放回原数组 */
            copy(buf.begin(), buf.end(), nums.begin());
            exp *= 10;
        }

        /* 遍历桶搜索最大间距 */
        for (i = 1; i < n; i++) {
            ans = max(ans, nums[i] - nums[i - 1]);
        }

        return ans;
    }
};


class Solution {
public:
    int maximumGap(vector<int>& nums) {
        /*
         * 桶排序
         * 假设数组中最大最小元素为max, min, 则相邻数字的最大间距为(max - min) / (N - 1)向上取整
         * 选取d = (max - min) / (N - 1)向下取整，将区间划分为大小为d的桶，并找出每个整数所在的桶
         * 数字的最大间距一定出现在两桶之间。找到桶后，每个同记录最大最小值，遍历所有的桶，后一个桶的
         * 最小值与前一个桶的最大值之差作为两个桶的间距
         */
        int ans = 0;
        int n = nums.size(), i;

        if (n < 2)
            return 0;

        int maxv = *max_element(nums.begin(), nums.end());
        int minv = *min_element(nums.begin(), nums.end());

        int d = max(1, (maxv - minv) / (n - 1));
        int bucketsize = (maxv - minv) / d + 1;
        vector<pair<int, int>> buckets(bucketsize, {-1, -1});

        /* 把数组元素放入桶中 */
        for (i = 0; i < n; i++) {
            int idx = (nums[i] - minv) / d;
            if (buckets[idx].first == -1) {
                buckets[idx].first = buckets[idx].second = nums[i];
            } else {
                buckets[idx].first = min(buckets[idx].first, nums[i]);
                buckets[idx].second = max(buckets[idx].second, nums[i]);
            }
        }

        /* 遍历桶搜索最大间距 */
        int pre = -1;
        for (i = 0; i < bucketsize; i++) {
            if (buckets[i].first != -1) {
                if (pre != -1) {
                    ans = max(ans, buckets[i].first - buckets[pre].second);
                }
                pre = i;
            }
        }

        return ans;
    }
};
