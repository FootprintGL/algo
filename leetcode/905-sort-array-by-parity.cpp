class Solution {
public:
    void swap(vector<int> &A, int l, int r) {
        int tmp = A[l];
        A[l] = A[r];
        A[r] = tmp;
    }

    vector<int> sortArrayByParity(vector<int>& A) {
        int n = A.size();
        if (n < 2)
            return A;

        int l = 0, r = n - 1;

        /* 双指针 */
        while (l < r) {
            //cout << l << " " << r << endl;
            if ((A[l] & 1) == 0) {
                /* 偶数 */
                l++;
            } else if ((A[r] & 1) == 1) {
                /* 奇数 */
                r--;
            } else if ((A[l] & 1) == 1 && (A[r] & 1) == 0){
                swap(A, l, r);
                l++;
                r--;
            }
        }

/*
        for (auto a : A)
            cout << a << " ";
        cout << endl;
*/
        return A;
    }
};

class Solution {
public:
    void swap(vector<int> &A, int l, int r) {
        int tmp = A[l];
        A[l] = A[r];
        A[r] = tmp;
    }

    vector<int> sortArrayByParity(vector<int>& A) {
        int n = A.size();
        if (n < 2)
            return A;

        int l = 0, r = n - 1;

        /* 双指针 */
        while (l < r) {
            while (l < r && A[l] % 2 == 0)
                l++;

            if (l == r)
                break;

            while (r > l && A[r] % 2 == 1)
                r--;

            if (l == r)
                break;

            //cout << l << " - " << r << endl;

            swap(A, l, r);
            l++;
            r--;
        }

/*
        for (auto a : A)
            cout << a << " ";
        cout << endl;
*/
        return A;
    }
};
