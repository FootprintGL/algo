

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int n = A.size();
        if (n == 0)
            return 0;

        /* 哈希表保持两数之和加速查询 */
        unordered_map<int, int> tbl;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int sum = A[i] + B[j];
                tbl[sum]++;
            }
        }

        for (int k = 0; k < n; k++) {
            for (int l = 0; l < n; l++) {
                int sum = C[k] + D[l];
                if (tbl[0 - sum])
                    ans += tbl[0 - sum];
            }
        }

        return ans;
    }
};


/* 暴力超时 O(n^3) */
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int n = A.size();
        if (n == 0)
            return 0;

        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        sort(C.begin(), C.end());
        sort(D.begin(), D.end());
        unordered_map<int, int> tbl;

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int sum = A[i];
            for (int j = 0; j < n; j++) {
                sum += B[j];
                for (int k = 0; k < n; k++) {
                    sum += C[k];
                    tbl[sum]++;
                    //cout << i << "-" << j << "-" << k << ": " << sum << " " << tbl[sum] << endl;
                    /*
                    for (int l = 0; l < n; l++) {
                        if (tbl[0 - D[l]])
                            ans += tbl[0 - D[l]];
                    }
                    */
                    sum -= C[k];
                }
                sum -= B[j];
            }
        }

        for (int l = 0; l < n; l++) {
            if (tbl[0 - D[l]])
                ans += tbl[0 - D[l]];
        }

        return ans;
    }
};
