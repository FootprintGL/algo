

class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        /*
         * 用一个二维prefix存储左上子矩阵的异或结果
         */
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> prefix(m, vector<int> (n, 0));
        priority_queue<int, vector<int>, std::greater<int>> pq;

        for (int i = 0; i < m; i++) {
            int tmp = 0;
            for (int j = 0; j < n; j++) {
                if (i == 0) {
                    if (j > 0)
                        prefix[i][j] = prefix[i][j - 1] ^ matrix[i][j];
                    else
                        prefix[i][j] = matrix[i][j];
                } else {
                    if (j > 0)
                        prefix[i][j] = prefix[i - 1][j] ^ prefix[i][j - 1] ^ prefix[i - 1][j - 1] ^ matrix[i][j];
                    else
                        prefix[i][j] = prefix[i - 1][j] ^ matrix[i][j];
                }
                pq.push(prefix[i][j]);
                if (pq.size() > k)
                    pq.pop();
            }
        }
/*
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << prefix[i][j] << " ";
            }
            cout << endl;
        }
*/
        return pq.top();
    }
};
