
/* 并查集 */
class DSU {
    vector<int> parent;

public:
    DSU(int n) {
        for (int i = 0; i < n; i++) {
            parent.push_back(i);
        }
    }

    int find(int x) {
        return x == parent[x] ? x : find(parent[x]);
    }

    void merge(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        if (rx != ry)
            parent[rx] = ry;
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        DSU dsu(26);

        /* 并查集 */
        for (auto &str : equations) {
            if (str[1] == '=')
            /* 等式具有传递性 - 合并 */
                dsu.merge(str[0] - 'a', str[3] - 'a');
        }
        
        for (auto &str : equations) {
            if (str[1] == '!' && dsu.find(str[0] - 'a') == dsu.find(str[3] - 'a'))
            /* 不等式两端属于相同集合 */
                return false;
        }

        return true;
    }
};


/* https://www.jianshu.com/p/b37ba1f7d45c */
/* https://segmentfault.com/a/1190000004023326 */

class Solution {
public:
    /* 处理等式，并入集合 */
    void createset(char c, char d, vector<set<char>> &myset) {
        set<char> res;
        int len = myset.size();
        int ci = len, di = len;
        int i;

        /* 在集合中查找c，d，并保存集合index到ci, di */
        for (i = 0; i < len; i++) {
            if (myset[i].find(c) != myset[i].end()) {
                ci = i;
            }
            if (myset[i].find(d) != myset[i].end()) {
                di = i;
            }
        }

        if (ci == len) {
            if (di == len) {
                /* 都没找到 - c和d加入新集合 */
                res.insert(c);
                res.insert(d);
                myset.push_back(res);
            } else {
                /* 只找到d - 把c并入集合di */
                myset[di].insert(c);
            }
        } else {
            if (di == len) {
                /* 只找到c - 把d并入集合ci */
                myset[ci].insert(d);
            } else {
                if (ci != di) {
                    /* 找到c和d - 并入元素多的结合 */
                    if (ci > di) {
                        myset[ci].insert(myset[di].begin(), myset[di].end());
                        myset.erase(myset.begin() + di);
                    } else {
                        myset[di].insert(myset[ci].begin(), myset[ci].end());
                        myset.erase(myset.begin() + ci);
                    }
                }
            }
        }
    }

    /* 处理不等式 - 检查可能性 */
    bool ispossible(char c, char d, vector<set<char>> &myset) {
        set<char> res;
        int len = myset.size();
        int ci = len, di = len;
        int i;

        /* 在集合中查找c,d的index */
        for (i = 0; i < len; i++) {
            if (myset[i].find(c) != myset[i].end()) {
                ci = i;
            }
            if (myset[i].find(d) != myset[i].end()) {
                di = i;
            }
        }

        /* 如果c和d属于不同的集合 - 不可能 */
        return !(ci != len && di != len && ci == di);
    }

    bool equationsPossible(vector<string>& equations) {
        vector<set<char>> myset;
        int len = equations.size();
        int i;

        /* 遍历所有等式，建立集合 */
        for (i = 0; i < len; i++) {
            if (equations[i][1] == '=') {
                createset(equations[i][0], equations[i][3], myset);
            }
        }

        /* 便利所有不等式，检查其可能性 */
        for (i = 0; i < len; i++) {
            if (equations[i][1] == '!') {
                if (equations[i][0] == equations[i][3])
                    return false;
                if (!ispossible(equations[i][0], equations[i][3], myset))
                    return false;
            }
        }

        return true;
    }
};



class Solution {
public:
    /* 处理等式，并入集合 */
    void createset(char c, char d, vector<set<char>> &myset) {
        set<char> res;
        int len = myset.size();
        int ci = len, di = len;
        int i;

        /* 在集合中查找c，d，并保存集合index到ci, di */
        for (i = 0; i < len; i++) {
            if (myset[i].find(c) != myset[i].end()) {
                ci = i;
            }
            if (myset[i].find(d) != myset[i].end()) {
                di = i;
            }
        }

        if (ci == len) {
            if (di == len) {
                /* 都没找到 - c和d加入新集合 */
                res.insert(c);
                res.insert(d);
                myset.push_back(res);
            } else {
                /* 只找到d - 把c并入集合di */
                myset[di].insert(c);
            }
        } else {
            if (di == len) {
                /* 只找到c - 把d并入集合ci */
                myset[ci].insert(d);
            } else {
                if (ci != di) {
                    /* 找到c和d - 并入元素多的结合 */
                    if (ci > di) {
                        myset[ci].insert(myset[di].begin(), myset[di].end());
                        myset.erase(myset.begin() + di);
                    } else {
                        myset[di].insert(myset[ci].begin(), myset[ci].end());
                        myset.erase(myset.begin() + ci);
                    }
                }
            }
        }
    }

    /* 处理不等式 - 检查可能性 */
    bool ispossible(char c, char d, vector<set<char>> &myset) {
        set<char> res;
        int len = myset.size();
        int ci = len, di = len;
        int i;

        /* 在集合中查找c,d的index */
        for (i = 0; i < len; i++) {
            if (myset[i].find(c) != myset[i].end()) {
                ci = i;
            }
            if (myset[i].find(d) != myset[i].end()) {
                di = i;
            }
        }

        /* 如果c和d属于不同的集合 - 不可能 */
        return !(ci != len && di != len && ci == di);
    }

