




class Solution {
public:
    string simplifyPath(string path) {
        vector<string> v;
        istringstream iss(path);
        string buf;

        /* 利用istringstream以/为分隔符切割字符串 */
        while (getline(iss, buf, '/')) {
            //cout << buf << endl;
            if (!buf.empty() && buf != "." && buf != "..")
                v.push_back(buf);
            else if (!v.empty() && buf == "..")
                v.pop_back();
        }

        if (v.empty())
            return "/";
        
        /* 构建结果 */
        string res;
        for (auto &s : v) {
            res += "/";
            res += s;
        }

        return res;
    }
};

/* 错误 - 无法解析含有"..."文件名的路径, 比如"/..." */
class Solution {
public:
    string simplifyPath(string path) {
        /*
         * 堆栈
         * '.'当前目录 - 抵消一个/
         * ‘..‘父目录 - 抵消两个’/’和之间的内容  -   /../
         * 连续多个'/',只需要保留一个
         * 最后多余的'/',需去掉
         */
        
        /* 放入'/'表示绝对路径 */
        string res = "/";

        for (auto &c : path) {
            if (c == '/') {
                if (res.back() == '.') {
                    /* '.'当前目录 - 消除一个’/’ */
                    res.pop_back();
                } else if (res.back() != '/') {
                    res.push_back(c);
                }
            } else if (c == '.') {
                if (!res.empty() && res.back() == '.') {
                    /* '..'父目录 - 记录删除了几个‘/‘ */
                    int cnt = 0;
                    /* 回退直到删除两个'/'或栈为空 */
                    while (!res.empty()) {
                        char t = res.back();
                        res.pop_back();
                        if (res.back() == '/') {
                            cnt++;
                            if (cnt == 2)
                            /* 以删除了两个'/' */
                                break;
                        }
                    }
                    if (res.empty())
                    /* 堆栈为空，需放入'/'表示绝对路径 */
                        res.push_back('/');
                } else {
                    /* 不构成父目录 - 直接入栈 */
                    res.push_back(c);
                }
            } else {
                /* 除‘.‘和'/'以外的其他字符 - 直接入栈 */
                res.push_back(c);
            }
        }

        /* 去掉末尾多余的‘/‘, 注意根目录只有一个单独的’/’ */
        if (res.size() > 1 && res.back() == '/')
            res.pop_back();

        if (res.back() == '.')
        /* 如果path以'.'结尾需要删除 */
            res.pop_back();

        return res;
    }
};
