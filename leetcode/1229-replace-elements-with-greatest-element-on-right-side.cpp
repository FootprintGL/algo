

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int maxvalue = arr[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            int tmp = max(maxvalue, arr[i]);
            arr[i] = maxvalue;
            maxvalue = tmp;
        }
        arr[n - 1] = -1;

        return arr;
    }
};
