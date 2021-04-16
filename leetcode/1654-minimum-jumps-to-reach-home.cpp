

class Solution {
public:
    struct pt {
        int now;
        int step;
        int rear;
        pt(int a, int b, int c) : now(a), step(b), rear(c) {}
    };

    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        /*
         * BFS
         * 每次都要做选择，可以用BFS或DFS，只要寻找最小跳跃次数，无须记录每一步位置，BFS
         * 需要flag标记当前位置上次是向前跳跃到达，还是向后跳跃到达
         * 往前跳的点需要排除，往后跳的点不需要排除，因为之前的点，可能会通过往前跳到这个点上
         * 前进去过的地方,后退就没必要再去了，因为前进去过的地方，既可以前进又可以后退。但后退
         * 去过的地方只能前进，所以前进还得再搜一下，看后退符不符合条件。
         */
        unordered_set<int> vis(forbidden.begin(), forbidden.end());
        int end = max(x, *max_element(forbidden.begin(), forbidden.end())) + a + b;
        pt point(0, 0, 0);
        queue<pt> qu;
        qu.push(point);

        while (!qu.empty()) {
            auto p = qu.front();
            qu.pop();
            if (p.now == x)
                return p.step;

            if (p.now < end && vis.find(p.now + a) == vis.end()) {
                /* 向前跳到达的点需要排除 */
                vis.insert(p.now + a);
                qu.push(pt(p.now + a, p.step + 1, 0));
            }

            if (p.rear == 0 && vis.find(p.now - b) == vis.end() && p.now - b > 0) {
                /* 往后跳到达的点不需要排除 */
                qu.push(pt(p.now - b, p.step + 1, 1));
            }
        }

        return -1;
    }
};
