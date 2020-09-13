
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> res;
        int mindiff, i;

        sort(arr.begin(), arr.end());
        mindiff = arr[1] - arr[0];
        res.push_back({arr[0], arr[1]});
        for (i = 2; i < arr.size(); i++) {
            int diff = arr[i] - arr[i - 1];
            if (diff < mindiff) {
                mindiff = diff;
                res.clear();
                res.push_back({arr[i - 1], arr[i]});
            } else if (diff == mindiff) {
                res.push_back({arr[i - 1], arr[i]});
            }
        }

        return res;
    }
};
