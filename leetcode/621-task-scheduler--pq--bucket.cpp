
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        /*
         * 桶思想
         * 建立大小为n + 1的桶，个数是任务数量最多的那个任务
         * 1. 假设没有其他任务
         * 2. 其他任务可以插入空闲时间
         * 总排队时间 = (桶个数 - 1) * (n + 1) + 最后一桶的任务数
         * 3. 空闲时间很短，任务种类很多时
         * 不存在空余时间，总排队时间 = 任务的数量
         */
        int len = tasks.size();
        vector<int> vec(26, 0);
        int cnt = 1;

        for (auto &t : tasks)
            vec[t - 'A']++;
        
        //sort(vec.begin(), vec.end(), std::greater<int>);
        sort(vec.begin(), vec.end(), [](int &x, int &y){return x > y;});

        while (cnt < vec.size() && vec[cnt] == vec[0])
            cnt++;

        return max(len, cnt + (n + 1) * (vec[0] - 1));
    }
};



class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        /*
         * 排序/优先队列
         * 规定n + 1个任务为一轮，同一轮中一个任务最多被安排一次
         * 每一轮中选择剩余次数最多的n + 1个任务依次执行
         * 如果任务数t小于n + 1, 选择全部t个任务，剩余时间空闲
         * 利用优先队列按剩余次数降序排列
         */
        int res = 0;
        //priority_queue<int, vector<int>, std::greater<int>> pq;
        priority_queue<int> pq;
        int tasknum = tasks.size();
        int cnt[26] = {0};
        int i;

        /* 统计每个任务的数量 */
        for (auto &t : tasks)
            cnt[t - 'A']++;

        /* 任务数量放入优先队列 */
        for (i = 0; i < 26; i++)
            if (cnt[i])
                pq.push(cnt[i]);

        while (!pq.empty()) {
            vector<int> temp;
            for (i = 0; i < n + 1; i++) {
                /* n + 1个为一轮 */
                if (!pq.empty()) {
                    int cur = pq.top();
                    pq.pop();
                    cur--;
                    if (cur > 0)
                        /* 当前任务还有 */
                        temp.push_back(cur);
                }
                res++;
                //cout << "pq size " << pq.size() << " temp size " << temp.size() << endl;
                if (pq.empty() && temp.empty())
                /* 处理完毕，退出 */
                    break;
            }
            //cout << "temp size " << temp.size() << endl;
            for (auto &t : temp)
            /* 放回还有剩余次数的任务 */
                pq.push(t);
        }

        return res;
    }
};
