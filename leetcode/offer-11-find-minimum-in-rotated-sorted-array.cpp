





class Solution {
public:
    int minArray(vector<int>& numbers) {
        int ans = 0;
        int len = numbers.size();
        int i = len - 1;

        if (len == 1)
            return numbers[0];

        while (i >= 1) {
            if (numbers[i - 1] <= numbers[i])
                i--;
            else
                break;
        }

        return i == 0 ? min(numbers[0], numbers[1]) : numbers[i];
    }
};
