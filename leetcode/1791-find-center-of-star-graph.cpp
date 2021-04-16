

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        /* 找出任意两条边的公共顶点 - edges[0]和edges[1]的公共顶点 */
        if (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1])
            return edges[0][0];
        else
           return edges[0][1];
    }
};
