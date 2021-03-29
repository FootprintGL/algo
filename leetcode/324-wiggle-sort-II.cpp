




//#define A(i) nums[(1+2*(i))%(n|1)]

class Solution {
public:
/*
    void swap(vector<int> &nums, int i, int j) {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
*/
    void wiggleSort(vector<int>& nums) {
        /*
         * 快速选择 + 3-way-partition + 虚地址
         * nth_element()可以进行快速选择，将第n个小的元素放在数组的第n个位置
         * 同时保证其左边元素不大于自身，右边元素不小于自身
         * 找到中位数后，需要利用3-way-partition算法将中位数放中间，小数放左边，大数放右边 
         * 然后将数组从中间等分为2个部分，然后反序，穿插，即可得到最终结果
         * 为了优化空间，可以将数组从原本的空间映射到另一个虚拟空间，虚拟空间的索引和真实空间的索引
         * 存在某种映射关系。这里需要建立一种映射关系来描述“分割“和”穿插”的过程，然后我们可以用虚拟
         * 地址访问元素，在虚拟地址空间中对3-way-partition或排序，使数组在虚拟空间中满足某种空间关系。
         * 3-way-partition调整为大的放在左边，小的放在右边A[i] = num[(1 + 2 * in) % (n | 1)]
         * n为偶数，n | 1为n + 1, 如果n为奇数，n | 1为n
         * Accessing A(0) actually accesses nums[1].
         * Accessing A(1) actually accesses nums[3].
         * Accessing A(2) actually accesses nums[5].
         * Accessing A(3) actually accesses nums[7].
         * Accessing A(4) actually accesses nums[9].
         * Accessing A(5) actually accesses nums[0].
         * Accessing A(6) actually accesses nums[2].
         * Accessing A(7) actually accesses nums[4].
         * Accessing A(8) actually accesses nums[6].
         * Accessing A(9) actually accesses nums[8].
         */
        auto midptr = nums.begin() + nums.size() / 2;
        nth_element(nums.begin(), midptr, nums.end());
        int mid = *midptr;
        int n = nums.size();

        #define A(i) nums[(1+2*(i)) % (n|1)]

        /* 3-way-partition - 大的放在左边(偶数位置), 小的放在右边(奇数位置) */
        int i = 0, j = 0, k = n - 1;
        while (j <= k) {
            if (A(j) > mid) {
                swap(A(i), A(j));
                i++;
                j++;
            } else if (A(j) < mid) {
                swap(A(j), A(k));
                k--;
            } else {
                j++;
            }
        }
    }
};



class Solution {
public:
    void swap(vector<int> &nums, int i, int j) {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }

    void wiggleSort(vector<int>& nums) {
        /*
         * 快速选择 + 3-way-partition
         * nth_element()可以进行快速选择，将第n个小的元素放在数组的第n个位置
         * 同时保证其左边元素不大于自身，右边元素不小于自身
         * 找到中位数后，需要利用3-way-partition算法将中位数放中间，小数放左边，大数放右边
         * 然后将数组从中间等分为2个部分，然后反序，穿插，即可得到最终结果
         */
        auto midptr = nums.begin() + nums.size() / 2;
        nth_element(nums.begin(), midptr, nums.end());
        int mid = *midptr;

        /* 3-way-partition */
        int i = 0, j = 0, k = nums.size() - 1;
        while (j < k) {
            if (nums[j] > mid) {
                swap(nums, j, k);
                k--;
            } else if (nums[j] < mid) {
                swap(nums, i, j);
                j++;
                i++;
            } else {
                j++;
            }
        }

        /* 中间等分两个部分，反序穿插放回原数组 */
        if (nums.size() % 2)
            ++midptr;

        vector<int> nums1(nums.begin(), midptr);
        vector<int> nums2(midptr, nums.end());

        for (int i = 0; i < nums1.size(); i++) {
            nums[i * 2] = nums1[nums1.size() - i - 1];
        }

        for (int i = 0; i < nums2.size(); i++) {
            nums[i * 2 + 1] = nums2[nums2.size() - i - 1];
        }
    }
};

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        /* 先排序 - 再分别从前后拿入 */
        vector<int> up(nums);
        sort(up.begin(), up.end());

        int left = 0, right = nums.size() - 1;
        bool front = true;
        int idx = 0;

        while (left <= right) {
            if (front)
                nums[idx++] = up[left++];
            else
                nums[idx++] = up[right--];
            front = !front;
        }
    }
};
