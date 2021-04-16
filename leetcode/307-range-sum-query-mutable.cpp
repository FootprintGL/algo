
class NumArray {
public:
    /* 线段树 */
    int n;
    vector<int> tree;

    NumArray(vector<int>& nums) {
        n = nums.size();
        tree.resize(2 * n);
        for (int i = n - 1; i >= 0; i--) {
            tree[i + n] = nums[i];
        }

        /* tree[i] = tree[2 * i] + tree[2 * i + 1] */
        for (int i = n - 1; i >= 0; i--) {
            tree[i] = tree[2 * i] + tree[2 * i + 1];
        }
/*
        for (int i = 0; i < 2 * n; i++)
            cout << tree[i] << " ";
        cout << endl;
    */
    }

    void update(int index, int val) {
        int pos = index + n;
        tree[pos] = val;

        while (pos > 0) {
            int left = (pos % 2) == 0 ? pos : pos - 1;
            int right = (pos % 2) == 0 ? pos + 1 : pos;
            /* tree[i] = tree[2 * i] + tree[2 * i + 1] */
            tree[pos / 2] = tree[left] + tree[right];
            /* 更新i后更新i / 2 */
            pos /= 2;
        }
    }

    int sumRange(int left, int right) {
        int l = left + n;
        int r = right + n;
        int sum = 0;

        while (l <= r) {
            if (l % 2 == 1) {
                /* 左边界是右节点，累加并向右 */
                sum += tree[l];
                l++;
            }
            if (r % 2 == 0) {
                /* 右边界是左节点，累加并向左 */
                sum += tree[r];
                r--;
            }
            l /= 2;
            r /= 2;
        }

        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */



/* 超时 - 前缀和 */
class NumArray {
public:
    /* 前缀和 */
    vector<int> sum;
    int n;

    NumArray(vector<int>& nums) {
        n = nums.size();
        sum.resize(n + 1);
        for (int i = 0; i < n; i++) {
            sum[i + 1] += sum[i] + nums[i];
        }
    }

    void update(int index, int val) {
        /* index位置的数据 */
        int t = sum[index + 1] - sum[index];
        for (int i = index + 1; i <= n; i++)
        /* 更新index+1往后的前缀和 */
            sum[i] += val - t;
    }

    int sumRange(int left, int right) {
        if (left == 0)
            return sum[right + 1];
        else
            return sum[right + 1] - sum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
