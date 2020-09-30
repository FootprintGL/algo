

class Solution {
public:
    int breakfastNumber(vector<int>& staple, vector<int>& drinks, int x) {
        int m = staple.size(), n = drinks.size();
        int M = 1e9 + 7;
        int res = 0;
        int i, j = n - 1;

        /* 排序 + 双指针 */
        sort(staple.begin(), staple.end());
        sort(drinks.begin(), drinks.end());
        
        for (i = 0; i < m; i++) {
            while (j >= 0 && staple[i] + drinks[j] > x)
                j--;
            if (j == -1)
                break;
            res += j + 1;
            res %= M;
        }

        return res;
    }
};


/* 超时 */
class Solution {
public:
    int breakfastNumber(vector<int>& staple, vector<int>& drinks, int x) {
        int m = staple.size(), n = drinks.size();
        int M = 1e9 + 7;
        int res = 0;
        sort(staple.begin(), staple.end());
        sort(drinks.begin(), drinks.end());

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (staple[i] + drinks[j] <= x) {
                    res++;
                    res %= M;
                } else {
                    break;
                }
            }
        }

        return res;
    }
};
