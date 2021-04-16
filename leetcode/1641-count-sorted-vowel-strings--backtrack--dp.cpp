



class Solution {
public:
    int countVowelStrings(int n) {
        /*
         * 组合计数 - 隔板法
         * n个字符分配给五个元音所代表的盒子中，一旦每个盒子中的字符个数定了，那么字符串也就定了
         * 这是一个经典的数学问题，将n个小球放到m个盒子里，盒子可以为空
         * 1 先看看盒子不能为空的情况，n个小球排成一排，中间放m - 1个隔板，相当于n个小球分成了m份
         *   盒子不为空，两个小球之间不能放多个隔板，两端也不能放隔板，放隔板位置为n - 1个, 需要放置m - 1个隔板
         *   结果为C(n - 1, m - 1)
         * 2 允许盒子为空的情况，先假设给5个元音字母分配一个虚的位置，相当与有n + 5个球需要分配，然后用隔板法保证
         *   每个字母至少分配到一个位置 - 虚的位置保证每个字母必须分配一个, 插完隔板后把隔板抽掉。就是从n + 4个防治
         *   隔板的位置中选择4个 - C(n + 5 - 1, 5 - 1) = C(n + 4, 4)
         */
        return (n + 4) * (n + 3) * (n + 2) * (n + 1) / 24;
    }
};

class Solution {
public:
    int res;
    int index;

    void helper(int n, int start) {
        if (index == n) {
            res++;
            return;
        }

        for (int i = start; i < 5; i++) {
            index++;
            helper(n, i);
            index--;
        }
    }

    int countVowelStrings(int n) {
        /* 回溯算法 */
        res = 0;
        index = 0;

        helper(n, 0);

        return res;
    }
};
