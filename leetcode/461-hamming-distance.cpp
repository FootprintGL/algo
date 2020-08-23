

class Solution {
public:
    int hammingDistance(int x, int y) {
        int dis = 0;
        int z = x ^ y;

        /* 统计异或结果1的个数 - 布赖恩·克尼根算法（Brain Kernighan）*/
        while (z) {
            z &= z - 1;
            dis++;
        }

        return dis;
    }
};
