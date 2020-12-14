

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        /*
         * 贪心
         * 维护两个哈希表，一个存放每个剩余数字的个数，另一个存放以该数结尾的满足条件的子序列的个数
         * 遍历数组，假设当前元素为k
         *      1 如果有k - 1的子序列则k接到后面，k的个数减一，并且以k - 1结尾的子序列个数减一
         *        以k结尾的子序列的个数加一
         *      2 如果没有k - 1结尾的子序列，k需要开起一个新的子序列，检查是否有k + 1, k + 2
         *        如果有，则k, k + 1, k + 2 构成一个子序列，k/k+1/k+2个数减1，k + 2结尾的
         *        子序列的个数加一
         *      3 如果当前元素个数为0，数字已经用玩，跳过
         *      4 如果有d元素个数不为0，说明这个数字多出来了，且无法组成连续子序列，可以直接返回false
         * 检查到某个数时，这个数未被消耗完，且既不能和前面组成连续子序列，也不能和右边组成连续子序列时，无法分割
         */
        unordered_map<int, int> freq;
        unordered_map<int, int> seqfreq;

        /* 统计数字个数 */
        for (auto & num : nums)
            freq[num]++;

        for (auto &num : nums) {
            if (freq[num]) {
                /* 当前数字num还有剩余 */
                if (seqfreq[num - 1]) {
                    /* 存在以num - 1结尾的子序列，num接在后面 */
                    seqfreq[num - 1]--;
                    seqfreq[num]++;
                    freq[num]--;
                } else {
                    /* 向后检查能否构成一个长度为3的子序列 */
                    if (freq[num + 1] && freq[num + 2]) {
                        /* 开启一个新的长度为3的子序列 */
                        seqfreq[num + 2]++;
                        freq[num]--;
                        freq[num + 1]--;
                        freq[num + 2]--;
                    } else {
                        /* 不能开起新的子序列，无法分割 */
                        return false;
                    }
                }
            }
        }

        return true;
    }
};


class Solution {
public:
    bool isPossible(vector<int>& nums) {
        /*
         * 哈希表 + 最小堆
         * 当前x
         *      1 如果存在一个子序列以x - 1结尾，长度为k，则可以将x加入该子序列中，得到长度为k + 1的子序列
         *      2 如果不存在，则新建一个包含x的子序列，长度为1
         *      3 如果存在多个子序列以x - 1结尾，应该将x加入长度最短的子序列
         * 哈希表的键为为子序列的最后一个数字，值为最小堆，用于存储所有子序列的长度，堆顶元素为最短子序列
         * 遍历数组，遍历到x时，可以得到以x结尾的子序列
         *      1 如果哈希表中存在以x - 1的子序列，则取出以x - 1结尾的最小的子序列，把x接在后面
         *      2 如果没有以x - 1的子序列，则新建一个长度为1的以x结尾的子序列
         * 数组有序，遍历到x时，数组中所有小于x的元素都已经被遍历过，不会出现当前元素比之前的元素小的情况
         * 遍历结束，检查哈希表中存储的每个子序列的长度是否都大于等于3，即可判断能否分割
         */
        unordered_map<int, priority_queue<int, vector<int>, std::greater<int>>> freq;

        /* 遍历数组，构建哈希表 */
        for (auto &num : nums) {
            if (freq.count(num - 1) && !freq[num - 1].empty()) {
                /* 存在以num - 1结尾的子序列, num接在后面 */
                freq[num].push(freq[num - 1].top() + 1);
                freq[num - 1].pop();
                if (freq[num - 1].empty())
                    freq.erase(num - 1);
            } else {
                /* 不存在以num - 1结尾的子序列，创建一个以num结尾的长度为1的子序列 */
                freq[num].push(1);
            }
        }

        /* 遍历哈希表，检查结果子序列最小长度是否都大于等于3 */
        for (auto &temp : freq) {
            //cout << temp.first << " " << temp.second.top() << endl;
            if (temp.second.top() < 3)
                return false;
        }

        return true;
    }
};
