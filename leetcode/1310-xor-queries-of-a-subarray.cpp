

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        /*
         * 异或前缀和
         * presum[i]表示前i个元素的异或前缀和
         * presum[0] = 0
         * presum[i] = arr[0] ^ arr[1] ^ ... ^ arr[i - 1]
         * presum[Li] ^ presum[Ri + 1] = (arr[0] ^ arr[1] ^ ... ^ arr[Li - 1]) ^ (arr[0] ^ arr[1] ^ ... ^ arr[Ri])
         * = arr[Li] ^ arr[Li + 1] ^ ... ^ arr[Ri]
         */
        int n = arr.size();
        vector<int> res;
        vector<int> presum(n + 1, 0);

        /* 计算异或前缀和 */
        for (int i = 1; i <= n; i++)
            presum[i] = presum[i - 1] ^ arr[i - 1];

        /* 计算结果 */
        for (int i = 0; i < queries.size(); i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            res.push_back(presum[l] ^ presum[r + 1]);
        }

        return res;
    }
};
