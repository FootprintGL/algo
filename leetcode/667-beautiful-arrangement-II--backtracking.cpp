

class Solution {
public:
    /* 翻转数组[i,j]之间元素 */
    void reverse(vector<int> &arr, int i, int j) {
        while (i < j) {
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
            i++;
            j--;
        }
    }

    vector<int> constructArray(int n, int k) {
        /*
         * 脑筋急转弯 - 找规律
         * n = 8, 初始状态1，2，3，4，5，6，7，8
         * k == | 1,2,3,4,5,6,7,8
         * k == 1,|8,7,6,5,4,3,2
         * k == 1,8,|2,3,4,5,6,7
         * k == 1,8,2,|7,6,5,4,3
         * k > 1时需要翻转k - 1次，每次反转保持前m(m = 1,2,3,...,k-1)个数
         * 每次翻转都在原数组上进行
         */
        vector<int> res;
        
        for (int i = 0; i < n; i++)
            res.push_back(i + 1);
        
        if (k == 1)
        /* k == 1，直接返回 */
            return res;
        
        /* k > 1, 反转k - 1次，每次反转保留前i个数 */
        for (int i = 1; i < k; i++) {
            reverse(res, i, n - 1);
        }

        return res;
    }
};


/* 回溯 -- 超时 */
class Solution {
public:
    unordered_map<int, int> tbl;
    vector<int> res;

    void dump(vector<int> &vec) {
        for (int i = 0; i < vec.size(); i++)
            cout << vec[i] << " ";
        cout << endl;
    }

    /* 回溯算法 */
    bool dfs(int start, int n, int k, vector<int> &vis) {
        if (start > n) {
            //cout << "find: " << tbl.size() << endl;
            //dump(res);
            /* 完成一个满足条件的结果 */
            return tbl.size() == k;
        }

        //cout << tbl.size() << endl;
        //dump(res);
        //cout << endl;

        if (tbl.size() > k)
        /* 相邻元素的差的个数大于k，不满足条件 */
            return false;

        int delta;
        bool flag = false;
        for (int i = 1; i <= n; i++) {
            if (vis[i])
                continue;

            if (!res.empty()) {
                delta = abs(res.back() - i);
                tbl[delta]++;
                flag = true;
            } else {
                flag = false;
            }

            vis[i] = true;
            res.push_back(i);
            if (dfs(start + 1, n, k, vis))
                return true;
            /* 回溯 */
            res.pop_back();
            vis[i] = false;

            if (flag) {
                tbl[delta]--;
                if (tbl[delta] == 0)
                    tbl.erase(delta);
            }
        }

        return false;
    }

    vector<int> constructArray(int n, int k) {
        vector<int> vis(n + 1, false);
        dfs(1, n, k, vis);
        return res;
    }
};
