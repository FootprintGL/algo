
class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int> res;
        int len = rounds.size();
        int start = rounds[0], end = rounds[rounds.size() - 1];
        int i = start;

        /* 中间的圈数不会影响结果，只要考虑起点和重点的，注意重点比起点小的情况 */
        while (i != end) {
            res.push_back(i);
            i++;
            if (i == n + 1)
                i = 1;
        }
        res.push_back(end);
        sort(res.begin(), res.end());

        return res;
    }
};
