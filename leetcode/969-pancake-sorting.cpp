

class Solution {
public:
    void dump(vector<int> &arr) {
        for (auto &a : arr)
            cout << a << " ";
        cout << endl;
    }

    vector<int> pancakeSort(vector<int>& arr) {
        /*
         * 找最大的翻转两次可以到正确位置
         * 第一次使它到第一的位置，第二次翻转归位
         * 题目要求翻转次数在10 * arr.length以内
         */
        vector<int> res;
        int k = 0, l = 0;
        while (l < arr.size()) {
            auto imax = max_element(arr.begin(), arr.end() - l);
            //cout << "imax " << *imax << " " << l << endl;
            if (imax + 1 == arr.end()) {
                l++;
                continue;
            }

            k = distance(arr.begin(), imax) + 1;
            //cout << "k " << k << " " << l << endl;
            if (k > 1) {
                /* 不在第一时才需要反转 */
                res.push_back(k);
                reverse(arr.begin(), imax + 1);
            }
            //cout << "1-rev: ";
            //dump(arr);

            /* 第二次翻转使第一个元素归位 */
            reverse(arr.begin(), arr.end() - l);
            res.push_back(arr.size() - l);
            //cout << "2-rev: ";
            //dump(arr);
            l++;
        }

        return res;
    }
};
