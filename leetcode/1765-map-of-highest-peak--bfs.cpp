

class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        /*
         * BFS
         * 陆地的最大高度为陆地离最近水域的距离的最大值
         */
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>> res(m, vector<int>(n, -1));
        queue<pair<int, int>>qu;

        /* 寻找水域放入队列 */
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j] == 1) {
                    qu.push({i, j});
                    res[i][j] = 0;
                }
            }
        }

        int height = 0;
        while (!qu.empty()) {
            int size = qu.size();
            //cout << size << endl;
            height++;
            for (int i = 0; i < size; i++) {
                auto cur = qu.front();
                qu.pop();
                for (int j = 0; j < 4; j++) {
                    int nx = cur.first + dx[j];
                    int ny = cur.second + dy[j];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && res[nx][ny] == -1) {
                        qu.push({nx, ny});
                        res[nx][ny] = height;
                    }
                }
            }
        }

        return res;
    }
};
