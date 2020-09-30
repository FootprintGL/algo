
class Solution {
public:
    int convertInteger(int A, int B) {
        /* 转换为无符号数防止溢出 */
        unsigned int diff = A ^ B;
        int cnt = 0;
        cout << diff << endl;

        while (diff ) {
            diff &= diff - 1;
            cnt++;
        }

        return cnt;
    }
};
