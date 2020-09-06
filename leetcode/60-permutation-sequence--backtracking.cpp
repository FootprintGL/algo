class Solution {
public:
    void factorial(vector<int> &fact, int n) {
        fact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i;
        }
    }

    string getPermutation(int n, int k) {
        string ans;
        vector<int> fact(n + 1, 0);
        vector<int> nums(n, 0);
        int i, index;

        /* 计算0 ～ n的阶乘 */
        factorial(fact, n);

        for (i = 1; i <= n; i++)
            nums[i - 1] = i;

        if (k > fact[n])
            return ans;

        /* 找n个数字的全排列中找到下标为k - 1的那个数*/
        k--;
        for (i = n - 1; i >= 0; i--) {
            index = k / fact[i];
            //cout << " " << i << " " << k << " " << fact[i] << " " << index << endl;
            ans.push_back(nums[index] + '0');
            nums.erase(nums.begin() + index);
            k -= index * fact[i];
        }

        return ans;
    }
};



class Solution {
public:
    string ans;

    void factorial(vector<int> &fact, int n) {
        fact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i;
        }
    }

    bool dfs(int n, int k, int start, string &cur, vector<bool> &used, vector<int> &fact) {
        //cout << n << " " << k << " " << start << " " << cur << endl;
        if (start == n) {
            ans = cur;
            return true;
        }

        for (int i = 1; i <= n; i++) {
            if (used[i] == false) {
                if (k > fact[n - start - 1]) {
                    k -= fact[n - start - 1];
                    continue;
                }

                used[i] = true;
                cur.push_back(i + '0');
                if (dfs(n, k, start + 1, cur, used, fact))
                    return true;
                /* 不需要继续 */
                break;
            }
        }

        return false;
    }

    string getPermutation(int n, int k) {
        string cur;
        vector<bool> used (n + 1, false);
        vector<int> fact(n + 1, 0);

        /* 计算0 ～ n的阶乘 */
        factorial(fact, n);
        dfs(n, k, 0, cur, used, fact);
        return ans;
    }
};


/* 回溯算法 */
class Solution {
public:
    string ans;
    int cnt;

    bool dfs(int n, int k, string &cur, vector<bool> &used) {
        if (cur.length() == n) {
            cnt++;
            if (cnt == k) {
                ans = cur;
                return true;
            }
        }

        for (int i = 1; i <= n; i++) {
            if (used[i] == true)
                continue;
            used[i] = true;
            cur.push_back(i + '0');
            if (dfs(n, k, cur, used))
                return true;
            /* 回溯 */
            used[i] = false;
            cur.pop_back();
        }

        return false;
    }

    string getPermutation(int n, int k) {
        vector<bool> used (n + 1, false);
        string path;

        cnt = 0;
        dfs(n, k, path, used);

        return path;
    }
};
