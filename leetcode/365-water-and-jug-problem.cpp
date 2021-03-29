
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        /*
         * 数学 - 最大公约数
         * 题目实际求一对数a,b使得ax + by = z
         * 根据贝组定律, ax + by = z有解，当且仅当z是x，y的最大公约数的倍数
         * 只要找到x,y的最大公约数并判断z是否是它的倍数即可
         */
        if (x + y < z)
            return false;

        if (x == 0 || y == 0)
            return z == 0 || z == x + y;
        
        return z % gcd(x, y) == 0;
    }
};





struct pair_hash {
    template<class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2>& p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1^h2;
    }
};

class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        /*
         * BFS
         * 问题的状态又X水壶中的水量和Y水壶中的水量
         * 可以有以下几种操作
         *      1 把X水壶的水倒进Y, 直到装满或倒空
         *      2 把Y水壶的水倒进X，直到装满或倒空
         *      3 把X倒满
         *      4 把Y倒满
         *      5 把X清空
         *      6 把Y清空
         * 需要哈希表记录已经出现的状态防止死循环
         */
        unordered_set<pair<int, int>, pair_hash> appeared;
        queue<pair<int, int>> qu;
        qu.push({0, 0});

        while (!qu.empty()) {
            pair<int, int> cur = qu.front();
            qu.pop();

            //cout << cur.first << " " << cur.second << " " << qu.size() << endl;

            if (appeared.count(cur))
                continue;

            appeared.insert(cur);

            if (cur.first == z || cur.second == z || cur.first + cur.second == z)
                return true;

            /* X倒满 */
            qu.push({x, cur.second});
            /* Y倒满 */
            qu.push({cur.first, y});
            /* X清空 */
            qu.push({0, cur.second});
            /* Y清空 */
            qu.push({cur.first, 0});
            /* X倒进Y */
            qu.push({cur.first - min(cur.first, y - cur.second), cur.second + min(cur.first, y - cur.second)});
            /* Y倒进X */
            qu.push({cur.first + min(cur.second, x - cur.first), cur.second - min(cur.second, x - cur.first)});
        }

        return false;
    }
};
