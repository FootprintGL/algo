


class Solution {
public:
    vector<int> swapNumbers(vector<int>& numbers) {
        /*
         * a ^ b ^ b = a
         * a ^ b ^ a = b
         * a ^ a = 0
         * a ^ 0 = a
         * 异或满足交换律和结合律
         */
        numbers[0] = numbers[0] ^ numbers[1]; //a = a ^ b
        numbers[1] = numbers[0] ^ numbers[1]; //b = a ^ b ^ b -> a
        numbers[0] = numbers[0] ^ numbers[1]; //a = a ^ b ^ a = b
        return numbers;
    }
};
