


class Solution {
public:
    string predictPartyVictory(string senate) {
        /*
         * 贪心 - 模拟
         * 只要后面有其他阵营的议员就禁止他投票，最后剩下的阵营为获胜阵营
         * 每个议员不需要在轮到自己的时候就立即使用禁令，可以等到另一个阵营的议员投票时使用
         * 使用禁令时把禁止投票的议员设为B
         */
        int n = senate.size();
        int cntr = 0, cntd = 0;
        int banr = 0, band = 0;

        while (1) {
            /* 循环投票直到结束 */
            for (int i = 0; i < n; i++) {
                if (senate[i] == 'R') {
                    if (banr == 0) {
                        /* R阵营没有禁令，则给D阵营一个禁令 */
                        band++;
                    } else {
                        /* R阵营有禁令，禁掉该议员 */
                        banr--;
                        senate[i] = 'B';
                    }
                } else if (senate[i] == 'D') {
                    if (band == 0) {
                        /* D阵营没有禁令，给R阵营一个禁令 */
                        banr++;
                    } else {
                        /* D阵营有禁令，禁掉该议员 */
                        band--;
                        senate[i] = 'B';
                    }
                }
            }

            int r = count(senate.begin(), senate.end(), 'R');
            int d = count(senate.begin(), senate.end(), 'D');
            if (r == 0)
                /* 只剩下D阵营议员 */
                return "Dire";
            if (d == 0)
                /* 只剩下R阵营议员 */
                return "Radiant";
        }
    }
};
