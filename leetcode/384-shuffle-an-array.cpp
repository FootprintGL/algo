

class Solution {
public:
    /* 保存原始数组顺序 */
    vector<int> nums;
    /* 保持洗牌后的顺序 */
    vector<int> shuf;
    int n;

    Solution(vector<int>& nums) {
        this->nums = nums;
        shuf = nums;
        n = nums.size();
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums;
    }

    /*
     * Fisher-Yates洗牌算法
     * 每次迭代时，生成一个范围在0和当前下标之间的一个随机数
     * 接下来将当前元素和随机选出的元素进行交换 - 模拟洗牌的过程
     * 当前元素可以和它自身交换，保证完全随机
     */
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for (int i = n - 1; i >= 0; i--) {
            int index = rand() % (i + 1);
            //cout << i << " " << index << endl;
            swap(shuf[i], shuf[index]);
        }

        return shuf;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */

class Solution {
public:
    /* 保存原始数组顺序 */
    vector<int> nums;
    /* 保持洗牌后的顺序 */
    vector<int> shuf;
    /* 标记牌是否使用 */
    vector<bool> vis;
    int n;

    Solution(vector<int>& nums) {
        this->nums = nums;
        shuf = nums;
        n = nums.size();
        for (int i = 0; i < n; i++)
            vis.push_back(false);
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        /* 重置访问flag */
        for (int i = 0; i < n; i++)
            vis[i] = false;

        for (int i = 0; i < n; i++) {
            /* 找一个没有用过的index */
            int index = rand() % n;
            while (vis[index])
                index = rand() % n;
            /* 按顺序插入shuf */
            vis[index] = true;
            shuf[i] = nums[index];
        }

        return shuf;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
