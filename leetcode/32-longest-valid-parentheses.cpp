class Solution {
public:
    int longestValidParentheses(string s) {
        int max = 0, n = s.size();
        stack<int> st;
        int i;

        if (n == 0)
            return 0;
        /*
         * 堆栈
         * 栈底存放最后一个未配对的’)’下标
         * 如果s[i]是‘(‘，下标直接压栈
         * 如果s[i]是‘)‘, 直接弹栈
         *    如果栈空，则下标入栈
         *    如果栈非空，则i-st.top()就是以是s[i]结尾的最长有效字串，更新最大值
         * 第一个字符为’(’,不满足栈底存放最后一个未匹配的')'的下标，开始时压入‘-1‘
         */
        st.push(-1);
        for (i = 0; i < n; i++) {
            if (s[i] == ')') {
                st.pop();
                if (st.empty())
                    st.push(i);
                else if (i - st.top() > max)
                    max = i - st.top();
            } else {
                st.push(i);
            }
        }

        return max;
    }
};


class Solution {
public:
    int longestValidParentheses(string s) {
        int max = 0, n = s.size();
        vector<int> dp (n + 1, 0);
        int i;

        if (n == 0)
            return 0;
        /*
         * 动态规划
         * dp[i] 表示s[i]结尾的子串包含的有效括号的长度
         * 如果s[i]为'(', dp[i] = 0 -> ‘(‘结尾i一律为非法括号
         * 如果s[i]为’)’并且s[i - 1]为'('
         *     s[i - 2]为')' 则dp[i] = dp[i - 2] + 2
         * 如果s[i]为’)’并且s[i - 1]为')'
         *     s[i - dp[i - 1] - 1]为‘(‘, 则dp[i] = dp[i - 1] + 2 + (dp[i - 1 - dp[i - 1] - 1])    -> "...((...))"
         *     s[i - dp[i - 1] - 1]为‘)‘, 则dp[i] = 0                                               -> "...)(...))"
         * 注意： 计算下标时有减法操作，需要注意下标结果为-1的越界情况
         *       dp[]数组初始化为0,所有对于dp[i]赋0的操作可以省略，简化代码
	 *       可以用问号表达式精简代码
         */
        for (i = 1; i < n; i++) {
            if (s[i] != '(') {
                if (s[i - 1] == '(')
                    dp[i] = (i >=2 ? dp[i - 2] : 0) + 2;
                else if (i - 1 - dp[i - 1] >= 0 && s[i - 1 - dp[i - 1]] == '(')
                    dp[i] = (i - dp[i - 1] >= 2 ? dp[i - dp[i - 1] - 2] : 0) + dp[i - 1] + 2;
            }
            if (dp[i] > max)
                max = dp[i];
        }

        return max;
    }
};


class Solution {
public:
    int longestValidParentheses(string s) {
        int max = 0, n = s.size();
        vector<int> dp (n + 1, 0);
        int i;

        if (n == 0)
            return 0;
        /*
         * 动态规划
         * dp[i] 表示s[i]结尾的子串包含的有效括号的长度
         * 如果s[i]为'(', dp[i] = 0 -> ‘(‘结尾i一律为非法括号
         * 如果s[i]为’)’并且s[i - 1]为'('
         *     s[i - 2]为')' 则dp[i] = dp[i - 2] + 2
         * 如果s[i]为’)’并且s[i - 1]为')'
         *     s[i - dp[i - 1] - 1]为‘(‘, 则dp[i] = dp[i - 1] + 2 + (dp[i - 1 - dp[i - 1] - 1])    -> "...((...))"
         *     s[i - dp[i - 1] - 1]为‘)‘, 则dp[i] = 0                                               -> "...)(...))"
         * 注意： 计算下标时有减法操作，需要注意下标结果为-1的越界情况
         *       dp[]数组初始化为0,所有对于dp[i]赋0的操作可以省略，简化代码
         */
        for (i = 1; i < n; i++) {
            if (s[i] != '(') {
                if (s[i - 1] == '(') {
                    dp[i] = 2;
                    if (i - 2 >= 0)
                        dp[i] += dp[i - 2];
                } else if (i - 1 - dp[i - 1] >= 0 && s[i - 1 - dp[i - 1]] == '(') {
                    dp[i] = dp[i - 1] + 2;
                    if (i - 1 - dp[i - 1] - 1 >= 0)
                        dp[i] += dp[i - 1 - dp[i - 1] - 1];
                }
            }
            if (dp[i] > max)
                max = dp[i];
        }

        return max;
    }
};


