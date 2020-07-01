class Solution {
public:
    /* 判断两个单词是否只差一个字母 */
    bool oneCharDiff(string w1, string w2, int len) {
        int diff = 0;
        int i;
        for (i = 0; i < len; i++) {
            if (w1[i] != w2[i]) {
                diff++;
            }
            if (diff == 2)
                break;
        }
        return (diff == 1);
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> map;
        int len = wordList.size();
        int wordLen = beginWord.size();
        queue<string> qu;
        vector<bool> visited (len + 1, false);
        int depth = 1, size;
        bool found = false;
        string letter = "abcdefghijklmnopqrstuvwxyz";
        string str, str1;
        int i, j, k;

        /* 建立map，加速查找 */
        for (i = 0; i < len; i++) {
            map.emplace(wordList[i], i);
        }
        map.emplace(beginWord, len);

        /* 如果endWord不再wordList中，直接返回0 */
        for (i = 0; i < len; i++) {
            if (!endWord.compare(wordList[i])){
                found = true;
            }
        }
        if (!found)
            return 0;

        /* 
         * 单向BFS
         * 每次替换一个字母到map中查找，找到则放入队列，visited标记访问过的元素
         * 每次只处理未被访问的元素,逐层处理，每处理完一层depth++
         * 直到找到最后的endWord，返回depth + 1，如果找不到，则返回0
         * 如果用oneCharDiff判断两个单词是否之差一个字母，在字典单词多时会超时
         * 改为每次替换一个字符到字典map中去查找可以通过测试
         * 执行结果：通过
         * 显示详情
         * 执行用时：288 ms, 在所有 C++ 提交中击败了46.40% 的用户
         * 内存消耗：11.9 MB, 在所有 C++ 提交中击败了100.00% 的用户
         */
        qu.push(beginWord);
        while (!qu.empty()) {
            size = qu.size();
            for (i = 0; i < size; i++) {
                str = qu.front();
                for (j = 0; j < wordLen; j++) {
                    str1 = str;
                    for (k = 0; k < 26; k++) {
                        if (str1[j] != letter[k]) {
                            str1[j] = letter[k];
                            if (map.find(str1) != map.end()) {
                                if (!visited[map[str1]]) {
                                    if (!endWord.compare(str1))
                                        return (depth + 1);
                                    qu.push(str1);
                                    visited[map[str1]] = true;
                                }
                            }
                        }
                    }
                }
                qu.pop();
            }
            depth++;
        }

       return 0;
    }
};



//超出时间限制
class Solution {
public:
    /* 判断两个单词是否只差一个字母 */
    bool oneCharDiff(string w1, string w2, int len) {
        int diff = 0;
        int i;
        
        for (i = 0; i < len; i++) {
            if (w1[i] != w2[i]) {
                diff++;
            }
            
            if (diff == 2)
                break;
        }

        return (diff == 1);
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> map;
        int len = wordList.size();
        int wordLen = beginWord.size();
        queue<string> qu;
        vector<bool> visited (len + 1, false);
        int depth = 1, size;
        bool found = false;
        string str;
        int i, j;
        int k;

        /**/
        for (i = 0; i < len; i++) {
            map.emplace(wordList[i], i);
        }
        map.emplace(beginWord, len);

        /* 如果endWord不再wordList中，直接返回0 */
        for (i = 0; i < len; i++) {
            if (!endWord.compare(wordList[i])){
                found = true;
            }
        }
        if (!found)
            return 0;

        /* BFS */
        qu.push(beginWord);
        while (!qu.empty()) {
            size = qu.size();
            for (i = 0; i < size; i++) {
                str = qu.front();
                for (j = 0; j < len; j++) {
                    if (!visited[j]) {
                        if (oneCharDiff(str, wordList[j], wordLen)) {
                            if (!endWord.compare(wordList[j])) {
                                /*cout << endl << endl << "visited-1:" << endl;
                                for (k = 0; k <= len; k++)
                                    cout << visited[k] << " ";
                                cout << endl;*/
                                return (depth + 1);
                            }
                            //cout << "push: " << wordList[j] << endl;
                            qu.push(wordList[j]);
                            visited[map[wordList[j]]] = true;
                        }
                    }
                }
                //cout << "pop: " << str << endl;
                qu.pop();
                //visited[map[str]] = true;
                /*
                cout << "visited:" << endl;
                for (k = 0; k <= len; k++)
                    cout << visited[k] << " ";
                cout << endl;
                cout << "qu size: " << qu.size() << "   front:" << qu.front() << "   back:" << qu.back() << endl;
                */
            }

            depth++;
            //cout << "depth:" << depth << endl;
        }

        return 0;
    }
};
