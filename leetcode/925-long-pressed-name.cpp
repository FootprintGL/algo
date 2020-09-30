

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int l1, r1, l2, r2, cnt1 = 0, cnt2 = 0;
        int n1 = name.length();
        int n2 = typed.length();

        if (n1 == 0 && n2 == 0)
            return true;

        if (n1 == 0 || n2 == 0)
            return false;

        l1 = l2 = 0;
        r1 = r2 = 0;

        while (r1 < n1 && r2 < n2) {
            r1 = l1 + 1;
            while (r1 < n1 && name[r1] == name[l1])
                r1++;
            r2 = l2 + 1;
            while (r2 < n2 && typed[r2] == typed[l2])
                r2++;

            //cout << l1 << " " << r1 << " " << l2 << " " << r2 << " " << name[l1] << " " << typed[l2] << endl;
            if (name[l1] != typed[l2] || (r1 - l1) > (r2 - l2))
                return false;
            l1 = r1;
            l2 = r2;
        }

        //cout << r1 << " " << n1 << " " << r2 << " " << n2 << endl;

        return r1 == n1 && r2 == n2;
    }
};
