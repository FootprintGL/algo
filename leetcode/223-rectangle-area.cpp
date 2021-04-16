

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        /*
         * 没有重叠结果为两个矩形面积之和
         * 有重叠结果为两个矩形面积之和减去重叠的部分
         */
        int area = (C - A) * (D - B) + (G - E) * (H - F);
        if (A >= G || B >= H || D <= F || C <= E)
        /* 不重叠 */
            return area;

        /* 重叠 */
        int left = max(A, E);
        int right = min(C, G);
        int top = min(D, H);
        int bottom = max(B, F);

        return area - (right - left) * (top - bottom);
    }
};
