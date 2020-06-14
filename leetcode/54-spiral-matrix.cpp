
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top, bottom, left, right;
        int i = 0, j = 0, k = 0;

        /* 特殊情况处理 */
        if (matrix.size() == 0) {
            /* 空矩阵 */
            vector<int> res;
            return res;
        } else if (matrix.size() == 1){
            /* 只有一行 */
            vector<int> res (matrix[0].begin(), matrix[0].end());
            return res;
        } else if (matrix[0].size() == 1) {
            /* 只有一列 */
            vector<int> res (matrix.size(), 0);
            for (i = 0; i < matrix.size(); i++) {
                res[k++] = matrix[i][0];
            }
            return res;
        } else {
            top = 0;
            bottom = matrix.size();
            left = 0;
            right = matrix[0].size();
        }

        /* 螺旋遍历矩阵 */
        k = 0;
        vector<int> res (bottom * right, 0);
        //cout << top << " " << bottom << " " << left << " " << right << " " << endl;

        while (top < bottom && left < right) {
            /* 从左向右遍历最上面一行*/
            for (j = left; j < right; j++) {
                res[k++] = matrix[top][j];
                //cout << res[k-1] << " ";
            }
            /* 更新top，判断终止条件 */
            if (++top == bottom)
                break;
            //cout << endl << "index:" << top << " " << bottom << " " << left << " " << right << endl;

            /* 从上到下遍历最右边一行 */
            for (j = top; j < bottom; j++) {
                res[k++] = matrix[j][right - 1];
                //cout << res[k-1] << " ";
            }
            /* 更新right，判断终止条件 */
            if (--right == left)
                break;
            //cout << endl << "index:" << top << " " << bottom << " " << left << " " << right << endl;

            /* 从右向左遍历最下面一行 */
            for (i = right - 1; i >= left; i--) {
                res[k++] = matrix[bottom - 1][i];
                //cout << res[k-1] << " ";
            }
            /* 更新bottom，判断终止条件 */
            if (--bottom == top)
                break;
            //cout << endl << "index:" << top << " " << bottom << " " << left << " " << right << endl;

            /* 从下到上遍历最左边一行 */
            for (j = bottom - 1; j >= top; j--) {
                res[k++] = matrix[j][left];
                //cout << res[k-1] << " ";
            }
            /* 更新left，判断终止条件 */
            if (++left == right)
                break;
            //cout << endl << "index:" << top << " " << bottom << " " << left << " " << right << endl;
        }

        return res;
    }
};



class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top, bottom, left, right;
        int i = 0, j = 0, k = 0;

        if (matrix.size() == 0) {
            /* 空矩阵处理 */
            vector<int> res;
            return res;
        } else {
            top = 0;
            bottom = matrix.size();
            left = 0;
            right = matrix[0].size();
        }

        /* 螺旋遍历矩阵 */
        k = 0;
        vector<int> res (bottom * right, 0);
        //cout << top << " " << bottom << " " << left << " " << right << " " << endl;

        while (top < bottom && left < right) {
            /* 从左向右遍历最上面一行*/
            for (j = left; j < right; j++) {
                res[k++] = matrix[top][j];
                //cout << res[k-1] << " ";
            }
            /* 更新top，判断终止条件 */
            if (++top == bottom)
                break;
            //cout << endl << "index:" << top << " " << bottom << " " << left << " " << right << endl;

            /* 从上到下遍历最右边一行 */
            for (j = top; j < bottom; j++) {
                res[k++] = matrix[j][right - 1];
                //cout << res[k-1] << " ";
            }
            /* 更新right，判断终止条件 */
            if (--right == left)
                break;
            //cout << endl << "index:" << top << " " << bottom << " " << left << " " << right << endl;

            /* 从右向左遍历最下面一行 */
            for (i = right - 1; i >= left; i--) {
                res[k++] = matrix[bottom - 1][i];
                //cout << res[k-1] << " ";
            }
            /* 更新bottom，判断终止条件 */
            if (--bottom == top)
                break;
            //cout << endl << "index:" << top << " " << bottom << " " << left << " " << right << endl;

            /* 从下到上遍历最左边一行 */
            for (j = bottom - 1; j >= top; j--) {
                res[k++] = matrix[j][left];
                //cout << res[k-1] << " ";
            }
            /* 更新left，判断终止条件 */
            if (++left == right)
                break;
            //cout << endl << "index:" << top << " " << bottom << " " << left << " " << right << endl;
        }

        return res;
    }
};
