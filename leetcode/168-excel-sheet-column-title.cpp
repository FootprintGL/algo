

class Solution {
public:
    string convertToTitle(int n) {
        string res;

        while (n) {
            /* 题目要求下标从1开始 1->A, 2->B,... */
            n--;
            int cur = n % 26;
            //cout << cur << " " << (char) (cur - 1 + 'A') << endl;
            res.insert(0, 1, (char)(cur + 'A'));
            n /= 26;
        }

        return res;
    }
};
