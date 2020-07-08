
class Solution {
public:
    /* 判断数字 */
    bool isdigitial(char c) {
        return (c >= '0' && c <= '9');
    }

    /* 判断大写字母 */
    bool isupper(char c) {
        return (c >= 'A' && c <= 'Z');
    }
    /* 大写转小写 */
    char tolower(char c) {
        return ('a' + c - 'A');
    }

    /*
     * 大小写互转
     * 大小写字母刚好相差32(1 << 5)，异或刚好可以实现转换
     * 具体可参考ASCII码表值
     */
    char upperlower(char c) {
        return c ^ (1 << 5);
    }

    void dfs(string& S, int len, int dep, string path, vector<string>& res) {
        if (path.size() == len) {
            /* path等于字符串长度，处理结束，保存结果 */
            res.push_back(path);
            return;
        }
        if (dep < len) {
            if (isdigitial(S[dep])) {
                path += S[dep];
                dfs(S, len, dep + 1, path, res);
            } else {
                /* 添加当前字母更新路径 */
                path += S[dep];
                /* dfs处理下一个元素 */
                dfs(S, len, dep + 1, path, res);
                /* 移除当前字母，添加它对应的大/小写字母 */
                path.erase(path.size() - 1, 1);
                path += S[dep] ^ (1 << 5);
                /* dfs处理下一个元素 */
                dfs(S, len, dep + 1, path, res);
            }
        }
    }

    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        int len = S.size();
        string path;

        /* 空串 - 返回空 */
        if (len == 0)
            return res;
        /*
         * 回溯算法 - 三要素：路径，选择列表，结束条件
         * 基本框架：
         *     1. 从选择列表中一个元素加入到路径中，并从选择列表中移除该元素
         *     2. dfs递归处理下一个元素
         *     3. 从路径中移除这个元素并放回选择列表
         *     4. 循环1-3处理过程
         */
        dfs(S, len, 0, path, res);

        return res;
    }
};

