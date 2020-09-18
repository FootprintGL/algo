
class Solution {
public:
    void helper(int n, vector<int>& A, vector<int>& B, vector<int>& C) {
        if (n == 0)
            return;

        if (n == 1) {
            C.push_back(A.back());
            A.pop_back();
            return;
        }

        helper(n - 1, A, C, B);
        helper(1, A, B, C);
        helper(n - 1, B, A, C);
    }

    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
        helper(A.size(), A, B, C);
    }
};


class Solution {
public:
    void helper(int n, vector<int>& A, vector<int>& B, vector<int>& C) {
        if (n == 0)
            return;

        if (n == 1) {
            C.push_back(A.back());
            A.pop_back();
            return;
        }

        if (n == 2) {
            B.push_back(A.back());
            A.pop_back();
            C.push_back(A.back());
            A.pop_back();
            C.push_back(B.back());
            B.pop_back();
            return;
        }

        helper(n - 1, A, B, C);
        helper(1, A, C, B);
        helper(n - 1, C, B, A);
        helper(1, B, A, C);
        helper(n - 1, A, B, C);
    }

    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
        helper(A.size(), A, B, C);
    }
};
