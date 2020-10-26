

class Solution {
public:
    vector<int> shortestSeq(vector<int>& big, vector<int>& small) {
        /* 滑动窗口 */
        vector<int> res;
        unordered_map<int, int> smallmap;
        unordered_map<int, int> bigmap;
        int minlen = INT_MAX, start = 0, valid = 0;
        int left, right, cur;

        /* 存放small对应的元素和数量，题目没有相同元素，为了不失一般性，还是统计每个元素的个数 */
        for (auto t : small)
            smallmap[t]++;

        left = right = 0;
        while (right < big.size()) {
            /* 右移right直到包含small中所有元素 */
            cur = big[right];
            right++;
            /* 注意: 如果cur不在map中，map[cur]访问会将cur加入map */
            //cout << right << " " << cur << " " << smallmap.count(cur) << endl;
            if (smallmap.count(cur) != 0) {
                bigmap[cur]++;
                if (bigmap[cur] == smallmap[cur])
                    valid++;

                while (valid == smallmap.size()) {
                    /* 找到small中所有元素，右移left寻找满足条件的最短子数组 */
                    //cout << left << " - " << right << " " << minlen << endl;
                    if (minlen > right - left) {
                        minlen = right - left;
                        start = left;
                    }

                    int cur = big[left];
                    left++;
                    if (smallmap.count(cur) != 0) {
                        if (bigmap[cur] == smallmap[cur])
                        /* 有small中相应元素移出窗口，更新bigmap和valid */
                            valid--;
                        bigmap[cur]--;
                    }
                }
            }
        }

        //cout << start << " " << minlen << endl;

        if (minlen != INT_MAX) {
            res.push_back(start);
            res.push_back(start + minlen - 1);
        }

        return res;
    }
};
