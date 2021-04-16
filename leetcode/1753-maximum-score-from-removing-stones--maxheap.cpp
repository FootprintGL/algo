
class Solution {
public:
    int maximumScore(int a, int b, int c) {
        /*
         * 数学方法
         * 先排序a, b, c
         *      如果a + b <= c, c不会被取完，结果为a + b
         *      如果a + b > c, 这种情况去完后c一定为0，否则a和b被取空，c没有充分利用
         *          取c时尽量保证a,b接近即可，c比b大，先让b减到a，然后循环去{a,c}和{b,c}
         *          c为0时，a要么等于b，要么和b差1
         *          结果为c + (a + b - c) / 2 = (a + b + c) / 2
         */
        int tmax = max(a, max(b, c));

        if (2 * tmax >= a + b + c)
            return a + b + c - tmax;
        else
            return (a + b + c) / 2;
    }
};

class Solution {
public:
    int maximumScore(int a, int b, int c) {
        /* 最大堆 - 从两个石头最多的堆里取 */
        priority_queue<int> pq;
        int res = 0;

        pq.push(a);
        pq.push(b);
        pq.push(c);

        while (pq.size() > 1) {
            int fmax = pq.top();
            pq.pop();
            int smax = pq.top();
            pq.pop();
            fmax--;
            smax--;
            res++;
            if (fmax > 0)
                pq.push(fmax);
            if (smax > 0)
                pq.push(smax);
        }

        return res;
    }
};
