class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people, 0);
        int cur = 1;
        int i;

        while (candies > 0) {
            for (i = 0; i < num_people; i++) {
                if (candies > cur) {
                    candies -= cur;
                    res[i] += cur;
                    cur++;
                } else {
                    res[i] += candies;
                    candies = 0;
                    break;
                }
            }
        }

        return res;
    }
};
