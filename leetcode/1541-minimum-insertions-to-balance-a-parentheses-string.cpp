class Solution {
public:
    int minInsertions(string s) {
        /*
         * 模拟
         * 如果遇到左括号，cnt加一，下标加一
         * 如果遇到右括号
         *      1 和前面的左括号匹配，如果左括号个数大于0，说明可以匹配，否则，需要插入一个左括号, insertion++
         *      2 确保有两个右括号，如果后面一个是右括号，下标加2，否则插入一个有括号, insertion++
         */
        int cnt = 0;
        int insertion = 0;
        int n = s.length();
        int idx = 0;

        while (idx < n) {
            if (s[idx] == '(') {
                cnt++;
                idx++;
            } else {
                if (cnt > 0) {
                    cnt--;
                } else {
                    /* 前面没有左括号，需要插入一个 */
                    insertion++;
                }
                if (idx < n - 1 && s[idx + 1] == ')') {
                    /* 后面是右括号，直接配对，跳过下一个 */
                    idx += 2;
                } else {
                    /* 后面没有右括号，需要插入一个 */
                    insertion++;
                    idx++;
                }
            }
        }

        insertion += 2 * cnt;

        return insertion;
    }
};



class Solution {
public:
    int minInsertions(string s) {
        /*
         * 栈
         * 如果为‘(‘, 直接入栈
         *      1 如果有一个')', 加一个')'构成'())'
         *      2 如果有两个‘)‘且栈为空，加一个’(’构成‘())‘
         * 最后剩下的'(', 每一个添加两个’)’分别构成'())'
         */
        int res = 0;
        string stk;

        /* 累计连续的')'数量 */
        int cnt = 0;
        for (auto &c : s) {
            if (c == '(') {
                if (cnt == 1) {
                    /* 前面有一个')' */
                    if (stk.empty()) {
                        /* 需要加一个'('和一个')' */
                        res += 2;
                    } else {
                        /* 加一个’)’和栈里的一个'('配对 */
                        res++;
                        stk.pop_back();
                    }
                    /* '('入栈 */
                    cnt = 0;
                }
                stk += c;
            } else {
                cnt++;
                if (cnt == 2) {
                    /* 连续两个')' */
                    if (stk.empty())
                        /* 需要添加一个‘(‘ */
                        res++;
                    else
                        /* 弹出一个'('配对 */
                        stk.pop_back();
                    /* 重置cnt */
                    cnt = 0;
                }
            }
        }

        if (cnt == 1) {
            /* 如果最后都是')'，比如")))"剩下的一个')' */
            if (stk.empty()) {
                /* 需要添加一个'('和一个')'配对 */
                res += 2;
            } else {
                /* 需要添加一个')'和栈上的一个'('配对 */
                res++;
                stk.pop_back();
            }
        }

        /* 剩下的每个'('需要两个')'进行配对 */
        res += stk.size() * 2;

        return res;
    }
};