class Solution {
public:
    int longestValidParentheses(string s) {
        int max = 0, n = s.size();
        vector<int> dp (n + 1, 0);
        int i;

        if (n == 0)
            return 0;
        /*
         * 动态规划
         * dp[i] 表示s[i]结尾的子串包含的有效括号的长度
         * 如果s[i]为'(', dp[i] = 0 -> ‘(‘结尾i一律为非法括号
         * 如果s[i]为’)’并且s[i - 1]为'('
         *     s[i - 2]为')' 则dp[i] = dp[i - 2] + 2
         * 如果s[i]为’)’并且s[i - 1]为')'
         *     s[i - dp[i - 1] - 1]为‘(‘, 则dp[i] = dp[i - 1] + 2 + (dp[i - dp[i - 1] - 1])    -> "...((...))"
         *     s[i - dp[i - 1] - 1]为‘)‘, 则dp[i] = 0                                      -> "...)(...))"
         * 注意： 计算下标时有减法操作，需要注意下标结果为-1的越界情况
         */
        for (i = 1; i < n; i++) {
            if (s[i] == '(') {
                dp[i] = 0;
            } else {
                if (s[i - 1] == '(') {
                    if (i >= 2)
                        dp[i] = dp[i - 2] + 2;
                    else
                        dp[i] = 2;
                } else {
                    if (i - 1 - dp[i - 1] >= 0 && s[i - 1 - dp[i - 1]] == '(') {
                        if (i - 1 - dp[i - 1] - 1 >= 0)
                            dp[i] = dp[i - 1] + 2 + dp[i - 1 - dp[i - 1] - 1];
                        else
                            dp[i] = dp[i - 1] + 2;
                    }
                    else
                        dp[i] = 0;
                }
            }

            if (dp[i] > max)
                max = dp[i];
        }

        return max;
    }
};


class Solution {
public:
    int longestValidParentheses(string s) {
        int max = 0, n = s.size();
        vector<int> dp (n + 1, 0);
        int i;

        if (n == 0)
            return 0;
        /*
         * 动态规划
         * dp[i + 1] 表示s[i]结尾的子串包含的有效括号的长度
         * 如果s[i]为'(', dp[i + 1] = 0 -> ‘(‘结尾i一律为非法括号
         * 如果s[i]为’)’并且s[i - 1]为'('
         *     s[i - 2]为')' 则dp[i + 1] = dp[i - 1] + 2
         * 如果s[i]为’)’并且s[i - 1]为')'
         *     s[i - dp[i - 1] - 1]为‘(‘, 则dp[i + 1] = dp[i] + 2 + (dp[i + 1 - dp[i] - 1])    -> "...((...))"
         *     s[i - dp[i - 1] - 1]为‘)‘, 则dp[i + 1] = 0                                      -> "...)(...))"
         * 注意： 计算下标时有减法操作，需要注意下标结果为-1的越界情况
         */
        for (i = 1; i < n; i++) {
            if (s[i] == '(') {
                dp[i + 1] = 0;
            } else {
                if (s[i - 1] == '(') {
                        dp[i + 1] = dp[i - 1] + 2;                    
                } else {
                    if (i - 1 - dp[i] >= 0 && s[i - 1 - dp[i]] == '(')
                        dp[i + 1] = dp[i] + 2 + dp[i - dp[i] - 1];
                    else
                        dp[i + 1] = 0;
                }
            }

            if (dp[i + 1] > max)
                max = dp[i + 1];
        }

        return max;
    }
};
