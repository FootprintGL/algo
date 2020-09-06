
class Solution {
public:
    bool dfs(vector<int>& nums, int n, int k, int start, int target, int cur, vector<bool> &used) {

        if (cur == target)
            /* 搜索到一个和为target的子集，start从0开始继续搜索 */
            return dfs(nums, n, k - 1, 0, target, 0, used);

        /* 剩下肯定能组和成target */
        if (k == 1)
            return true;

        /* 对一其中一个集合，不用每次从第一个一个搜索，从start开始搜索可以避免重复的检查 */
        //for (int i = 0; i < n; i++) {
        for (int i = start; i < n; i++) {
            if (used[i])
                continue;
            used[i] = true;
            if ((cur + nums[i] <= target) && dfs(nums, n, k, i + 1, target, cur + nums[i], used))
                return true;
            used[i] = false;
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        /*
         * 回溯算法
         * 把nums分成k组，每组和为sum/k
         * 搜索子集和为sum/k, 知道搜到k个和为sum/k的子集停止
         */
        int target, sum = 0;
        int n = nums.size();
        int i;

        for (i = 0; i < n; i++)
            sum += nums[i];

        /* 从大到小排序 - 减少递归次数 */
        sort(nums.begin(), nums.end(), greater());
        //dump(nums);

        target = sum / k;
        if (n < k || sum % k || nums[0] > target)
            return false;

        vector<bool> used(n, false);
        return dfs(nums, n, k, 0, target, 0, used);
    }
};


class Solution {
public:
    void dump(vector<int> &used) {
        for (int i = 0; i < used.size(); i++)
            cout << used[i] << " ";
        cout << endl;
    }

    bool dfs(vector<int>& nums, int n, int k, int target, int cur, vector<bool> &used) {
        /*
        cout << cur << " " << k << endl;
        dump(used);
        cout << endl;
        */
        if (cur == target)
            return dfs(nums, n, k - 1, target, 0, used);

        /* 剩下肯定能组和成target */
        if (k == 1)
            return true;

        for (int i = 0; i < n; i++) {
            if (used[i])
                continue;
            used[i] = true;
            if ((cur + nums[i] <= target) && dfs(nums, n, k, target, cur + nums[i], used))
                return true;
            used[i] = false;
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        /*
         * 回溯算法
         * 把nums分成k组，每组和为sum/k
         * 搜索子集和为sum/k, 知道搜到k个和为sum/k的子集停止
         */
        int target, sum = 0;
        int n = nums.size();
        int i;

        for (i = 0; i < n; i++)
            sum += nums[i];

        /* 从大到小排序 - 减少递归次数 */
        sort(nums.begin(), nums.end(), greater());
        //dump(nums);

        target = sum / k;
        if (n < k || sum % k || nums[0] > target)
            return false;

        vector<bool> used(n, false);
        return dfs(nums, n, k, target, 0, used);
    }
};
