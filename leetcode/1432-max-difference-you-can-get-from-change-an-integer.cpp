

class Solution {
public:
    int maxDiff(int num) {
        string tmp = to_string(num);
        int n = tmp.length(), i;
        int maxv, minv;
        char s, t;
        bool find = false;

        /* 计算可以得到最大的值 - 从左向右找到第一个不为9的值t，把所有的t都替换成9 */
        for (i = 0; i < n; i++) {
            if (!find && tmp[i] != '9') {
                s = tmp[i];
                t = '9';
                find = true;
            }

            if (find && tmp[i] == s)
                tmp[i] = t;
        }
        maxv = stoi(tmp, nullptr, 10);
        //cout << num << " " << maxv << " " << t << endl;

        /*
         * 计算可以得到的最小的值
         * 如果第一个t不为1且不为0的位置i
         * 如果i为0，则把所有的t都换成1
         * 如果i不为0，则把所有的t都换成0
         */
        tmp = to_string(num);
        find = false;
        for (i = 0; i < n; i++) {
            if (!find && tmp[i] != '1' && tmp[i] != '0') {
                s = tmp[i];
                if (i == 0)
                    t = '1';
                else
                    t = '0';
                find = true;
            }
            //cout << find << " " << i << " " << tmp[i] << " " << s << endl;
            if (find && tmp[i] == s) {
                tmp[i] = t;
            }
        }

        minv = stoi(tmp);

        //cout << num << " " << minv << " " << t << endl;

        /* 返回结果 */
        return maxv - minv;
    }
};
