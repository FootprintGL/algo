

class Solution {
public:
    string defangIPaddr(string address) {
        //cout << address << endl;
        for (int i = 0; i < address.length(); i++) {
            if (address[i] == '.') {
                /* 插入之后，i指向[ */
                address.insert(address.begin() + i, '[');
                address.insert(address.begin() + i + 2, ']');
                /* 偏移i使它指向]后面一个数字 */
                i = i + 3;
            }
        }
        //cout << address << endl;

        return address;
    }
};
