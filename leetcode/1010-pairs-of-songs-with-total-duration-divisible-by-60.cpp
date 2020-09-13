
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        /* 哈希表 */
        unordered_map<int, int> mymap;
        int cnt = 0;

        mymap[time[0] % 60]++;
        for (int i = 1; i < time.size(); i++) {
            cnt += mymap[(60 - time[i] % 60) % 60];
            mymap[time[i] % 60]++;
        }

        return cnt;
    }
};

/* 超时 */
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        /* 暴力 */
        int cnt = 0;

        for (int i = 0; i < time.size(); i++) {
            for (int j = i + 1; j < time.size(); j++) {
                if ((time[i] + time[j]) % 60 == 0)
                    cnt++;
            }
        }

        return cnt;
    }
};
