
class Solution {
public:
    vector<int> diStringMatch(string S) {
        /* 
         * 如果S[i]为I, 填剩下元素最小的
         * 如果S[i]为D，填剩下元素最大的
         */
        int N = S.size(), i;
        vector<int> res(N + 1);
        int l = 0, r = N;

        for (i = 0; i < N; i++) {
            if (S[i] == 'I') {
                res[i] = l++;
            } else {
                res[i] = r--;
            }
        }
        res[N] = l;

        return res;
    }
};


class Solution {
public:
    vector<int> diStringMatch(string S) {
        /*
         * 如果S[i]为I, 填剩下元素最小的
         * 如果S[i]为D，填剩下元素最大的
         */
        int N = S.size(), i;
        vector<int> nums(N + 1);
        vector<int> res(N + 1);

        for (i = 0; i <= N; i++)
            nums[i] = i;

        for (i = 0; i < N; i++) {
            if (S[i] == 'I') {
                res[i] = nums[0];
                nums.erase(nums.begin());
            } else {
                res[i] = nums[nums.size() - 1];
                nums.pop_back();
            }
        }
        res[N] = nums[0];

        return res;
    }
};
