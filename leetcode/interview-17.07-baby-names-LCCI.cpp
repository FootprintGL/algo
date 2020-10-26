


class Solution {
public:
    /* 父节点集合 */
    unordered_map<string, string> parent;
    /* 存放根节点出现频率 */
    unordered_map<string, int> freqs;
    /* 保存结果 */
    vector<string> res;

    /* 寻找word的父节点 */
    string findroot(string &word) {
        while (parent[word] != word)
            word = parent[word];
        return word;
    }

    /* 合并2个节点word1和word2 */
    void unionroot(string &word1, string &word2) {
        string r1 = findroot(word1);
        string r2 = findroot(word2);

        if (r1 != r2) {
            /* 根节点不同则合并，小的根节点作为根节点 */
            if (r1 < r2) {
                /* 合并并累加频率 */
                parent[r2] = r1;
                freqs[r1] += freqs[r2];
                /* 删除被合并的集合 */
                freqs.erase(r2);
            } else {
                /* 合并并累加频率 */
                parent[r1] = r2;
                freqs[r2] += freqs[r1];
                /* 删除被合并的集合 */
                freqs.erase(r1);
            }
        }
    }

    /* 分离名字和出现频率并初始化每个名字出现频率和并查集合 */
    void splitname1(vector<string> &names) {
        int index, len;
        for (auto &name : names) {
            len = name.length();
            index = len - 2;
            while (index >= 0 && name[index] >= '0' && name[index] <= '9') {
                index--;
            }
            string name1 = name.substr(0, index);
            string freq = name.substr(index + 1, len - 1 - index - 1);
            /* 初始化单个名字出现频率 */
            freqs[name1] = stoi(freq);
            /* 初始化父节点为自己 */
            parent[name1] = name1;
        }
    }

    /* 根据synonyms分离名字并构建并查集 */
    void splitname2(vector<string> &synonyms) {
        for (auto &syn : synonyms) {
            int i = 1;
            int len = syn.length();
            while (i < len && syn[i] != ',')
                i++;
            string name1 = syn.substr(1, i - 1);
            string name2 = syn.substr(i + 1, len - 1 - i - 1);
            if (parent.count(name1) && parent.count(name2))
            /* 两个都出现过时才需要合并 */
                unionroot(name1, name2);
        }
    }

    /* 并查集 */
    vector<string> trulyMostPopular(vector<string>& names, vector<string>& synonyms) {
        splitname1(names);
        splitname2(synonyms);

        /* 构建结果并返回 */
        for (auto &[name, freq] : freqs) {
            string s = name;
            s += '(';
            s += to_string(freq);
            s += ')';
            res.push_back(s);
        }

        return res;
    }
};
