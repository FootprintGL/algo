
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
    bool robot(string command, vector<vector<int>>& obstacles, int x, int y) {
        //unordered_set<pair<int, int>, pair_hash> myset;
        unordered_set<long> myset;
        //pair<int, int> pos(0, 0);
        int index = 0, n = command.length();

        /*
         * 循环执行指令集
         * 先计算执行command一次向上和向右走了多少步，并保存经过的点
         * 可以推导出是否会经过位置{m, n}，loop = min(m/xx, n/yy)
         * {m, n}相当于第一圈的{m - loop * xx, n - loop * yy}
         * 如果要完好到达终点需要满足2个条件
         *     1. 第一次循环可以经过终点
         *     2. 第一次循环不能经过障碍
         * 可以用xx << 30 | yy作为key值
         */
        long xx = 0, yy = 0;

        /* 执行command保存经过的点和向右向上移动距离 */
        myset.insert(xx << 30 | yy);
        for (auto &c : command) {
            if (c == 'U')
                yy++;
            else
                xx++;
            myset.insert(xx << 30 | yy);
        }

        /* 检查能否经过终点 */
        int loop = min(x/xx, y/yy);
        if (myset.count(((x - loop * xx)<< 30) | (y - loop * yy)) == 0)
            return false;

        /* 检查是否会碰到障碍物 */
        for (auto &t : obstacles) {
            if (t.size() > 2)
                continue;
            if (t[0] > x || t[1] > y)
                continue;
            loop = min(t[0] / xx, t[1] / yy);
            if (myset.count(((t[0] - loop * xx) << 30) | (t[1] - loop * yy)))
                return false;
        }

        return true;
    }
};




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
    bool robot(string command, vector<vector<int>>& obstacles, int x, int y) {
        unordered_set<pair<int, int>, pair_hash> myset;
        pair<int, int> pos(0, 0);
        int index = 0, n = command.length();

        /*
         * 循环执行指令集
         * 先计算执行command一次向上和向右走了多少步，并保存经过的点
         * 可以推导出是否会经过位置{m, n}，loop = min(m/xx, n/yy)
         * {m, n}相当于第一圈的{m - loop * xx, n - loop * yy}
         * 如果要完好到达终点需要满足2个条件
         *     1. 第一次循环可以经过终点
         *     2. 第一次循环不能经过障碍
         */
        int xx = 0, yy = 0;

        /* 执行command保存经过的点和向右向上移动距离 */
        myset.insert({0, 0});
        for (auto &c : command) {
            if (c == 'U')
                yy++;
            else
                xx++;
            myset.insert({xx, yy});
        }

        /* 检查能否经过终点 */
        int loop = min(x/xx, y/yy);
        if (myset.count({x - loop * xx, y - loop * yy}) == 0)
            return false;

        /* 检查是否会碰到障碍物 */
        for (auto &t : obstacles) {
            if (t.size() > 2)
                continue;
            if (t[0] > x || t[1] > y)
                continue;
            loop = min(t[0] / xx, t[1] / yy);
            if (myset.count({t[0] - loop * xx, t[1] - loop * yy}))
                return false;
        }

        return true;
    }
};



/* 模拟超时 */
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
    bool robot(string command, vector<vector<int>>& obstacles, int x, int y) {
        unordered_set<pair<int, int>, pair_hash> myset;
        pair<int, int> pos(0, 0);
        int index = 0, n = command.length();

        /* 模拟 */
        for (auto &t : obstacles)
            myset.insert({t[0], t[1]});
        
        while (true) {
            while (index < n) {
                if (command[index] == 'U') {
                    /* 向上走一步 */
                    pos.second++;

                } else {
                    /* 向右走一步 */
                    pos.first++;
                }

                if (myset.count(pos) || pos.first > x || pos.second > y)
                /* 碰到障碍物或者越过目标位置 */
                    return false;
                
                if (pos.first == x && pos.second == y)
                    return true;

                index++;
            }
            /* 循环执行指令集command */
            index = 0;
        }

        return false;
    }
};

