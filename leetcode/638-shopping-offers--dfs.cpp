

class Solution {
public:
    //unordered_map<vector<int>, int> map;

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        /*
         * 记忆化搜索
         * 考虑全部原价购买，sum(needs[i] * price[i])
         * 如果一个礼包special[i]里面没个物品的数量都小于等于needs[i]，则可以使用special[i]
         * 剩下需要购买的物品为needs'[i] = needs[i] - special[i]
         * 此时面临相邻的选项: 先全价购买，再考虑用优惠券
         * needs相同，prices和special选项也相同，可以用map<vector<int>, int>缓存实现记忆化搜索
         * C++ 默认不支持用vector<int>做key，跳过优化
         */
        //if (map.count(needs))
            //return map[needs];

        int res = 0;
        int size = price.size();
        bool valid;
        int i;

        for (i = 0; i < size; i++)
            res += price[i] * needs[i];

        for (auto spec : special) {
            valid = true;
            vector<int> clone = needs;
            for (i = 0; i < size; i++){
                if (spec[i] > clone[i]) {
                    valid = false;
                    break;
                }
                clone[i] -= spec[i];
            }
            if (valid) {
                res = min(res, spec.back() + shoppingOffers(price, special, clone));
            }
        }

        //map[needs] = res;
        return res;
    }
};
