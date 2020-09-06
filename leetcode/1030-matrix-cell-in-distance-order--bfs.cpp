
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        /* BFS */
        int move[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        vector<vector<int>> ans;
        vector<int> tmp(2, 0);
        vector<vector<bool>> visited(R, vector<bool> (C, false));
        queue<pair<int, int>> qu;
        pair<int, int> pos;
        int r1, c1, r2, c2;
        int i;

        qu.push({r0, c0});
        visited[r0][c0] = true;
        while (!qu.empty()) {
            pos = qu.front();
            qu.pop();
            tmp[0] = r1 = pos.first;
            tmp[1] = c1 = pos.second;
            ans.push_back(tmp);

            for (i = 0; i < 4; i++) {
                r2 = r1 + move[i][0];
                c2 = c1 + move[i][1];
                if (r2 >= 0 && r2 < R && c2 >= 0 && c2 < C && visited[r2][c2] == false) {
                    qu.push({r2, c2});
                    visited[r2][c2] = true;
                }
            }
        }

        return ans;
    }
};
