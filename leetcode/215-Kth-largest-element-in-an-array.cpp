
class Solution {
public:
    /* 交换数组中下标i和j的元素 */
    void swap(vector<int> &nums, int i, int j) {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }

    /* 调整最大堆 - 递归  */
    void adjustheap(vector<int> &nums, int j, int len) {
        if (2 * j + 1 < len) {
            if (2 * j + 2 < len) {
                /* 左右儿子都有 */
                if (nums[2 * j + 1] > nums[2 * j + 2]) {
                    /* 左儿子较大 */
                    if (nums[j] < nums[2 * j + 1]) {
                        swap(nums, j, 2 * j + 1);
                        /* 继续调整右子树 */
                        adjustheap(nums, 2 * j + 1, len);
                    } else {
                        return;
                    }
                } else {
                    /* 右儿子较大 */
                    if (nums[j] < nums[2 * j + 2]) {
                        swap(nums, j, 2 * j + 2);
                        /* 继续调整右子树 */
                        adjustheap(nums, 2 * j + 2, len);
                    } else {
                        return;
                    }
                }
            } else {
                /* 只有左儿子 */
                if (nums[j] < nums[2 * j + 1]) {
                    swap(nums, j, 2 * j + 1);
                }
                return;
            }
        }
    }

    /* 构建调整最大堆 */
    void createheap(vector<int> &nums, int len) {
        int i;

        for (i = len / 2 - 1; i >= 0; i--) {
            adjustheap(nums, i, len);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int i;

        /*
         * 堆排序
         * 每次构建堆可以排好一个元素，调整k次可得到第k个最大元素
         */
        for (i = 0; i < k; i++) {
            createheap(nums, n - i);
            swap(nums, 0, n - i - 1);
        }
/*
     for (i = 0; i < n; i++) {
            cout << nums[i] << " ";
        }
        cout << endl;
*/
        return nums[n - k];
    }
};

class Solution {
public:
    /* 交换数组中下标i和j的元素 */
    void swap(vector<int> &nums, int i, int j) {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }

    /* 构建调整最大堆 - 迭代 */
    void adjustheap(vector<int> &nums, int len) {
        int i, j;

        for (i = len / 2 - 1; i >= 0; i--) {
            j = i;
            while (2 * j + 1 < len) {
                if (2 * j + 2 < len) {
                    /* 左右儿子都有 */
                    if (nums[2 * j + 1] > nums[2 * j + 2]) {
                        /* 左儿子较大 */
                        if (nums[j] < nums[2 * j + 1]) {
                            swap(nums, j, 2 * j + 1);
                            /* 继续调整右子树 */
                            j = 2 * j +  1;
                        } else {
                            break;
                        }
                    } else {
                        /* 右儿子较大 */
                        if (nums[j] < nums[2 * j + 2]) {
                            swap(nums, j, 2 * j + 2);
                            /* 继续调整右子树 */
                            j = 2 * j + 2;
                        } else {
                            break;
                        }
                    }
                } else {
                    /* 只有左儿子 */
                    if (nums[j] < nums[2 * j + 1]) {
                        swap(nums, j, 2 * j + 1);
                    }
                    break;
                }
            }
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int i;

        /*
         * 堆排序
         * 每次构建堆可以排好一个元素，调整k次可得到第k个最大元素
         */
        for (i = 0; i < k; i++) {
            adjustheap(nums, n - i);
            swap(nums, 0, n - i - 1);
        }
/*
     for (i = 0; i < n; i++) {
            cout << nums[i] << " ";
        }
        cout << endl;
*/
        return nums[n - k];
    }
};

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
