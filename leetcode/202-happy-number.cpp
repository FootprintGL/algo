

class Solution {
public:
    bool isHappy(int n) {
        /* 哈希表记录历史，防止死循环 */
        unordered_set<int> hist;
        while (n != 1) {
            int s = 0;
            while(n) {
                int t = n % 10;
                s += t * t;
                n /= 10;
            }
            n = s;
            if (hist.count(s))
                break;
            else
                hist.insert(s);
        }
        return n == 1;
    }
};
