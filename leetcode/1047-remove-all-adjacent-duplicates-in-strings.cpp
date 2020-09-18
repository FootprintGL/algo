

class Solution {
public:
    string removeDuplicates(string S) {
        /* 堆栈模拟 */
        string res;

        for (auto const &c : S) {
            if (!res.empty() && c == res.back())
                /* 和栈顶元素相同，弹栈 */
                res.pop_back();
            else
                /* 和栈顶元素不同，进栈 */
                res.push_back(c);
        }

        return res;
    }
};
