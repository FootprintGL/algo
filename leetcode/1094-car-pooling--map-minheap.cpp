

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        /*
         * 按上下车地点排序，如果超载则返回false，否则返回true
         */
        map<int, int> tbl;

        for (auto &tmp : trips) {
            tbl[tmp[1]] += tmp[0];
            tbl[tmp[2]] -= tmp[0];
        }

        int passengers = 0;
        for (auto &it : tbl) {
            passengers += it.second;
            if (passengers > capacity)
                return false;
        }

        return true;
    }
};
