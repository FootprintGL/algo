class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        vector<int> C(m, 0);
        int i, j, k;
        for (i = 0; i < m; i++)
            C[i] = A[i];
        i = j = k = 0;
        while (k < m + n) {
            if (i == m)
                /* C处理完毕,把B依次放入 */
                A[k++] = B[j++];
            else if (j == n)
                /* B处理完毕 把C依次放入 */
                A[k++] = C[i++];
            else if (C[i] <= B[j])
                A[k++] = C[i++];
            else
                A[k++] = B[j++];
        }
    } 
};
