
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt = 0;
        int len = flowerbed.size();

        /* 前后加入哨兵方便处理 */
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.push_back(0);

        for (int i = 1; i <= len; i++) {
            if (flowerbed[i] == 0 && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0) {
                //cout << i << " " << flowerbed[i - 1] << " " << flowerbed[i + 1] << endl;
                flowerbed[i] = 1;
                cnt++;
            }
        }

        return cnt >= n;
    }
};
