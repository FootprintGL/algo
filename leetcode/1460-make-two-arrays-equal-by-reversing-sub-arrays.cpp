
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        /* 数组一定可以通过翻转操作排序，只要2个数组元素相同即为true */
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());
        return target == arr;
    }
};
