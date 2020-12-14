


/*
 * 随机获取 - 每个数值存入数组列表，随机产生一个索引即可
 * 随机删除 - 列表中顺序是没有关系的，删除元素时，可以将被删除的元素与列表的最后一个元素交换位置，即可O(1)内删除
 * 需要额外维护数值在列表中每一次出现的下标集合, 记下标集合为Sidx
 * 删除时找出val出现的任意一个下标i, 将nums[i]与nums[nums.length() - 1]交换。
 * 随后，将i从Sval中移除，将Snums[nums.length() - 1]原有的nums.length() - 1替换成i
 * 集合中每个操作都是O(1)的，总的平均时间复杂度也是O(1)的
 */
class RandomizedCollection {
public:
    unordered_map<int, unordered_set<int>> idx;
    vector<int> nums;

    /** Initialize your data structure here. */
    RandomizedCollection() {

    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        nums.push_back(val);
        idx[val].insert(nums.size() - 1);
        return idx[val].size() == 1;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (idx.find(val) == idx.end())
            return false;
        /* 取地一个做交换 */
        int i = *(idx[val].begin());
        nums[i] = nums.back();
        idx[val].erase(i);
        idx[nums[i]].erase(nums.size() - 1);
        if (i < nums.size() - 1)
            idx[nums[i]].insert(i);
        if (idx[val].size() == 0)
            idx.erase(val);
        nums.pop_back();
        return true;
    }

    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
