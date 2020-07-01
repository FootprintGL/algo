class Solution {
public:
    /* 交换数组中下标i和j的元素 */
    void swap(vector<int> &nums, int i, int j) {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }

    /* 分区使得[l, j - 1]元素小于nums[j], [j + 1, r]元素大于nums[j], 返回归为元素下标 */
    int partition(vector<int>& nums, int l, int r) {
        int ri = rand() % (r - l + 1);
        int key;
        int i, j;

        if (l == r)
            return l;
        
        swap(nums, l + ri, l);
        key = nums[l];
        i = l + 1;
        j = r;

        while (i <= j) {
            while (i <= j && nums[i] < key)
                i++;
            while (i <= j && nums[j] > key)
                j--;
            
            if (i > j)
                break;
            
            swap(nums, i, j);
            i++;
            j--;
        }
        swap(nums, l, j);

        return j;
    }

    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int p, l, r;
        int target = n - k;

        l = 0;
        r = n - 1;
        /*
         * 快速排序
         * 从小到大排序后，第k个最大的元素的下标为n - k
         * 快速排序会有一个元素归位，如果归位元素下标为n - k, 则提前结束
         * pivot的选择和重要，这里随机选择pivot元素，保证算法的整体复杂度
         * 每次只需要查找target所在的分区即可
         */
        while (true) {
            p = partition(nums, l, r);
            if (p == target)
                break;
            else if (p < target)
                l = p + 1;
            else
                r = p - 1;
        }

        return nums[p];
    }
};
