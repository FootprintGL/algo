

struct Trie {
    /* 节点： 字母到节点的map */
    unordered_map<char, Trie *> child;
    /* 保存字典序最小的3个产品 */
    priority_queue<string> words;
};

class Solution {
public:
    void addword(Trie *root, string &word) {
        Trie *cur = root;
        for (auto &ch : word) {
            if (!cur->child.count(ch)) {
                /* 创建新节点 */
                cur->child[ch] = new Trie();
            }
            cur = cur->child[ch];
            /* 最多保持3个字典序最小的word */
            cur->words.push(word);
            if (cur->words.size() > 3)
                cur->words.pop();
        }
    }

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        /*
         * 字典树
         * 用字典树来存放products中的所有字符串
         * 依次输入searchword中的每个字母，从根节点向下查找，判断是否存在以当前输入为前缀的字符串
         * 并找出最小的3个字符串(如果存在的话)
         * 假设字典数中的某个节点node，从根节点到它对应的字符串为prefix
         * 字典树的节点可以保持字典树最小的3个以prefix为前缀的字符串，从而加速查找
         */
        Trie *root = new Trie();
        vector<vector<string>> res;

        for (auto &word : products)
            addword(root, word);

        Trie *cur = root;
        bool flag = false;

        for (auto &ch : searchWord) {
            if (flag || !cur->child.count(ch)) {
                /* 没有匹配的word */
                res.emplace_back();
                flag = true;
            } else {
                cur = cur->child[ch];
                vector<string> selects;
                while (!cur->words.empty()) {
                    /* 提取前缀为prefix的word */
                    selects.push_back(cur->words.top());
                    cur->words.pop();
                }
                reverse(selects.begin(), selects.end());
                res.emplace_back(selects);
            }
        }

        return res;
    }
};



class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        /*
         * 先对products进行排序
         * 对于前缀prefix, 在products中找到第一个大于等于prefix的元素
         * 依次判断products[i], products[i + 1], products[i + 2]是否办汗prefix前缀即可
         * prefix依次递增，直接从i往后搜索即可
         */
        vector<vector<string> > res;
        string prefix;

        /* 先排序 */
        sort(products.begin(), products.end());

        auto iter_last = products.begin();
        for (auto &ch : searchWord) {
            prefix += ch;
            /* 搜索第一个大于等于prefix的位置 */
            auto iter_find = lower_bound(iter_last, products.end(), prefix);
            vector<string> selects;

            /* 检查iter_find后面3个元素是否以prefix为前缀 */
            for (int i = 0; i < 3; i++) {
                if (iter_find + i < products.end() && (*(iter_find + i)).find(prefix) == 0) {
                    selects.push_back(*(iter_find+i));
                } else {
                    break;
                }
            }

            res.push_back(selects);
            iter_last = iter_find;
        }

        return res;
    }
};
