

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> res;
        int cur = K, i = A.size();

        /* 加法模拟 */
        while (--i >= 0 || cur) {
            if (i >= 0)
                cur += A[i];
            
            res.insert(res.begin(), cur % 10);
            cur /= 10;
        }

        return res;
    }
};


class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> res;
        int i = A.size() - 1;
        int car = 0, cur, tmp;

        /* 加法模拟 - 注意进位处理 */
        while (i >= 0 && (K || car)) {
            cur = K % 10;
            tmp = cur + A[i] + car;

            if (tmp >= 10) {
                car = tmp / 10;
                tmp %= 10;
            } else {
                car = 0;
            }

            res.insert(res.begin(), tmp);
            K /= 10;
            i--;
        }

        while (i >= 0) {
            res.insert(res.begin(), A[i]);
            i--;
        }

        while (K || car) {
            cur = K % 10;
            tmp = cur + car;

            if (tmp >= 10) {
                car = tmp / 10;
                tmp %= 10;
            } else {
                car = 0;
            }

            res.insert(res.begin(), tmp);
            K /= 10;
        }

        return res;
    }
};
