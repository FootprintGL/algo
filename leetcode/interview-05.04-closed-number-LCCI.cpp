class Solution {
public:
    vector<int> findClosedNumbers(int num) {
        /*
         * 比num大的数，从右向左搜索第一个01，01 -> 10, 右边剩下的都移到低位
         * 比num小的数，从右向左搜索第一个10，10 -> 01, 右边剩下的都一道高位
         * 用bitset处理，常规上，低位在右侧，bitset地位在左侧
         */
        int b = -1, s = -1;
        bitset<32> big(num);
        bitset<32> small(num);
        int left, right, i;

        /* 求较小的数10 -> 01*/
        for (i = 1; i < 32; i++) {
            //cout << i << " " << small[i] << " " << small[i - 1] << endl;
            if (small[i] == 1 && small[i - 1] == 0) {
                small.flip(i);
                small.flip(i - 1);
                
                left = 0;
                right = i - 2;
                //cout << left << " " << right << endl;
                while (left < right) {
                    //cout << left << " - " << right << endl;
                    while (left < right && small[left] == 0)
                        left++;

                    while (left < right && small[right] == 1)
                        right--;
                    //cout << left << " -- " << right << endl;
                    if (left == right)
                        break;
                    small.flip(left);
                    small.flip(right);
                    left++;
                    right--;
                }
                //cout << i << " " << small << endl;
                s = (int)small.to_ulong();
                break;
            }
        }

        /* 求较大的数 01 -> 10 */
        for (i = 1; i < 32; i++) {
            //cout << i << " - " << big[i] << " " << big[i - 1] << endl;
            if (big[i] == 0 && big[i - 1] == 1) {
                big.flip(i);
                big.flip(i - 1);
                left = 0;
                right = i - 2;
                //cout << left << " " << right << endl;
                while (left < right) {
                    //cout << left << " - " << right << endl;
                    while(left < right && big[left] == 1)
                        left++;
                    while(left < right && big[right] == 0)
                        right--;
                    //cout << left << " -- " << right << endl;
                    if (left == right)
                        break;
                    big.flip(left);
                    big.flip(right);
                    left++;
                    right--;
                }
                //cout << i << " " << big << endl;
                b = (int)big.to_ulong();
                break;
            }
        }

        //cout << b << " " << s << endl;

        return {b, s};
    }
};



/* 位操作 */
class Solution {
public:
    vector<int> findClosedNumbers(int num) {
        /*
         * 比num大的数，从右向左搜索第一个01，01 -> 10, 右边剩下的都移到低位
         * 比num小的数，从右向左搜索第一个10，10 -> 01, 右边剩下的都一道高位
         */

        /* 求比num大的值 - 搜索01 */
        int cnt = 0, pre = 0, i;
        int small, big;

        for (i = 0; i < 32; i++) {
            int cur = (num >> i) & 1;
            if (cur == 1)
                cnt++;
            if (pre == 1 && cur == 0)
            /* 找到01 */
                break;
            pre = cur;
        }
        //cout << i << " " << cnt << endl;

        if (i == 32) {
            /* 没找到 */
            big = -1;
        } else {
            /* 第i位置1 */
            big = num | (1 << i);
            /* 0 ~ i - 1位置清0 */
            big &= ~((1 << i) - 1);
            /* cnt个1移到最低位 */
            big |= (1 << (cnt - 1)) - 1;
        }

        /* 搜索比num小的值 - 搜索10 */
        cnt = 0;
        pre = 1;
        for (i = 0; i < 32; i++) {
            int cur = (num >> i) & 1;
            if (cur == 1)
                cnt++;
            if (pre == 0 && cur == 1)
            /* 找到01 */
                break;
            pre = cur;
        }

        //cout << i << " - " << cnt << endl;

        if (i == 32) {
            /* 没找到 */
            small = -1;
        } else {
            /* 第i位请0 */
            small = num & (~(1 << i));
            /* i - cnt ~ i - 1位置1 */
            small |= ((1 << cnt) - 1) << (i - cnt);
            /* 0 ~ i - cnt - 1清0 */
            small &= ~((1 << (i - cnt)) - 1);
        }

        cout << big << " " << small << endl;

        return {big, small};
    }
};
