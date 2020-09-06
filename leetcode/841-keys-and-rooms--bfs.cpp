class Solution {
public:
    int cnt;

    void dfs(vector<vector<int>> &rooms, int i, vector<bool> &visited) {
        visited[i] = true;
        cnt++;
        for (int j = 0; j < rooms[i].size(); j++) {
            if (rooms[i][j] != i && visited[rooms[i][j]] == false) {
                dfs(rooms, rooms[i][j], visited);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> qu;
        int n = rooms.size();
        vector<bool> visited(n, false);
        
        cnt = 0;
        dfs(rooms, 0, visited);

        return cnt == n;
    }
};

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> qu;

        int n = rooms.size();
        vector<bool> visited(n, false);
        int i, j, cnt = 0;

        /* BFS */
        qu.push(0);
        visited[0] = true;
        cnt++;
        while (!qu.empty()) {
            i = qu.front();
            qu.pop();
            for (j = 0; j < rooms[i].size(); j++) {
                if (rooms[i][j] != i && visited[rooms[i][j]] == false) {
                    visited[rooms[i][j]] = true;
                    qu.push(rooms[i][j]);
                    cnt++;
                }
            }
        }

        //cout << cnt << " " << n << endl;

        return cnt == n;
    }
};
