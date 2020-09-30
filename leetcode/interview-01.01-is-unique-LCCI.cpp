
class Solution {
public:
    bool isUnique(string astr) {
        /* 位运算: a - bit 1, b - bit 2, c bit3 */
        int mask = 0;

        for (auto &c : astr) {
            if (1 << (c - 'a') & mask)
                return false;
            mask |= 1 << (c - 'a');
        }

        return true;
    }
};
