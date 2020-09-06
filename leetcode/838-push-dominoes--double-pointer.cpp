

class Solution {
public:
    void replace(string &dominoes, int i, int j, char c) {
        for (int k = i; k <= j; k++) {
            dominoes[k] = c;
        }
    }

    string pushDominoes(string dominoes) {
        /*
         * 双指针
         * 以L,R为分界点一段一段处理l, r分别指向区间的左端和右端
         *      1. 以'.'开始的情况，l = 0, A[l] = '.'
         *          a. 如果A[r]为R，则0 -> r - 1不变，l = r
         *          b. 如果A[r]为L，则0 -> r - 1变为L, l = r
         *      2. A[l] = R, A[r] = R, 则l + 1 -> r - 1变为R
         *      3. A[l] = L, A[r] = L, 则l + 1-> r - 1变为L
         *      4. A[l] = L, A[r] = R, 则l + 1-> r - 1不变
         *      5. A[l] = R, A[r] = L, 则l + 1-> r - 1左半部分变R，右半部分变L，如果是奇数个，最中间那个不变
         *      6. 以‘.‘结尾的情况, r = len - 1， A[r] = '.'
         *          a. 如果A[l] = R, 则l + 1 -> r变成R
         *          b. 如果A[l] = L, 则l + 1 -> r不变
         *          c. 如果A[l] = '.', 则l + 1 -> r不变
         */
        int len = dominoes.length();
        int l = 0, r = 1, t;

        if (len <= 1)
            return dominoes;

        while (r < len) {
            if (dominoes[r] == '.') {
                if (r == len - 1 && dominoes[l] == 'R') {
                    replace(dominoes, l + 1, r, 'R');
                    break;
                }
                r++;
                continue;
            }
            if (dominoes[l] == '.' && dominoes[r] == 'L') {
                replace(dominoes, l, r - 1, 'L');
            } else if (dominoes[l] == 'R' && dominoes[r] == 'R') {
                replace(dominoes, l, r - 1, 'R');
            } else if (dominoes[l] == 'L' && dominoes[r] == 'L') {
                replace(dominoes, l, r - 1, 'L');
            } else if (dominoes[l] == 'R' && dominoes[r] == 'L') {
                t = r - l - 1;
                replace(dominoes, l + 1, l + (r - l - 1) / 2, 'R');
                replace(dominoes, r - (r - l - 1) / 2, r - 1, 'L');
            }
            l = r;
            r++;
        }

        return dominoes;
    }
};
