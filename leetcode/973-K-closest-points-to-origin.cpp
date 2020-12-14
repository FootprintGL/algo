

/* 快速排序 */
class Solution {
public:
    /* 计算点p到原点距离 */
    int distance(vector<int> &p) {
        return p[0] * p[0] + p[1] * p[1];
    }

    /* 交换i,j位置元素 */
    void swap(vector<vector<int>> &points, int i, int j) {
        auto t = points[i];
        points[i] = points[j];
        points[j] = t;
    }

    void dump(vector<vector<int>> &points) {
        for (int i = 0; i < points.size(); i++) {
            cout << points[i][0] << " " << points[i][1] << endl;
            
        }
        cout << endl;
    }

    /* 快速排序 */
    void quicksearch(vector<vector<int>> &points, int K, int l, int r) {
        if (l == K)
            return;

        //cout << l << " " << r << " " << K << endl;
        //dump(points);
        
        auto pivot = points[l];
        int i = l, j = r;

        while (i < j) {
            while (i < j && distance(points[j]) > distance(pivot))
                j--;
            //cout << i << " - " << j << endl;
            points[i] = points[j];
            while (i < j && distance(points[i]) <= distance(pivot))
                i++;
            //cout << i << " -- " << j << endl;
            points[j] = points[i];
        }
        points[i] = pivot;

        if (i + 1 == K) {
            return;
        } else if (i + 1 < K) {
            return quicksearch(points, K, i + 1, r);
        } else {
            return quicksearch(points, K, l, i);
        }
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        /* 快速排序 */
        vector<vector<int>> res;
        quicksearch(points, K, 0, points.size() - 1);
        return vector<vector<int>> (points.begin(), points.begin() + K);
    }
};



/* 堆排序 - 优先队列 */
bool comp(vector<int> &p1, vector<int> &p2) {
    return (p1[0] * p1[0] + p1[1] * p1[1]) < (p2[0] * p2[0] + p2[1] * p2[1]);
}

class mycomparison
{
public:
  bool operator() (const vector<int> &p1, const vector<int> &p2) const
  {
    return (p1[0] * p1[0] + p1[1] * p1[1]) < (p2[0] * p2[0] + p2[1] * p2[1]);
  }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> res;
        priority_queue<vector<int>, vector<vector<int>>, mycomparison> pq;
        int i, j, n = points.size();

        /* 对排序 - 优先队列 */
        for (i = 0; i < K && i < n; i++) {
            pq.push(points[i]);
        }

        while (i < n) {
            vector<int> t = pq.top();
            if (comp(points[i], t)) {
                pq.pop();
                pq.push(points[i]);
            }
            i++;
        }

        while (!pq.empty()) {
            res.push_back(pq.top());
            pq.pop();
        }

        return res;
    }
};
