
class Solution {
public:
    /* 检测速度为k在h小时内H所有香蕉 */
    bool canfinish(vector<int> &piles, int k, int h) {
        for (int i = 0; i < piles.size(); i++) {
            h -= piles[i] / k;
            if (piles[i] % k)
                h--;
            if (h < 0)
                return false;
        }

        return true;
    }

    int minEatingSpeed(vector<int>& piles, int H) {
        /* 二分法 */
        int n = piles.size(), maxvalue = piles[0];

        /* 最大一堆的香蕉数 */
        for (int i = 1; i < n; i++) {
            if (maxvalue < piles[i])
                maxvalue = piles[i];
        }

        //int left = 1, right = maxvalue, mid;
        int left = 1, right = 1e9, mid;

        while (left <= right) {
            mid = left + (right - left) / 2;
            if (canfinish(piles, mid, H)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};


class Solution {
public:
    /* 检测速度为k在h小时内H所有香蕉 */
    bool canfinish(vector<int> &piles, int k, int h) {
        for (int i = 0; i < piles.size(); i++) {
            h -= piles[i] / k;
            if (piles[i] % k)
                h--;
            if (h < 0)
                return false;
        }

        return true;
    }

    int minEatingSpeed(vector<int>& piles, int H) {
        /* 二分法 */
        int n = piles.size(), maxvalue = piles[0];

        /* 最大一堆的香蕉数 */
        for (int i = 1; i < n; i++) {
            if (maxvalue < piles[i])
                maxvalue = piles[i];
        }

        int left = 1, right = maxvalue, mid;

        while (left <= right) {
            mid = left + (right - left) / 2;
            if (canfinish(piles, mid, H)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};


class Solution {
public:
    /* 检测速度为k在h小时内H所有香蕉 */
    bool canfinish(vector<int> &piles, int k, int h) {
        for (int i = 0; i < piles.size(); i++) {
            h -= piles[i] / k;
            if (piles[i] % k)
                h--;
            if (h < 0)
                return false;
        }

        return true;
    }

    int minEatingSpeed(vector<int>& piles, int H) {
        /* 二分法 */
        sort(piles.begin(), piles.end());

        int n = piles.size(), res;
        int left = 1, right = piles[n - 1], mid;
        //int left = piles[0], right = piles[n - 1], mid;

/*
        if (n == 1) {
            res = piles[0] / H;
            if (piles[0] % H)
                res++;
            return res;
        }

        if (piles[0] == piles[n - 1])
            return piles[0];
*/
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (canfinish(piles, mid, H)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};
