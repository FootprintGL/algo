
class Solution {
public:
    const int mx[4] = {-1, 0, 1, 0};
    const int my[4] = {0, 1, 0, -1};

    void helper(vector<vector<int>> &image, int x, int y, int color, int newColor) {
        int pr, pc;

        if (image[x][y] == color) {
            image[x][y] = newColor;
            for (int i = 0; i < 4; i++) {
                pr = x + mx[i];
                pc = y + my[i]; 
                if ((pr >= 0 && pr < image.size()) &&
                    (pc >= 0 && pc < image[0].size()) &&
                    image[pr][pc] == color){
                    helper(image, pr, pc, color, newColor);
                }
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] == newColor)
            return image;

        /* DFS */
        helper(image, sr, sc, image[sr][sc], newColor);
        
        return image;
    }
};


class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] == newColor)
            return image;

        queue<pair<int, int>> qu;
        pair<int, int> pos;
        const int mx[] = {-1, 0, 1, 0};
        const int my[] = {0, 1, 0, -1};
        int m = image.size(), n = image[0].size();
        int pr, pc, color;

        /* BFS */
        qu.push({sr, sc});
        color = image[sr][sc];
        image[sr][sc] = newColor;
        while (!qu.empty()) {
            pos = qu.front();
            qu.pop();
            for (int i = 0; i < 4; i++) {
                pr = pos.first + mx[i];
                pc = pos.second + my[i];
                if ((pr >= 0 && pr < m) &&
                    (pc >= 0 && pc < n) &&
                    image[pr][pc] == color){
                    //cout << pr << " " << pc << " " << image[pr][pc] << endl;
                    image[pr][pc] = newColor;
                    //cout << pr << " " << pc << " " << image[pr][pc] << endl << endl;
                    qu.push({pr, pc});
                }
            }
        }

        return image;
    }
};
