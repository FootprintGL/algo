class Solution {
public:
    int sumNums(int n) {
        int sum = 0;

        /* 递归算法 - 利用逻辑与&&的阻断性质终止递归 */
        n && (sum = (sumNums(n - 1) + n));

        return sum;
    }
};
