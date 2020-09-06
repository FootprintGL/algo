

class Solution {
public:
    #define N 10010
    int bit[N];

    int countone(int x) {
        int ans = 0;
        while (x) {
            x &= x - 1;
            ans++;
        }

        return ans;
    }

    bool cmp(int x, int y) {
        return bit[x] == bit[y] ? x < y : bit[x] < bit[y];
    }

    vector<int> sortByBits(vector<int>& arr) {
        for (auto x : arr)
            bit[x] = countone(x);
        sort(arr.begin(), arr.end(), [&](int x, int y) {
            return bit[x] == bit[y] ? x < y : bit[x] < bit[y];
        });
        return arr;
    }
};
