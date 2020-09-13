

/* 可以用数组 */
class Solution {
public:
    //unordered_map<char, int> dic;
    int dic[26];

    /* 比较2个字符串大小 - w1大于等于w2返回trye，w1小于w2返回false */
    bool compare(string w1, string w2) {
        int n1 = w1.length();
        int n2 = w2.length();
        int n = min(n1, n2);

        //cout << w1 << " " << w2 << endl;
        for (int i = 0; i < n; i++) {
            if (w1[i] == w2[i])
                continue;

            //cout << i << " " << w1[i] << " " << w2[i] << endl;
            if (dic[w1[i] - 'a'] < dic[w2[i] - 'a'])
                return false;
            else
                return true;
        }

        return n1 >= n2 ? true : false;
    }

    bool isAlienSorted(vector<string>& words, string order) {
        int i;

        /* 哈希表存放字母和位置的映射 */
        for (i = 0; i < 26; i++) {
            dic[order[i] - 'a'] = i;
        }

        /* 相邻单词比较，如果出现逆序则返回false */
        for (i = 1; i < words.size(); i++) {
            if (compare(words[i - 1], words[i]))
                return false;
        }

        return true;
    }
};

class Solution {
public:
    unordered_map<char, int> dic;

    /* 比较2个字符串大小 - w1大于等于w2返回trye，w1小于w2返回false */
    bool compare(string w1, string w2) {
        int n1 = w1.length();
        int n2 = w2.length();
        int n = min(n1, n2);

        //cout << w1 << " " << w2 << endl;
        for (int i = 0; i < n; i++) {
            if (w1[i] == w2[i])
                continue;

            //cout << i << " " << w1[i] << " " << w2[i] << endl;
            if (dic[w1[i]] < dic[w2[i]])
                return false;
            else
                return true;
        }

        return n1 >= n2 ? true : false;
    }

    bool isAlienSorted(vector<string>& words, string order) {
        int i;

        /* 哈希表存放字母和位置的映射 */
        for (i = 0; i < 26; i++) {
            dic[order[i]] = i;
        }

        /* 相邻单词比较，如果出现逆序则返回false */
        for (i = 1; i < words.size(); i++) {
            if (compare(words[i - 1], words[i]))
                return false;
        }

        return true;
    }
};
