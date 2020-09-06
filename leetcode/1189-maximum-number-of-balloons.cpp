
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        /* 分别统计b,a,l,o,n个数，看最多能组成多少个ballon */
        int ca = 0, cb = 0, cl = 0, cn = 0, co = 0;
        for (auto &c : text) {
            if (c == 'a')
                ca++;
            else if (c == 'b')
                cb++;
            else if (c == 'l')
                cl++;
            else if (c == 'n')
                cn++;
            else if (c == 'o')
                co++;
        }

        //cout << ca << " " << cb << " " << cl << " " << cn << " " << co << endl;

        return min(min(min(min(ca, cb), cl / 2), cn), co / 2);
    }
};
