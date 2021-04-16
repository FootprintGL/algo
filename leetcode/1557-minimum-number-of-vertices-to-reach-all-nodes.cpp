

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        /*
         * 入度为0的点只能从自己进入，入度不为0的点可以从其他点进入
         * 实际是统计入度为0的节点个数
         */
        vector<int> din(n, 0);
        for (auto &edge : edges)
            din[edge[1]]++;

        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (din[i] == 0)
                res.push_back(i);
        }

        return res;
    }
};
