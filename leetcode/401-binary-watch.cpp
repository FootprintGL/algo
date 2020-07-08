class Solution {
public:
    /* 整型转字符串 */
    string itoa(int num) {
        string str;
        char dig;
        int div = 1;

        if (num < 0) {
            str += "-";
            num = num * (-1);
        }
        while (num / div >= 10) {
            div *= 10;
        }
        while (div) {
            dig = (num / div + '0');
            str += dig;
            num %= div;
            div /= 10;
        }

        return str;
    }

    /* 计算时间并判断时间是否有效 */
    bool isvalid(int num, vector<int> &path, int &hour, int &min) {
        int h = 0, m = 0;
        bool ret = true;

        for (int i = 0; i < num; i++) {
            if (path[i] >= 6) {
                /* 小时 */
                h += 1 << (path[i] - 6);
                if (h > 11) {
                    ret = false;
                    break;
                }
            } else {
                /* 分钟 */
                m += 1 << path[i];
                if (m > 59) {
                    ret = false;
                    break;
                }
            }
        }
        hour = h;
        min = m;
        return ret;
    }

    void appendresult(int num, vector<int> &path, vector<string> &res) {
        string time;
        int h, m;

        if (isvalid(num, path, h, m)) {
            /* 保存格式化结果 */
            time += itoa(h);
            time += ":";
            if (m < 10)
                time += "0";
            time += itoa(m);
            res.push_back(time);
        }
    }

    /* 回溯算法 */
    void dfs(int num, int start, vector<int> &path, vector<string> &res) {
        if (num == path.size()) {
            appendresult(num, path, res);
            return;
        }
        for (int i = start; i < 10; i++) {
            /* 选择新元素，更新路径 */
            path.push_back(i);
            /* 递归处理下一层 */
            dfs(num, i + 1, path, res);
            /* 撤销选择，选择下一个元素 */
            path.pop_back();
        }
    }

    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        vector<int> path;

        /* num必为0到10之间的数[0,10] */
        if (num < 0 || num > 10) {
            return res;
        }
        dfs(num, 0, path, res);

        return res;
    }
};
