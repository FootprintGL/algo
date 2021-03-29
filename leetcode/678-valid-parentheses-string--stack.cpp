


class Solution {
public:
    bool checkValidString(string s) {
        /*
         * 贪心
         * 统计左括号至少几个，至多几个 
         * 遇到左括号，至少至多都增加
         * 遇到右括号，至少至多都减少
         * 遇到星号，可能减少/不变/增加, 至少减少，至多增加
         * 若至少小于0
         */
        int cmin = 0, cmax = 0;

        for (auto &c : s) {
            if (c == '(') {
                cmin++;
                cmax++;
            } else if (c == ')'){
                if (cmin > 0)
                    cmin--;
                cmax--;
                if (cmax < 0)
                /* 左括号不够匹配 */
                    return false;
            } else {
                if (cmin > 0)
                /* 做右括号 */
                    cmin--;
                /* 做左括号 */
                cmax++;
            }
        }

        return cmin == 0;
    }
};

class Solution {
public:
    bool checkValidString(string s) {
        /*
         * 双堆栈
         * 堆栈存放的是索引，一个存放左括号，一个存放右括号
         * 遍历过程中，同时判断是否有足够的右括号使他们出栈，优先抵消左括号(贪心)
         * 两栈同时出栈，要求所有的左括号，都有其右边索引的星号能使其抵消
         * 左括号不能有剩余
         */
        stack<int> lefts;
        stack<int> stars;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                lefts.push(i);
            } else if (s[i] == '*') {
                stars.push(i);
            } else {
                /* 优先和左括号配对 */
                if (!lefts.empty())
                    lefts.pop();
                else if (!stars.empty())
                    stars.pop();
                else
                    return false;
            }
        }

        while (!lefts.empty() && !stars.empty()) {
            /* 星号索引大于等于左括号索引 */
            if (lefts.top() > stars.top())
                return false;
            lefts.pop();
            stars.pop();
        }

        /* 不能有剩余的左括号 */
        return lefts.empty();
    }
};
