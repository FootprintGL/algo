

class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    /* DFS */
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] == newColor)
            return image;

        int m = image.size();
        int n = image[0].size();
        int orgcolor = image[sr][sc];

        image[sr][sc] = newColor;
        for (int i = 0; i < 4; i++) {
            int nx = sr + dx[i];
            int ny = sc + dy[i];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && image[nx][ny] == orgcolor) {
                floodFill(image, nx, ny, newColor);
            }
        }

        return image;
    }
};
