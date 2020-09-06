
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int cnt = 0;
        bool flag = true;

        for (int i = 0; i < arr1.size(); i++) {
            flag = true;
            for (int j = 0; j < arr2.size(); j++) {
                if (abs(arr1[i] - arr2[j]) <= abs(d)) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                cnt++;
        }

        return cnt;
    }
};
