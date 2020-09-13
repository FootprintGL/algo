

class RecentCounter {
public:
    /* 环形数组 */
    int data[3002];
    int start;
    int end;

    RecentCounter() {
        start = 0;
        end = 0;
        for (auto d : data)
            d = 0;
    }

    int ping(int t) {
        //cout << start << " " << end << " " << t << endl;
        if (start == end) {
            data[end++] = t;
            return end - start;
        }

        data[end++] = t;
        if (end == 3002)
            end = 0;

        while (start < 3002 + end && data[start % 3002] < t - 3000) {
            start++;
            if (start == 3002)
                start = 0;
        }

        return end > start ? end - start : end + 3002 - start;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
