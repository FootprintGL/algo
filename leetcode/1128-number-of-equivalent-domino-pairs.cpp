
class Solution {
public:
    bool equal(vector<int> &a1, vector<int> &a2) {
        return (a1[0] == a2[0] && a1[1] == a2[1]) || (a1[0] == a2[1] && a1[1] == a2[0]);
    }

    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        /* 哈希表 */
        unordered_map<int, int> tbl;
        int key, ans = 0;

        for (auto &arr : dominoes) {
            key  = arr[0] > arr[1] ? arr[0] * 10 + arr[1] : arr[1] * 10 + arr[0];
            tbl[key]++;
        }

        for (auto &[k, cnt] : tbl) {
            ans += cnt * (cnt - 1) / 2;
        }

        return ans;
    }
};


/* 超时 */
class Solution {
public:
    bool equal(vector<int> &a1, vector<int> &a2) {
        return (a1[0] == a2[0] && a1[1] == a2[1]) || (a1[0] == a2[1] && a1[1] == a2[0]);
    }

    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        /* 暴力 */
        int ans = 0;
        for (int i = 0; i < dominoes.size(); i++) {
            for (int j = i + 1; j < dominoes.size(); j++) {
                if (equal(dominoes[i], dominoes[j]))
                    ans++;
            }
        }

        return ans;
    }
};
