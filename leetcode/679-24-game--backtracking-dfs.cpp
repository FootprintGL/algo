
class Solution {
public:

    bool dfs(vector<double> list) {
        int size = list.size();
/*
        cout << "size-" << size << ": ";
        for (int i = 0; i < size; i++)
            cout << list[i] << " ";
        cout << endl;
*/
        if (size == 1) {
            return fabs(list[0] - 24) <= 1e-6;
        }

        vector<double> list2;
        int i, j, k;
        for (i = 0; i < size; i++) {
            for (j = 0; j < size; j++) {
                if (i != j) {
                    list2.clear();
                    for (k = 0; k < size; k++) {
                        if (k != i && k != j)
                            list2.push_back(list[k]);
                    }
                    for (k = 0; k < 4; k++) {
                        if (k < 2 && i > j)
                            continue;
                        if (k == 0)
                            list2.push_back(list[i] + list[j]);
                        else if (k == 1)
                            list2.push_back(list[i] * list[j]);
                        else if (k == 2) {
                            list2.push_back(list[i] - list[j]);
                        } else {
                            if (list[j] < 1e-6)
                                continue;
                            list2.push_back(list[i] / list[j]);
                        }
                        if (dfs(list2))
                            return true;
                        list2.pop_back();
                    }
                }
            }
        }

        return false;
    }

    /*
     * 回溯算法
     * 开始列表一共4个数字，从列表中拿出2个数，用四种符号计算结果替换两个数字
     * 组成一个3个数字的列表，从3个数中拿出2个，用四种符号计算结果替换两个数字
     * 组成一个2个数字的列表，用四种符号计算结果和24比较，因为浮点数计算，误差小于10e6认为相同
     * 除零非法，浮点数10e6认为是0
     * 加法和乘法满足交换率,2个数字只需要计算一次
     */
    bool judgePoint24(vector<int>& nums) {
        vector<double> list;
        for (auto num : nums) {
            list.push_back((double)num);
        }
        return dfs(list);
    }
};
