



class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        /* 记录当前最大亮起的灯，如果最大亮起的灯等于遍历过的等的数量，说明前面的灯都点亮了 */
        int res = 0;
        int imax = 0;

        for (int i = 0; i < light.size(); i++) {
            imax = max(imax, light[i]);
            if (imax == i + 1)
                res++;
        }

        return res;
    }
};

/* 超时 */
class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        /*
         * 左边全亮时才会亮蓝灯，维护一个cnt数组，记录每个位置左边亮灯的数目
         * 如果最右边的位置i，恰好左边有i盏灯，则全部亮绿灯
         */
        int res = 0;
        int max = 0;
        int n = light.size();
        vector<int> cnt(n, 0);

        cnt[light[0] - 1] = 1;
        max = light[0];
        if (light[0] == 1)
            res++;

        for (int i = 1; i < n; i++) {
            //cout << i << " " << light[i] << " " << max << " " << cnt[max - 1] << endl;
            if (light[i] > max) {
                for (int j = max; j < light[i]; j++) {
                    cnt[j] = cnt[max - 1] + 1;
                }
                max = light[i];
            } else {
                for (int j = light[i]; j < max; j++)
                    cnt[j]++;
            }

            //cout << max << " " << cnt[max - 1] << endl;
            if (cnt[max - 1] == max)
                res++;
        }

        return res;
    }
};
