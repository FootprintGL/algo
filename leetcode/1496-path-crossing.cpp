
class Solution {
public:
    struct pair_hash {
        template<class T1, class T2> std::size_t operator() (const std::pair<T1, T2>& p) const {
            auto h1 = std::hash<T1>{}(p.first);
            auto h2 = std::hash<T2>{}(p.second);
            return h1^h2;
        }
    };

    bool isPathCrossing(string path) {
        unordered_set<pair<int, int>, pair_hash> his;
        int x = 0, y = 0;
        /* 哈希表 */
        for (auto &d : path) {
            his.insert({x, y});
            if (d == 'N')
                y++;
            else if (d == 'S')
                y--;
            else if (d == 'E')
                x++;
            else
                x--;

            if (his.count({x, y}))
                return true;
        }

        return false;
    }
};
