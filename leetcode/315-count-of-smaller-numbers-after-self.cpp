



class Solution {
public:
    /* 归并排序 - 归并时统计结果 */
    void countmerge(vector<int> &nums, int l, int m, int r, vector<int> &index, vector<int> &temp, vector<int> &res) {

        int i, j, k;
        for (i = l; i <= r; i++) {
            temp[i] = index[i];
        }
        //cout << "merge: " << l << " " << m << " " << r << endl;
        i = l;
        j = m + 1;
        for (k = l; k <= r; k++) {
            if (i > m) {
                index[k] = temp[j];
                j++;
            } else if (j > r) {
                /* 右办部分处理完毕 - 左半部分剩下的元素都比右半部分大，更新结果 */
                index[k] = temp[i];
                res[index[k]] += (r - m);
                i++;
            } else if (nums[temp[i]] <= nums[temp[j]]) {
                /* 右半部分已经归位的比temp[i]小，更新结果 */
                index[k] = temp[i];
                res[index[k]] += (j - m - 1);
                i++;
            } else {
                index[k] = temp[j];
                j++;
            }
        }
    }

    void dfs(vector<int> &nums, int l, int r, vector<int> &index, vector<int> &temp, vector<int> &res) {
        if (l == r)
            return;
        int mid = l + (r - l) / 2;
        //cout << "dfs: " << l << " " << mid << " " << r << endl;
        dfs(nums, l, mid, index, temp, res);
        dfs(nums, mid + 1, r, index, temp, res);
        if (nums[index[mid]] > nums[index[mid + 1]])
            /* 如果num[index[mid]]比num[index[mid + 1]]小，区间已经有序，只在没排好才继续处理 */
            countmerge(nums, l, mid, r, index, temp, res);
    }

    vector<int> countSmaller(vector<int>& nums) {
        int len = nums.size();
        vector<int> res(len, 0);
        if (len == 0)
            return res;

        vector<int> index(len, 0);
        vector<int> temp(len, 0);

        for (int i = 0; i < len; i++)
            index[i] = i;
        /*
         * 归并排序
         * 归并排序会改变数组中元素的顺序，需要统计每个元素右侧小于它的数
         * 借助索引数组，对索引数据排序从而避免原数组位置的变化
         */
        dfs(nums, 0, len - 1, index, temp, res);

        return res;
    }
};
