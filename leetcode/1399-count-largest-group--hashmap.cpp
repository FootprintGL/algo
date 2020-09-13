
class Solution {
public:
    int sum(int n) {
        int res = 0;

        while (n > 0) {
            res += n % 10;
            n /= 10;
        }
        return res;
    }

    int countLargestGroup(int n) {
        int res = 0, maxlen = 0;
        unordered_map<int, vector<int>> mymap(36);

        /* 哈希表 */
        for (int i = 1; i <= n; i++)
            mymap[sum(i)].push_back(i);

        for (auto &t : mymap) {
            int size = t.second.size();
            if (size > maxlen) {
                maxlen = size;
                res = 1;
            } else if (size == maxlen) {
                res++;
            }
        }

        return res;
    }
};
