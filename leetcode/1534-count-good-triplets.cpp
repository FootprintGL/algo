

class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        /* 暴力 */
        int i, j, k, res = 0, n = arr.size();

        for (i = 0; i < n; i++) {
            for (j = i + 1; j < n; j++) {
                if (abs(arr[i] - arr[j]) <= a) {
                    for (k = j + 1; k < n; k++) {
                        if (abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c)
                            res++;
                    }
                }
            }
        }

        return res;
    }
};

class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        /* 暴力 */
        int i, j, k, res = 0, n = arr.size();

        for (i = 0; i < n; i++) {
            for (j = i + 1; j < n; j++) {
                for (k = j + 1; k < n; k++) {
                    if (abs(arr[i] - arr[j]) <= a && abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c)
                        res++;
                }
            }
        }

        return res;
    }
};
