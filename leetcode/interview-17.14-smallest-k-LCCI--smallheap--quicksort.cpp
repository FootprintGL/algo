
class Solution {
public:
    int index;

    /* 交换i, j元素 */
    void swap(vector<int> &arr, int i, int j) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }

    void dump(vector<int> &arr) {
        for (auto a : arr)
            cout << a << " ";
        cout << endl;
    }

    /* 
     * 快速排序
     * 寻找pivot的位置
     *  1. 如果刚好为k，则k前面元素即为结果
     *  2. 如果小于k, 则结果在右边
     *  3. 如果大于k，则结果在左边
     * 找到位置k，返回true，否则返回false
     */
    bool quicksort(vector<int> &arr, int start, int end, int k) {
        int pivot = start;
        int left = start + 1, right = end;

        //cout << start << " " << end << endl;
        //dump(arr);

        while (left <= right) {
            while (left <= right && arr[left] <= arr[pivot])
                left++;

            while (left <= right && arr[right] > arr[pivot])
                right--;

            if (left <= right) {
                swap(arr, left, right);
            }
        }

        swap(arr, pivot, right);

        /* 坐标right为pivot的所属位置 */
        if (right == k) {
            /* 等于k，找到位置，更新index，返回true */
            index = right;
            return true;
        }

        if (right > k) {
            /* 大于k，在左边搜索 */
            if(quicksort(arr, start, right - 1, k))
                return true;
        } else {
            /* 小于k，在右边搜索 */
            if (quicksort(arr, right + 1, end, k))
                return true;
        }

        return false;
    }

    vector<int> smallestK(vector<int>& arr, int k) {
        
        vector<int> res;
        index = -1;

        if (k == 0)
            return res;

        quicksort(arr, 0, arr.size() - 1, k);

        //dump(arr);

        for (int i = 0; i < index; i++)
            res.push_back(arr[i]);

        return res;
    }
};



class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        /* 小顶堆 */
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<int> res;

        if (k == 0)
            return res;

        for (auto a : arr)
            pq.push(a);

        for (int i = 0; i < k; i++) {
            res.push_back(pq.top());
            pq.pop();
        }

        return res;
    }
};
