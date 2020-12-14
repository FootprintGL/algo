

class Solution {
public:
    int n;

    /* 一维坐标转换成二维坐标 */
    void get(int mov, int &r, int &c) {
        r = n - 1 - (mov - 1) / n;
        if (r % 2 == (n - 1) % 2) {
            /* 从左到右 */
            c = (mov - 1) % n;
        } else {
            /* 从右到左 */
            c = n - 1 - (mov - 1) % n;
        }
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        /* BFS */
        queue<int> qu;
        n = board.size();
        int step = 0;
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        qu.push(1);
        visited[n - 1][0] = true;
        while (!qu.empty()) {
            int size = qu.size();
            for (int i = 0; i < size; i++) {
                int cur = qu.front();
                if (cur == n * n)
                    return step;
                qu.pop();
                for (int mov = cur + 1; mov <= min(cur + 6, n * n); mov++) {
                    int r, c;
                    get(mov, r, c);
                    /* 蛇梯跳跃 */
                    int finalmov = board[r][c] == -1 ? mov : board[r][c];
                    get(finalmov, r, c);
                    if (visited[r][c])
                    /* 跳过已经访问过的位置 */
                        continue;
                    visited[r][c] = true;
                    //cout << mov << " - " << r << " " << c << " " << board[r][c] << " " << size << endl;
                    qu.push(finalmov);
                }
            }
            cout << endl;
            step++;
        }

        return -1;
    }
};
