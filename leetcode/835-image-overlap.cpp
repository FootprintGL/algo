class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int N = img1.size();
        int res = 0;
        
        /* 暴力 - 横方向可移动0 ~ N - 1, 纵方向上可移动0 ~ N - 1 */
        for (int i = 1 - N; i <= N - 1; i++) {
            for (int j = 1 - N; j <= N - 1; j++) {
                int cnt = 0;
                for (int p = 0; p < N; p++) {
                    for (int q = 0; q < N; q++) {
                        if (p + i >= 0 && p + i < N && q + j >= 0 && q + j < N) {
                            if (img1[p][q] == 1 && img2[p + i][q + j] == 1)
                                cnt++;
                        }
                    }
                }
                res = max(res, cnt);
            }
        }

        return res;
    }
};




/* 超时 */
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
unordered_set<pair<int, int>, pair_hash> myset;

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        /*
         * 让A中去所在的点去移到B中1所在的点，然后判断A中所有的1加上这段位移之后能否和B中的1重叠
         * A, B中1的位置存放到2个数组(vec1, vec2), 同时把B的位置加入哈希表加快搜索
         * 找到位移之后，如果vec1中每个元素加上这个位移在哈希表中，重叠加1
         * 边计算边统计最大值, 为了避免重复计算，把位移的delta也放入哈希表，跳过已经计算过的位移
         */
        int res = 0;
        int m = img1.size();
        int n = img1[0].size();
        vector<pair<int, int>> vec1;
        vector<pair<int, int>> vec2;
        /* m, n <= 30, 可以用row << 16 | col做key */
        unordered_set<pair<int, int>, pair_hash> deltaset;
        unordered_set<pair<int, int>, pair_hash> bset;
        int i, j;

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (img1[i][j]) {
                    vec1.push_back({i, j});
                }
                if (img2[i][j]) {
                    vec2.push_back({i, j});
                    bset.insert({i, j});
                }
            }
        }

        //cout << vec1.size() << " " << vec2.size() << " " << bset.size() << endl;

        for (auto &[r1, c1] : vec1) {
            for (auto &[r2, c2] : vec2) {
                int d1 = r2 - r1;
                int d2 = c2 - c1;
                //cout << r1 << " " << c1 << " " << r2 << " " << c2 << " " << d1 << " " << d2 << endl;
                /* 转换为无符号整形做移位操作 */
                if (!deltaset.count({d1, d2})) {
                    //cout << d1 << " * " << d2 << endl;
                    deltaset.insert({d1, d2});
                    int cnt = 0;
                    for (auto &[r, c] : vec1) {
                        if (r + d1 < 0 || r + d1 >= m || c + d2 < 0 || c + d2 >= n)
                            continue;
                        //cout << (r + d1) << " ** " << (c + d2) << endl;
                        if (bset.count({r + d1, c + d2}))
                            cnt++;
                    }
                    res = max(res, cnt);
                }
            }
        }

        return res;
    }
};

