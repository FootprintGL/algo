
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        int i, j;

        for (i = 0; i < n; i++) {
            if (arr[i] == 0) {
                for (j = n - 1; j > i; j--)
                    arr[j] = arr[j - 1];
                /* 插入了一个0，坐标向右偏移一个 */
                i++;
            }
        }
    }
};
