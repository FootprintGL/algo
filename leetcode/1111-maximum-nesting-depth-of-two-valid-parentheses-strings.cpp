

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        /*
         * 栈
         * 划分出使得最大嵌套深度最小的分组
         * 嵌套深度，维护一个栈，从左到右遍历字符串
         *      如果为‘(‘，压栈，此时栈的高度为嵌套深度
         *      如果为')',此时这个')'的嵌套深度为栈的高度,随后弹出一个'('
         * 只要保证栈内一半的’(’属于A，另一半属于B，就能保证拆分后的最大嵌套深度最小
         * 可以把奇数层分给A，偶数层分给B即可
         */
        vector<int> res;
        int d = 0;

        for (auto &c : seq) {
            if (c == '(') {
                d++;
                res.push_back(d % 2);
            } else {
                res.push_back(d % 2);
                d--;
            }
        }

        return res;
    }
};
