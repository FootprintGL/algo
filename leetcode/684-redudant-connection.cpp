

class Solution {
public:
    vector<int> parent;
    vector<int> res;

    int find_root(int point) {
        //cout << "find- " << point << endl;
        while (parent[point] != point) {
            //cout << point << " " << parent[point] << endl;
            point = parent[point];
        }
        //cout << "return -" << point << endl;

        return point;
    }

    bool union_root(int point1, int point2) {
        int r1 = find_root(point1);
        int r2 = find_root(point2);

        if (r1 == r2) {
            res.push_back(point1);
            res.push_back(point2);
            return true;
        } else {
            parent[r1] = r2;
        }
        return false;
    }



    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        /* 并查集 */
        int n = edges.size(), i;

        for (i = 0; i <= n; i++)
            parent.push_back(i);

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            if (union_root(u, v))
                break;
        }

        return res;
    }
};
