

class Solution {
public:
    int countbits(int label) {
        int cnt = 0;
        while (label) {
            cnt++;
            label >>= 1;
        }
        return cnt;
    }

    vector<int> pathInZigZagTree(int label) {
        /*
         * 如果按正常顺序构造完全二叉树
         * label/2为父节点，按之字形构建的话，父节点为label/2的对称节点
         * 如何求上一层的镜像节点
         * label/2 >> 1, 保持高位不变，其余位反转
         * 14 = 1110 -> 14 / 2 = 111 -> 100
         * 最高位标识所在层数，固定第一位其余数位范围从全0到全1
         * 镜像为和全1做异或操作求反
         */
        vector<int> res;

        while (label > 1) {
            res.insert(res.begin(), label);
            label >>= 1;
            label ^= (1 << (countbits(label) - 1)) - 1;
        }
        res.insert(res.begin(), 1);

        return res;
    }
};

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        /*
         * 如果按正常顺序构造完全二叉树
         * label/2为父节点，按之字形构建的话，父节点为label/2的对称节点
         * 假设上一层左右边界为left, right, label的父节点为left + right - label/2
         * 依次往上搜索直到根节点为止
         * 第N层的边界为2 ^ (N - 1)和2 ^ N - 1
         * 2 ^ (N - 1) + 2 ^ N - 1 = 2 ^ (N - 1) + 2 * 2 ^ (N- 1) - 1
         *       = 3 * 2 ^ (N - 1) - 1
         * 父节点为3 * 2 ^ (N - 1) - 1 + label / 2
         */
        vector<int> res;

        /* 求出label所在的层 */
        int n = 1;
        int level = 0;
        while (n <= label) {
            n <<= 1;
            level++;
        }

        /* 依次向上搜索知道根节点 */
        while (--level) {
            //cout << level << " " << label << endl;
            res.insert(res.begin(), label);
            label = 3 * pow(2, level - 1) - 1 - label / 2;
        }
        res.insert(res.begin(), 1);

        return res;
    }
};
