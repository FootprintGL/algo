

class Solution {
public:
    vector<int> constructRectangle(int area) {
        /* 从sqrt(area)开始搜索，搜索到的第一个就是最优解 */
        int width = (int) sqrt(area), i;

        for (i = width; i >= 1; i--) {
            if (area % i == 0)
                break;
        }
        
        return {area / i, i};
    }
};


class Solution {
public:
    vector<int> constructRectangle(int area) {
        /* 双指针 - 从sqrt(area)开始搜索，搜索到的第一个就是最优解 */
        vector<int> res(2, 0);
        int l, r;

        l = r = (int) sqrt(area);
        while (l <= r) {
            int t = l * r;
            if (t > area) {
                l--;
            } else if (t < area) {
                r++;
            } else {
                res[0] = r;
                res[1] = l;
                break;
            }
        }

        return res;
    }
};

class Solution {
public:
    vector<int> constructRectangle(int area) {
        /* 双指针 */
        vector<int> res(2, 0);
        int r = area;
        int l = 1;

        while (l <= r) {
            int t = l * r;
            if (t > area) {
                r--;
            } else if (t < area) {
                l++;
            } else {
                res[0] = r;
                res[1] = l;
                l++;
                r--;
            }
        }

        return res;
    }
};
