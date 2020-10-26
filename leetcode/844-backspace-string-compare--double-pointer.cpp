class Solution {
public:
    string convert(string & s) {
        string stk;

        for (auto &c : s) {
            if (c == '#') {
                if (!stk.empty())
                    stk.pop_back();
            } else {
                stk.push_back(c);
            }
        }

        return stk;
    }

    bool backspaceCompare(string S, string T) {
        /* 堆栈 */
        return (convert(S) == convert(T));
    }
};


class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int len1 = S.length();
        int len2 = T.length();
        int i = len1 - 1, j = len2 - 1, k;
        int cnt = 0;

        /* 双指针 */
        while (i >= 0 || j >= 0) {
            cnt = 0;
            while (i >= 0) {
                /* 从后往前查找S能留下的有效字符 */
                if (S[i] == '#') {
                    /* 更新退格符数量 */
                    cnt++;
                } else {
                    if (cnt == 0)
                        /* 后面没有退格符, S[i]为有效字符 */
                        break;
                    /* 后面有退格符, 跳过S[i] */
                    cnt--;
                }
                i--;
            }

            cnt = 0;
            while (j >= 0) {
                /* 从后往前查找T能留下的有效字符 */
                if (T[j] == '#') {
                    /* 更新退格符数量 */
                    cnt++;
                } else {
                    if (cnt == 0)
                        /* 后面没有退格符, S[i]为有效字符 */
                        break;
                    /* 后面有退格符, 跳过S[i] */
                    cnt--;
                }
                j--;
            }

            if (i >= 0 && j >= 0 && S[i] != T[j])
                return false;

            /* 一个处理完了，一个没处理完 */
            if ((i >= 0) != (j >= 0))
                return false;

            /* 搜索处理下一个有效字符 */
            i--;
            j--;
        }
        
        return true;
    }
};



class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int len1 = S.length();
        int len2 = T.length();
        int i = len1 - 1, j = len2 - 1, k;
        int cnt = 0;

        /* 双指针 */
        while (i >= 0 && j >= 0) {
            cnt = 0;
            while (i >= 0) {
                /* 从后往前查找S能留下的有效字符 */
                if (S[i] == '#') {
                    /* 更新退格符数量 */
                    cnt++;
                } else {
                    if (cnt == 0)
                        /* 后面没有退格符, S[i]为有效字符 */
                        break;
                    /* 后面有退格符, 跳过S[i] */
                    cnt--;
                }
                i--;
            }

            /* 注意边界条件处理 */
            if (i < 0)
                break;

            cnt = 0;
            while (j >= 0) {
                /* 从后往前查找T能留下的有效字符 */
                if (T[j] == '#') {
                    /* 更新退格符数量 */
                    cnt++;
                } else {
                    if (cnt == 0)
                        /* 后面没有退格符, S[i]为有效字符 */
                        break;
                    /* 后面有退格符, 跳过S[i] */
                    cnt--;
                }
                j--;
            }
            //cout << i << " " << j << endl;
            /* 注意边界条件处理 */
            if (j < 0)
                break;

            if (S[i] != T[j])
                return false;

            /* 搜索处理下一个有效字符 */
            i--;
            j--;
        }

        //cout << i << "-" << j << endl;
        /* 检查剩下的是否能消除为空串，能则返回true，不能则返回false */
        cnt = 0;
        if (i >= 0) {
            while (i >= 0) {
                if (S[i] == '#') {
                    cnt++;
                } else {
                    if (cnt == 0)
                        return false;
                    cnt--;
                }
                 i--;
            }
        } else if (j >= 0) {
            while (j >= 0) {
                if (T[j] == '#') {
                    cnt++;
                } else {
                    if (cnt == 0)
                        return false;
                    cnt--;
                }
                j--;
            }
        }

        return true;
    }
};
