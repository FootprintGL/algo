

class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        /*
         * 动态规划
         * 本来的想法是从左到右检查，只要某个位置i的A[i]或B[i]不递增，就交换A[i]和B[i]，但发现并非最优解
         * A = {0,4,4,5,8} -交换A[2],B[2]-> {0,4,6,5,8} - 交换A[3],B[3]-> {0,4,6,7,8} (交换2次)
         * B = {0,1,6,7,9}                 {0,1,4,7,9}                   {0,1,4,5,9}
         * 实际上交换A[1],B[1]一次就可以使A,B递增
         * A = {0,4,4,5,8} -交换A[2],B[2]-> {0,1,4,5,8}
         * B = {0,1,6,7,9}                 {0,4,6,7,9}
         * A[i],B[i]交不交换之和他们前一位有关，题目保证有解，则有2中可能
         *      a. A[i] > A[i - 1] && B[i] > B[i - 1], 已经有序
         *      b. A[i] > B[i - 1] && B[i] > A[i - 1], 需要交换才能有序
         * 注意: a, b也可能同时满足
         * ch[i] noch[i] -> 表示位置i交换和不交换时的最小交换次数
         * 如果A[i] > A[i - 1] && B[i] > B[i - 1], 同时交换ch[i] = ch[i - 1] + 1, 同时不交换noch[i] = noch[i - 1]
         * 如果A[i] > B[i - 1] && B[i] > A[i - 1]，只交换i，ch[i] = noch[i - 1] + 1, 只交换i - 1, noch[i] = ch[i - 1]
         * 边界条件: ch[0] = 1, noch[0] = 0, 因为是求最小值ch, noch初始化为INT_MAX
         * 结果为min(ch[n - 1], noch[n - 1])
         */
        int n = A.size();
        vector<int> ch(n, INT_MAX);
        vector<int> noch(n, INT_MAX);
        int i;

        ch[0] = 1;
        noch[0] = 0;
        for (i = 1; i < n; i++) {
            if (A[i] > A[i - 1] && B[i] > B[i - 1]) {
                /* i，i - 1同时交换或不交换 */
                ch[i] = ch[i - 1] + 1;
                noch[i] = noch[i - 1];
            }
            /* 不是else if, 因为a, b两种条件也可能同时成立 */
            if (A[i] > B[i - 1] && B[i] > A[i - 1]) {
                /* 只交换i或i - 1 */
                ch[i] = min(ch[i], noch[i - 1] + 1);
                noch[i] = min(noch[i], ch[i - 1]);
            }
        }
/*
        for (i = 0; i < n; i++)
            cout << ch[i] << " ";
        cout << endl;

        for (i = 0; i < n; i++)
            cout << noch[i] << " ";
        cout << endl;
*/
        return min(ch[n - 1], noch[n - 1]);
    }
};
