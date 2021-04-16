

/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node *helper(vector<vector<int>> &grid, int row, int col, int n) {
        int val = grid[row][col];
        Node* cur = new Node();
        bool isleaf = true;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[row + i][col + j] != val)
                    isleaf = false;
            }
            if (isleaf == false)
                break;
        }

        if (isleaf) {
            cur->isLeaf = true;
            cur->val = val;
        } else {
            cur->isLeaf = isleaf;
            cur->val = val;
            cur->topLeft = helper(grid, row, col, n / 2);
            cur->topRight = helper(grid, row, col + n / 2, n / 2);
            cur->bottomLeft = helper(grid, row + n / 2, col, n / 2);
            cur->bottomRight = helper(grid, row + n / 2, col + n / 2, n / 2);
        }

        return cur;
    }

    Node* construct(vector<vector<int>>& grid) {
        /*
         * 当前网格有左上角点[row, col]和网格大小N决定
         * 如果当前网格内所有元素相等，则为叶子节点
         * 否则切分为四个小网格，每个网格大小为N/2
         */
        int n = grid.size();
        if (n == 0)
            return NULL;
        return helper(grid, 0, 0, n);
    }
};
