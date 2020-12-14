


class Solution {
public:
    vector<int> drawLine(int length, int w, int x1, int x2, int y) {
        vector<int> res(length, 0);
        /* 每行多少个int */
        int row = w / 32;
        /* 线段头所在的int */
        int start = row * y + x1 / 32;
        /* 线段头所在的int左边需要空出0的个数 */
        int start_s = x1 % 32;
        /* 线段尾部所在的int */
        int end = row * y + x2 / 32;
        /* 线段尾部所在的int右边需要空出的0的个数 */
        int end_s = 31 - x2 % 32;

        /* 线段头到尾部置-1 */
        for (int i = start; i <= end; i++)
            res[i] = -1;

        if (start == end) {
            /* 线段头和尾部在同一个int */
            res[start] = (unsigned int)res[start] >> (start_s + end_s);
            res[end] = (unsigned int)res[end] << end_s;
        } else {
            res[start] = (unsigned int)res[start] >> start_s;
            res[end] = (unsigned int)res[end] << end_s;
        }

        return res;
    }
};
