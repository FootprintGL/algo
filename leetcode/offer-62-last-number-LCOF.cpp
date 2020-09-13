
class Solution {
public:
    int lastRemaining(int n, int m) {
        /*
         * 约瑟夫
         * f(n, m) - n个元素，每隔m个元素进行环形删除，最后剩下的那个元素的索引号 
         * f(n, m) = 0, n == 1
         * f(n, m) = {f(n - 1, m) + m} % n, n > 1
         * n代表当前人数，n代表的是报数
         * 假设一共11个人，干掉报3的人最后那个胜利的人下表是6 (n = 11, m = 3)
         * 在下一轮10个人的时候，胜利者的编号往前移了3个 (n = 10, m = 3)
         * 假设有10个人，胜利者的下标为3，到11的人胜利者的下标向右移了3变成6
         * 递推公式为: f(n) = (f(n - 1) + m) % n
         */
        int pos = 0;

        for (int i = 2; i <= n; i++) {
            pos = (pos + m) % i;
        }

        return pos;
    }
};


/* 超时 */
class Solution {
public:
    int lastRemaining(int n, int m) {
        vector<int> nums(n, 0);

        for (int i = 0; i < n; i++)
            nums[i] = i;

        int start = 0;
        while (n > 1) {
            start = (start + m % nums.size() - 1 + nums.size()) % nums.size();
            //cout << start << " " << nums[start] << endl;
            nums.erase(nums.begin() + start);
            n--;
        }
        cout << n << endl;

        return nums[0];
    }
};
