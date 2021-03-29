


/*
 * 所有可能的点从1开始编号，直接随机编号就可以了，这样可以保证概率均匀
 * 首先通过编号判断在哪个矩形里面，利用前缀和方式存取矩形里面的节点个数
 * 这样可以通过二分直接查得编号在哪个矩形里面，之后再用类似二维矩阵的编码方式
 * [i][j] = row * i + j找到对应的点
 */
class Solution {
    vector<int> prefix;
    vector<vector<int>> rects;
public:
    Solution(vector<vector<int>>& rects) {
        this->rects = rects;
        prefix.reserve(rects.size());
        /* 计算前缀和 */
        for (auto &r : rects) {
            int cur = (r[2] - r[0] + 1) * (r[3] - r[1] + 1);
            if (!prefix.empty()) {
                prefix.push_back(cur + prefix.back());
            } else {
                prefix.push_back(cur);
            }
        }
        //cout << prefix.back() << " " << prefix.size() << " " << rects.size() << endl;
    }

    vector<int> pick() {
        /* rand() * (b - a + 1) + a表示a~b之间取一个随机数 */
        int idx = rand() % prefix.back() + 1;
        int pos = lower_bound(prefix.begin(), prefix.end(), idx) - prefix.begin();
        int startidx;
        //cout << idx << " " << pos << endl;
        if (pos == 0)
            startidx = 1;
        else
            startidx = prefix[pos - 1] + 1;
        int row = rects[pos][2] - rects[pos][0] + 1;
        int col = rects[pos][3] - rects[pos][1] + 1;
        int i = (idx - startidx) / row;
        int j = idx - startidx - i * row;

        return {rects[pos][0] + j, rects[pos][1] + i};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
