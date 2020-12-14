
bool compare(vector<int> &v1, vector<int> &v2) {
    /* 第一个元素升序，第二个元素降序 */
    if (v1[0] < v2[0])
        return true;
    else if (v1[0] > v2[0])
        return false;
    else
        return v1[1] > v2[1];
}

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        /*
         * 填坑 - 每次从身高里找最矮的，最矮的里找排名最高的
         * 假设它的排名是i，那么就从左到右把它放在第i个还没有被填过的坑里
         */
        int n = people.size();
        vector<vector<int>> res(n);
        int i, j;

        sort(people.begin(), people.end(), compare);
/*
        for (i = 0; i < n; i++)
            cout << people[i][0] << " " << people[i][1] << " - ";
        cout << endl;
*/
        for (i = 0; i < n; i++) {
            int spaces = people[i][1] + 1;
            for (j = 0; j < n; j++) {
                if (res[j].empty()) {
                    --spaces;
                    if (!spaces) {
                        /* 找到第people[i][1] + 1个空位 */
                        res[j] = people[i];
                        //cout << j << " " << people[i][0] << " " << people[i][1] << endl;
                        break;
                    }
                }
            }
        }

        return res;
    }
};




bool compare(vector<int> &v1, vector<int> &v2) {
    /* 按第一个元素降序，第二个元素升序排列 */
    if (v1[0] > v2[0])
        return true;
    else if (v1[0] < v2[0])
        return false;
    else
        return v1[1] < v2[1];
}

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        /*
         * 套路 - 数对涉及排序，根据第一个元素正向排序，根据第二个元素反向排序
         * 或者根据地一个元素反向排序，根据第二个元素正向排序，可以简化解题过程。
         * 本题根据采用根据第一个元素反向排序，根据第二个元素正向排序的策略。
         * 按元素1降序排序，每个元素前面元素的个数就是大于等于它的元素的数量。
         * 按元素2升序排序，我们希望k大的尽量在后面，减少插入操作的次数
         */
        int n = people.size();
        vector<vector<int>> res;
        int i;

        sort(people.begin(), people.end(), compare);
/*
        for (i = 0; i < n; i++)
            cout << people[i][0] << " " << people[i][1] << endl;
        cout << endl;
*/
        for (i = 0; i < n; i++) {
            if (res.size() <= people[i][1])
                res.push_back(people[i]);
            else
                res.insert(res.begin() + people[i][1], people[i]);
        }

        return res;
    }
};
