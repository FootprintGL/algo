
class Solution {
public:
    vector<string> ans;
    /* 用map使目的地排序 */
    unordered_map<string, map<string, int>> adj;

    bool dfs(string city) {
        for (auto &[next, number] : adj[city]) {
            if (number <= 0)
                continue;
            number--;
            dfs(next);
        }

        /* 
         * 终点是没有相邻边的顶点
         * 当终点删除后，终点前的顶点也没有相邻边了
         * 运行到这里，当前airport一定是没有可遍历的相邻边了
         * 则它是此时的终点, 倒着插入ans
         */
        ans.insert(ans.begin(), city);
        return false;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        /*
         * Hierholzer算法
         * 欧拉路径 - 从一个顶点开始每个边遍历一次，可以遍历每个顶点 - 一笔画
         * 欧拉回路 - 存在一条欧拉路径可以回到起点
         * 欧拉图 - 存在欧拉回路的图
         * 半欧拉图 - 存在欧拉路径的图
         * 欧拉图也是半欧拉图
         * 如何判断一个图是否是欧拉图或半欧拉图
         * 无向欧拉图 - 图连通且没有奇数度的顶点
         * 无向半欧拉图 - 图连通，有且只有2个奇数度的定点
         * 有向欧拉图 - 强联通，每个顶点出度和入度相同
         * 有向半欧拉图 - 强联通
         *      a. 恰有一个顶点入度和出度差1
         *      b. 恰有一个顶点出读和入度差1
         *      c. 其他顶点入度出度相同
         * Hierholzer算法
         * 1. 从起点出发，深度有限遍历
         * 2. 每次从一个顶点移动到另一个顶点时，删除这条边
         * 3. 如果没有可移动的路径，则该顶点为终点，入栈
         * 4. 继续搜索没有可移动的路径，分别为倒数第2，3,...,结果依次弹栈即可
         * 5. 欧拉图从任意顶点都可找到欧拉回路，半欧拉图必须从奇数度的两个顶点开始才能找到欧拉路径
         */
        if (tickets.size() == 1)
            return tickets[0];

        /* 建立临界表 */
        for (auto &tic : tickets) {
            adj[tic[0]][tic[1]]++;
        }

        dfs("JFK");
        return ans;
    }
};



class Solution {
public:
    vector<string> ans;
    unordered_map<string, map<string, int>> adj;
    int maxcount;

    bool dfs(string city, int count) {
        //cout << city << " " << count << " " << maxcount << endl;
        if (count == maxcount)
            return true;

        for (auto &c : adj[city]) {
            //cout << c.first << "-" << c.second << endl;
            if (c.second <= 0)
                continue;
            c.second--;
            ans.push_back(c.first);
            if (dfs(c.first, count + 1))
                return true;
            c.second++;
        }

        ans.pop_back();
        return false;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        /*
         * 回溯算法
         * 多种解法要求输出自然排序小的行程，邻接表用map对目的地进行排序
         * 存在相同机票，需要每个机票数量
         * 当所有机票用完时结束，当走不通时进行回溯
         */
        if (tickets.size() == 1)
            return tickets[0];

        /* 建立临界表 */
        for (auto &tic : tickets) {
            adj[tic[0]][tic[1]]++;
        }
        maxcount = tickets.size();
        /* 城市个数是机票数+1 */
        ans.push_back("JFK");
        dfs("JFK", 0);
        return ans;
    }
};
