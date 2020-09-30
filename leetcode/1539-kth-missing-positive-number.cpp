

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int start = 1, index = 0;
        int missing = 0;

        while (missing < k) {
            if (index < arr.size() && start == arr[index]) {
                start++;
                index++;
                continue;
            }
            //cout << missing << " " << start << " " << index << endl;
            missing++;
            start++;
        }

        return start - 1;
    }
};
