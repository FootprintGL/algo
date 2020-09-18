

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        int m = A.size();
        int n = queries.size();
        vector<int> answer(n, 0);
        int esum = 0, i;

        /* 计算原始数组偶数的和 */
        for (auto &a : A)
            if (a % 2 == 0)
                esum += a;

        for (i = 0; i < n; i++) {
            A[queries[i][1]] += queries[i][0];

            if (A[queries[i][1]] % 2 == 0 && queries[i][0] % 2) {
                /* 同为奇数，相加后变偶数，两个都要加 */
                esum += A[queries[i][1]];
            } else if (A[queries[i][1]] % 2 == 0 && queries[i][0] % 2 == 0) {
                /* 同为偶数，加上新的queries[i][0] */
                esum += queries[i][0];
            } else if (A[queries[i][1]] % 2 && queries[i][0] % 2) {
                /* A为偶数，Q为奇数 */
                esum -= A[queries[i][1]] - queries[i][0];
            }

            answer[i] = esum;
        }

        return answer;
    }
};
