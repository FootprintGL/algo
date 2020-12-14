

/* 排序比较函数 - 按评分递减排序，评分相同，按id递减排序 */
bool compare(vector<int> &r1, vector<int> &r2) {
    int rating1 = r1[1], rating2 = r2[1];
    int id1 = r1[0], id2 = r2[0];

    return rating1 == rating2 ? id1 > id2 : rating1 > rating2;
}

class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<int> res;
        /* 排序 - 按评分递减排序，评分相同，按id递减排序 */
        sort(restaurants.begin(), restaurants.end(), compare);
        /* 过滤并返回结果 */
        for (int i = 0; i < restaurants.size(); i++) {
            if (veganFriendly && restaurants[i][2] == 0)
                continue;
            if (restaurants[i][3] > maxPrice)
                continue;
            if (restaurants[i][4] > maxDistance)
                continue;
            res.push_back(restaurants[i][0]);
        }

        return res;
    }
};