    bool equationsPossible(vector<string>& equations) {
        vector<set<char>> myset;
        int len = equations.size();
        int i;

        /* 遍历所有等式，建立集合 */
        for (i = 0; i < len; i++) {
            if (equations[i][1] == '=') {
                createset(equations[i][0], equations[i][3], myset);
            }
        }

        /* 便利所有不等式，检查其可能性 */
        for (i = 0; i < len; i++) {
            if (equations[i][1] == '!') {
                if (equations[i][0] == equations[i][3])
                    return false;
                if (!ispossible(equations[i][0], equations[i][3], myset))
                    return false;
            }
        }
        
        return true;
    }
};


/* 36ms - 11.8M */
class Solution {
public:
/*
    bool helper(char c, char d, vector<set<char>> &myset, bool equal) {
        set<char> res;
        int len = myset.size();
        int ci = len, di = len;
        int i;

        for (i = 0; i < len; i++) {
            if (myset[i].find(c) != myset[i].end()) {
                ci = i;
            }
            if (myset[i].find(d) != myset[i].end()) {
                di = i;
            }
        }

        cout << "ci-" << c << " " << ci << " di-" << d << " " << di << endl;
        if (equal) {
            if (ci == len) {
                if (di == len) {
                    res.insert(c);
                    res.insert(d);
                    myset.push_back(res);
                } else {
                    myset[di].insert(c);
                }
            } else {
                if (di == len) {
                    myset[ci].insert(d);
                } else {
                    if (ci != di) {
                        cout << "ci-size" << myset[ci].size() << "     di-size" << myset[di].size() << endl;
                        myset[ci].insert(myset[di].begin(), myset[di].end());
                        cout << "ci-size" << myset[ci].size() << "     di-size" << myset[ci].size() << endl;
                        myset.erase(myset.begin() + di);
                    }
                }
            }
        } else {
            if (ci == len) {
                if (di == len) {
                    res.insert(c);
                    myset.push_back(res);
                    res.clear();
                    res.insert(d);
                    myset.push_back(res);
                } else {
                    res.insert(c);
                    myset.push_back(res);
                }
            } else {
                if (di == len) {
                    res.insert(d);
                    myset.push_back(res);
                } else {
                    if (ci == di)
                        return false;
                }
            }
        }

        cout << "size " << myset.size() << endl;
        for (i = 0; i < myset.size(); i++)
            cout << myset[i].size() << " ";
        cout << endl << endl << endl;

        return true;
    }
*/
    void createset(char c, char d, vector<set<char>> &myset) {
        set<char> res;
        int len = myset.size();
        int ci = len, di = len;
        int i;

        for (i = 0; i < len; i++) {
            if (myset[i].find(c) != myset[i].end()) {
                ci = i;
            }
            if (myset[i].find(d) != myset[i].end()) {
                di = i;
            }
        }

        cout << "ci-" << c << " " << ci << " di-" << d << " " << di << endl;

        if (ci == len) {
            if (di == len) {
                res.insert(c);
                res.insert(d);
                myset.push_back(res);
            } else {
                myset[di].insert(c);
            }
        } else {
            if (di == len) {
                myset[ci].insert(d);
            } else {
                if (ci != di) {
                    /**/
                    cout << "ci-size" << myset[ci].size() << "     di-size" << myset[di].size() << endl;
                    myset[ci].insert(myset[di].begin(), myset[di].end());
                    cout << "ci-size" << myset[ci].size() << "     di-size" << myset[ci].size() << endl;
                    myset.erase(myset.begin() + di);
                }
            }
        }

        cout << "size " << myset.size() << endl;
        for (i = 0; i < myset.size(); i++)
            cout << myset[i].size() << " ";
        cout << endl << endl << endl;
    }

    bool findset(char c, char d, vector<set<char>> &myset) {
        set<char> res;
        int len = myset.size();
        int ci = len, di = len;
        int i;

        for (i = 0; i < len; i++) {
            if (myset[i].find(c) != myset[i].end()) {
                ci = i;
            }
            if (myset[i].find(d) != myset[i].end()) {
                di = i;
            }
        }
        cout << "find " << myset.size() << " " << ci << " " << di << endl;
        return !(ci != len && di != len && ci == di);
    }

    bool equationsPossible(vector<string>& equations) {
        vector<set<char>> myset;
        int len = equations.size();
        int i;

        /**/
        for (i = 0; i < len; i++) {
            if (equations[i][1] == '=') {
                createset(equations[i][0], equations[i][3], myset);
            }
        }

        for (i = 0; i < len; i++) {
            if (equations[i][1] == '!') {
                if (equations[i][0] == equations[i][3])
                    return false;
                if (!findset(equations[i][0], equations[i][3], myset))
                    return false;
            }
        }
        
        return true;
    }
};
