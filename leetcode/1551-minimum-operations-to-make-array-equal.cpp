

class Solution {
public:
    int minOperations(int n) {
        /*
         * 找出平均数, 以它为中轴，左右两边的数据分别+1/-1往平均数靠拢
         * 结果为平均数左边的数和平均数距离之和
         */
        int sum = 0;
        int res = 0;

        for (int i = 0; i < n; i++)
            sum += 2 * i + 1;

        int aver = sum / n;
        for (int i = 0; (2 * i) + 1 < aver; i++) {
            //cout << i << " " << (2 * i + 1) << " " << aver << " " << res << endl;
            res += aver - (2 * i + 1);
        }

        return res;
    }
};
