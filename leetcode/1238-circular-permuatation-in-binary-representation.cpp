

class Solution {
public:
    void dump(vector<int> &arr) {
        for (auto &t : arr)
            cout << t << " ";
        cout << endl;
    }

    vector<int> circularPermutation(int n, int start) {
        /*
         * 格雷码
         * 1位格雷码两个数字{0, 1}
         * (n + 1)位格雷码的前2 ^ n个码字为n位格雷码字前面加0
         * (n + 1)位格雷码的后2 ^ n个码字为n位格雷码字前按逆序，前面加1
         * 先生成格雷码，找start的位置，再旋转数组
         */
        vector<int> res = {0, 1};

        /* 生成格雷码 */
        for (int i = 2; i <= n; i++) {
            for (int j = res.size() - 1; j >= 0; j--) {
                res.push_back(res[j] + (1 << (i - 1)));
            }
        }

        int size = res.size();
        int i;
        for (i = 0; i < size; i++) {
            if (res[i] == start)
                break;
        }

        /* 旋转数组使start为头 */
        //dump(res);
        reverse(res.begin(), res.end());
        //dump(res);
        reverse(res.begin(), res.end() - i);
        //dump(res);
        reverse(res.end() - i, res.end());
        //dump(res);

        return res;
    }
};
