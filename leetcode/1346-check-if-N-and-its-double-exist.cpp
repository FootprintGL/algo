

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> tbl;
        int zerocnt = 0;

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 0) {
                zerocnt++;
                if (zerocnt == 2)
                    /* 0是0的2倍 */
                    return true;
                /* 0不放入tbl */
                continue;
            }
            tbl.insert(arr[i] * 2);
        }

        for (auto a : arr)
            if (tbl.find(a) != tbl.end())
                return true;

        return false;
    }
};
