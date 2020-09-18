
class Solution {
public:
    int findComplement(int num) {
        int cnt = 0;
        int tmp = num;
        while (tmp) {
            cnt++;
            tmp >>= 1;
        }

        return num ^= ((long)(1 << cnt) - 1);
    }
};


class Solution {
public:
    int findComplement(int num) {
        int idx = 0, mask = 0;
        int tmp = num;
        while (num) {
            //cout << num << " " << mask << endl;
            mask |= 1 << idx;
            idx++;
            num >>= 1;
        }

        //cout << num << " " << mask << endl;

        return tmp ^= mask;
    }
};
