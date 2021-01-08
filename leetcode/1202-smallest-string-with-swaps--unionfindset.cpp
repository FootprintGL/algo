


class Solution {
public:
    static const int N = 1e5 + 5;
    std::set<int> st[N];
    std::unordered_set<int> roots;

    int fa[N];
    void init(const int &n) {
        for (int i = 0; i < n; ++i) fa[i] = i;
    }
    int find_union(const int &x) {
        return fa[x] == x? x: fa[x] = find_union(fa[x]);
    }

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        init(n);
        for (const auto &ch: pairs) {
            int u = ch[0], v = ch[1];
            int pu = find_union(u);
            int pv = find_union(v);
            if (pu != pv) {
                fa[pu] = pv;
            }
        }
        for (int i = 0; i < n; ++i) {
            int root = find_union(i);
            roots.insert(root);
            st[root].insert(i);
        }

        for (const auto &root: roots) {
            std::string str;
            for (const auto &ch: st[root]) {
                str += s[ch];
            }
            std::sort(str.begin(), str.end());
            int cnt = 0;
            for (const auto &ch: st[root]) {
                s[ch] = str[cnt++];
            }
        }
        return s;
    }
};


/* 并查集 - 超时 */
class DSU {
    vector<int> parent;

public:
    DSU(int n) {
        for (int i = 0; i < n; i++)
            parent.push_back(i);
    }

    void merge(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {
            parent[rootx] = rooty;
        }
    }

    int find(int x) {
        return x == parent[x] ? x : find(parent[x]);
    }
};


class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        /*
         * 并查集
         * 查找所有可交换位置的集合,排序每个集合内的字符,再查回原字符串
         */
        unordered_map<int, set<int>> mymap;
        int n = s.length();

        /* 构建并查集 */
        DSU dsu(n);
        for (auto &p : pairs) {
            dsu.merge(p[0], p[1]);
        }

        /* 集合放入哈希表 - 键为集合root，键值为root下的集合元素 */
        for (int i = 0; i < n; i++)
            mymap[dsu.find(i)].insert(i);

        for (auto &t : mymap) {
            string str;
            /* 提取集合里每个位置的字母 */
            for (auto &c : t.second)
                str += s[c];
            /* 排序后依次放回 - set内位置坐标自身有序，这样可以获得字典序最小的字符串 */
            sort(str.begin(), str.end());
            int cnt = 0;
            for (auto &c : t.second)
                s[c] = str[cnt++];
        }

        return s;
    }
};
