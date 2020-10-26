



/* 自定义哈希函数 */
struct pair_hash
{
    template<class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2>& p) const
    {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1^h2;
    }
};

class Solution {
public:
    /* 记录位置和方向 */
    int curx, cury, pos;
    /* 网格边界 */
    int minx, miny, maxx, maxy;
    /* 哈希表记录位置和颜色 */
    unordered_map<pair<int, int>, int, pair_hash> color;
    /* 方向 - 右下左上 */
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, - 1}, {-1, 0}};

    /* 模拟 - 注意其实位置没有转向，直接往右走 -- 题目描述有歧义 */
    void move(vector<vector<int>> &dir, int k) {
        while (k--) {
            pair<int, int> tmp = make_pair(curx, cury);
            //cout << curx << " " << cury << " " << color[tmp] << endl;

            if (color[tmp] == 0) {
                /* 白色 - 顺时针90 */
                pos = (pos + 1) % 4;
            } else {
                /* 黑色 - 逆时针90 */
                pos = (pos + 3) % 4;
            }

            /* 反色 */
            color[tmp] ^= 1;
            /* 向前走一步 */
            curx += dir[pos][0];
            cury += dir[pos][1];
            /* 更新边界 */
            minx = min(minx, curx);
            miny = min(miny, cury);
            maxx = max(maxx, curx);
            maxy = max(maxy, cury);
            //cout << curx << " : " << cury << " " << color[tmp] << endl;
            //cout << minx << " " << miny << " " << maxx << " " << maxy << endl << endl;;
        }
    }

    vector<string> printKMoves(int K) {
        /*初始位置为{0， 0}*/
        curx = cury = 0;
        /* 面向右 */
        pos = 0;
        minx = miny = maxx = maxy = 0;

        if (K <= 0)
            return {"R"};

        move(dir, K);

        /* 确定网格大小并生成网格 */
        int m = maxx - minx + 1;
        int n = maxy - miny + 1;
        vector<string> res(m, string(n, '_'));

        /* 更新网格每个位置的颜色 */
        for (auto i : color) {
            res[i.first.first - minx][i.first.second - miny] = (i.second == 1 ? 'X' : '_');
        }

        /* 更新朝向 */
        res[curx - minx][cury - miny] = (pos == 0 ? 'R' : pos == 1 ? 'D' : pos == 2 ? 'L' : 'U');

        return res;
    }
};
