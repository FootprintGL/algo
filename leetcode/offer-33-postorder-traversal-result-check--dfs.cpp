


class Solution {
public:
    bool dfs(vector<int> &postorder, int left, int right) {
        //cout << left << " " << right << endl;
        if (left >= right)
            return true;

        int root = postorder[right];
        int mid = left;
        while (mid < right && postorder[mid] < root)
        /* 从左向右找第一个大于root的元素 */
            mid++;

        int tmp = mid;
        while (tmp < right && postorder[tmp] > root)
            tmp++;

        if (tmp != right)
        /* 右半部分存在小于root的元素 */
            return false;

        return dfs(postorder, left, mid - 1) && dfs(postorder, mid, right - 1);
    }

    bool verifyPostorder(vector<int>& postorder) {
        /*
         * 二叉搜索树
         * 左子树 < root < 右子树
         * 后序遍历最后一个元素为根节点
         * 以根节点为把数组分为左右子树
         * 左边小于根节点的值，右边大于根节点的值
         * 如果不满足，则不是二叉搜索树
         */
        return dfs(postorder, 0, postorder.size() - 1);
    }
};
