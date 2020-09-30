

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int, vector<int>> tbl;
        set<int> myset;
        int i, n = arr.size();

        /* 哈希表 - map存放元素到位置坐标的映射，有序set进行去重排序 */
        for (i = 0; i < n; i++) {
            tbl[arr[i]].push_back(i);
            myset.insert(arr[i]);
        }

        int start = 1;
        for (auto &a : myset) {
            for (i = 0; i < tbl[a].size(); i++) {
                arr[tbl[a][i]] = start;
            }
            start++;
        }

        return arr;
    }
};
