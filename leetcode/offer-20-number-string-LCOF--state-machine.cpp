

class Solution {
public:
    enum State {
        STATE_INITIAL,
        STATE_INT_SIGN,
        STATE_INTEGER,
        STATE_POINT,
        STATE_POINT_WITHOUT_INT,
        STATE_FRACTION,
        STATE_EXP,
        STATE_EXP_SIGN,
        STATE_EXP_NUMBER,
        STATE_END,
    };

    enum CharType {
        CHAR_NUMBER,
        CHAR_EXP,
        CHAR_POINT,
        CHAR_SIGN,
        CHAR_SPACE,
        CHAR_ILLEGAL,
    };

    CharType toCharType(char ch) {
        if (ch >= '0' && ch <= '9')
            return CHAR_NUMBER;
        else if (ch == 'e' || ch == 'E')
            return CHAR_EXP;
        else if (ch == '.')
            return CHAR_POINT;
        else if (ch == '+' || ch == '-')
            return CHAR_SIGN;
        else if (ch == ' ')
            return CHAR_SPACE;
        else
            return CHAR_ILLEGAL;
    }

    bool isNumber(string s) {
        /*
         * 有限状态机
         * 状态：
         *      1. 起始空格 INITIAL {' '}
         *      2. 符号 INT_SIGN {+/-}
         *      3. 整数部分 INTEGER (0->9)
         *      4. 左侧有整数的小数点 POINT(.)
         *      5. 左侧无整数的小数点 POINT_WITHOUT_INT (.)
         *      6. 小数部分 FRACTION (0->9)
         *      7. 指数部分 EXP (e/#)
         *      8. 指数部分符号位 EXP_SIGN (+/-)
         *      9. 指数部分的整数部分 EXP_NUMBER (0->9)
         *      10. 末尾的空格 END (' ')
         * 驱动事件
         *      1. 数字 NUMBER
         *      2. 指数 EXP
         *      3. 小数点 POINT
         *      4. 符号位 SIGN
         *      5. 空格 SPACE
         *      6. 非法字符 ILLEGAL
         *
         */
        unordered_map<State, unordered_map<CharType, State>> transfer {
            {
                STATE_INITIAL, {
                    {CHAR_SPACE, STATE_INITIAL},
                    {CHAR_NUMBER, STATE_INTEGER},
                    {CHAR_POINT, STATE_POINT_WITHOUT_INT},
                    {CHAR_SIGN, STATE_INT_SIGN},
                }
            }, {
                STATE_INT_SIGN, {
                    {CHAR_NUMBER, STATE_INTEGER},
                    {CHAR_POINT, STATE_POINT_WITHOUT_INT},
                }
            }, {
                STATE_INTEGER, {
                    {CHAR_NUMBER, STATE_INTEGER},
                    {CHAR_EXP, STATE_EXP},
                    {CHAR_POINT, STATE_POINT},
                    {CHAR_SPACE, STATE_END},
                }
            }, {
                STATE_POINT, {
                    {CHAR_NUMBER, STATE_FRACTION},
                    {CHAR_EXP, STATE_EXP},
                    {CHAR_SPACE, STATE_END},
                }
            }, {
                STATE_POINT_WITHOUT_INT, {
                    {CHAR_NUMBER, STATE_FRACTION},
                }
            }, {
                STATE_FRACTION, {
                    {CHAR_NUMBER, STATE_FRACTION},
                    {CHAR_EXP, STATE_EXP},
                    {CHAR_SPACE, STATE_END},
                }
            }, {
                STATE_EXP, {
                    {CHAR_NUMBER, STATE_EXP_NUMBER},
                    {CHAR_SIGN, STATE_EXP_SIGN},
                }
            }, {
                STATE_EXP_SIGN, {
                    {CHAR_NUMBER, STATE_EXP_NUMBER},
                }
            }, {
                STATE_EXP_NUMBER, {
                    {CHAR_NUMBER, STATE_EXP_NUMBER},
                    {CHAR_SPACE, STATE_END},
                }
            }, {
                STATE_END, {
                    {CHAR_SPACE, STATE_END},
                }
            }
        };

        State st = STATE_INITIAL;
        for (int i = 0; i < s.length(); i++) {
            if (transfer[st].find(toCharType(s[i])) == transfer[st].end())
                return false;
            else
                st = transfer[st][toCharType(s[i])];
        }

        return st == STATE_END || st == STATE_POINT || st == STATE_INTEGER || st == STATE_FRACTION || st == STATE_EXP_NUMBER;
    }
};
