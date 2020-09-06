
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {

        /*
         * tmp - 记录<nums[i],i>映射关系
         * 对tmp基于tmp[i].first排序
         * 对于第i个数xi, 左边的书必都小于等于它，假设prei表示左边第一个不等于xi的下表，则比xi小的数是prei + 1
         * 如果xi-1等于xi，则prei == prei-1, xi-1 != xi, 则prei = i - 1
         */
        vector<pair<int, int>> tmp;
        int n = nums.size();
        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++)
            tmp.push_back({nums[i], i});

        /* 基于nums[i]排序 */
        sort(tmp.begin(), tmp.end());
        int pre = -1;
        ans[tmp[0].second] = 0;
        for (int i = 1; i < n; i++) {
            if (tmp[i].first == tmp[i - 1].first) {
                ans[tmp[i].second] = pre + 1;
            } else {
                pre = i - 1;
                ans[tmp[i].second] = pre + 1;
            }
        }

        return ans;
    }
};

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        /*
         * 桶思想 - 适用于数据规模不大的情况
         * nums[i]: 取值范围[0,100]
         * 建立一个cnt[101]记录0-100数字出现的次数
         * 计算cnt的前缀和，则比nums[i]小的元素的个数就是前缀和cnt[nums[i] - 1]
         */
        vector<int> cnt(101, 0);
        int n = nums.size();
        vector<int> ans(n, 0);
        int i;

        /* 统计各个数字出现的次数 */
        for (i = 0; i < n; i++)
            cnt[nums[i]]++;

        /* 计算前缀和 */
        for (i = 1; i <= 100; i++)
            cnt[i] += cnt[i - 1];

        /* 更新结果 */
        for (i = 0; i < n; i++) {
            if (nums[i])
                ans[i] = cnt[nums[i] - 1];
        }

        return ans;
    }
};
