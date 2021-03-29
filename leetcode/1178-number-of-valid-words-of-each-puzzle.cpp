

/*
 * 第二种：我们也可以使用通用的「枚举二进制子集」的方法，下面给出伪代码：

function get_subset(bitmask)
    subset = bitmask
    answer = [bitmask]
    while subset != 0
        subset = (subset - 1) & bitmask
        put subset into the answer list
    end while
    return answer
end function

其中 bitmask\texttt{bitmask}bitmask 表示一个二进制数，subset\texttt{subset}subset 会遍历所有 bitmask\texttt{bitmask}bitmask 的子集，并将所有的子集放入 answer\texttt{answer}answer 中。需要注意的是，bitmask\texttt{bitmask}bitmask 本身也是 bitmask\texttt{bitmask}bitmask 的一个子集，因此 answer\texttt{answer}answer 在初始时就包含 bitmask\texttt{bitmask}bitmask 本身。
 *
 * */



class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        /*
         * 状态压缩 + 位运算
         * 用32位整型表示puzzle和word
         * abb和aabbb的mask相同，用一个哈希表保存每个mask出现的次数
         * 枚举puzzle的每个子集，在哈希表中搜索并累加数量
         */
        int wn = words.size();
        int pn = puzzles.size();
        unordered_map<int, int> cnt;
        vector<int> res(pn, 0);

        /* 计算每个word的对应的mask, 并放入哈希表 */
        for (int i = 0; i < wn; i++) {
            int wmask = 0;
            for (auto &c : words[i])
                wmask |= 1 << (c - 'a');
            cnt[wmask]++;
        }

        for (int i = 0; i < pn; i++) {
            /* 计算puzzles[i]的mask */
            int pmask = 0;
            for (auto &c : puzzles[i])
                pmask |= 1 << (c - 'a');

            /* 枚举二进制状态数字pmask的子集 */
            int n = pmask;
            do {
                n = (n - 1) & pmask;
                if ((1 << (puzzles[i][0] - 'a') & n))
                    res[i] += cnt[n];
            } while (n != pmask);
        }

        return res;
    }
};


/* 超时 */
class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        /*
         * 状态压缩 + 位运算
         * 用32位整型表示puzzle和word
         * 对每个puzzle，统计有多少个word的mask是puzzle的submask
         */
        int wn = words.size();
        int pn = puzzles.size();
        vector<int> res(pn, 0);
        vector<int> wmask(wn, 0);

        /* 计算每个word的对应的mask */
        for (int i = 0; i < wn; i++) {
            for (auto &c : words[i])
                wmask[i] |= 1 << (c - 'a');
        }

        for (int i = 0; i < pn; i++) {
            /* 计算puzzles[i]的mask */
            int pmask = 0;
            for (auto &c : puzzles[i])
                pmask |= 1 << (c - 'a');

            for (int j = 0; j < wn; j++)
                if ((wmask[j] & pmask) == wmask[j] && (wmask[j] & (1 << (puzzles[i][0] - 'a'))))
                /* word所有字符都在puzzle中，并且puzzle的第一个字符在word中 */
                    res[i]++;
        }

        return res;
    }
};
