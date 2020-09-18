

class Solution {
public:
    /* pair需要定义hash函数 */
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

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<pair<int, int>, pair_hash> myset;
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        int ans = 0;
        int x = 0, y = 0;
        int nx, ny;
        int i, idx = 0;

        /* set保持障碍物坐标，每次走完步数或停在障碍物前面 */
        for (auto &obs : obstacles)
            myset.insert(make_pair(obs[0], obs[1]));

        for (auto &cmd : commands) {
            if (cmd == -2) {
                /* 左转90度 */
                idx = (idx + 3) % 4;
            } else if (cmd == -1) {
                /* 右转90度 */
                idx = (idx + 1) % 4;
            } else {
                for (i = 0; i < cmd; i++) {
                    nx = x + dx[idx];
                    ny = y + dy[idx];
                    if (!myset.count(make_pair(nx, ny))) {
                        /* (nx, ny)没有障碍物可以走 */
                        x = nx;
                        y = ny;
                        ans = max(ans, x * x + y * y);
                    } else {
                        /* (nx, ny)有障碍物，停在(x,y)处理下一条命令 */
                        break;
                    }
                }
            }
        }

        return ans;
    }
};
