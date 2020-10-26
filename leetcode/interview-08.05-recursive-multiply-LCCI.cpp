


/* 自定义哈希函数 */
struct pair_hash
{
    template<class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2>& p) const
    {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1^h2;
    }
};

class Solution {
public:
    unordered_map<pair<int, int>, int, pair_hash> tbl;

    /* 记忆化递归算法 */
    int multiply(int A, int B) {
        if (A == 1)
            return B;

        if (B == 1)
            return A;

        if (tbl.count({A, B}))
            return tbl[{A, B}];

        int res;

        if (A / 2 <= B)
            res = multiply(A / 2, B) + multiply(A / 2, B);
        else
            res = multiply(B, A / 2) + multiply(B, A / 2);

        if (A % 2)
            res += B;

        tbl[{A, B}] = res;

        return res;
    }
};



class Solution {
public:


    /* 递归算法 */
    int multiply(int A, int B) {
        if (A == 1)
            return B;

        if (B == 1)
            return A;

        int res;
        if (A / 2 <= B)
            res = multiply(A / 2, B) + multiply(A / 2, B);
        else
            res = multiply(B, A / 2) + multiply(B, A / 2);

        if (A % 2)
            res += B;

        return res;
    }
};

/* 超时 */
class Solution {
public:
    /* 递归算法 */
    int multiply(int A, int B) {
        if (A == 1)
            return B;

        if (B == 1)
            return A;

        int res = multiply(A / 2, B) + multiply(A / 2, B);

        if (A % 2)
            res += B;

        return res;
    }
};

