class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> out(N + 1, 0);
        vector<int> inn(N + 1, 0);
        int size = trust.size(), res = -1;
        int i;

        /* 入度为N - 1，出度为0的节点 */
        for (i = 0; i < size; i++) {
            out[trust[i][0]]++;
            inn[trust[i][1]]++;
        }

        for (i = 1; i <= N; i++) {
            if (out[i] == 0 && inn[i] == N - 1)
                res = i;
        }

        return res;
    }
};
