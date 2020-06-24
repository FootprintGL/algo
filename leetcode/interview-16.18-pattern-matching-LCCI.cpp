class Solution {
public:
    bool patternMatching(string pattern, string value) {
        int ca = 0, cb = 0, la = 0, lb = 0, lp = 0, lv = 0;
        string stra, strb;
        char a, b;
        bool valid = true;
        int i, j, k;

        lp = pattern.size();
        lv = value.size();

        /* empty pattern */
        if (lp == 0)
            return lv == 0;
        
        /* empty value or */
        if (lv == 0) {
            /* empty patttern or pattern has only 1 same char*/
            if (lp == 0)
                return true;
            
            a = pattern[0];
            for (i = 1; i < lp; i++) {
                if (a != pattern[i])
                    return false;
            }

            return true;
        }

        /* start with b -> swapping a and b */
        a = 'a';
        b = 'b';
        if (pattern[0] == 'b') {
            a = 'b';
            b = 'a';
        }

        /* calculate ca, cb */
        for (i = 0; i < lp; i++) {
            if (pattern[i] == a)
                ca++;
            else
                cb++;
        }

        /* pattern has only one same char a */
        if (cb == 0) {
            if (lv % lp != 0)
                /* invalid length */
                return false;
            la = lv / lp;
            stra = value.substr(0, la);
            for (i = la; i < lv; i = i + la) {
                if (value.substr(i, la) != stra)
                    return false;
            }

            return true;
        }

        //cout << "ca: " << ca << " cb: " << cb << endl;

        /*
         * enumeration method
         * ca * la + cb * lb = lv
         * ca: 0 -> lv / la
         */
        for (i = 0; i <= lv/ca; i++) {
            if ((lv - ca * i) % cb != 0) {
                //cout << "invalid len: " << i << endl;
                continue;
            }

            la = i;
            lb = (lv - ca * i) / cb;
            stra = value.substr(0, i);
            strb = "";
            k = la;
            valid = true;
            
            for (j = 1; j < lp; j++) {
                if (pattern[j] == a) {
                    if (value.substr(k, la) != stra) {
                        valid = false;
                        break;
                    } else {
                        k += la;
                    }
                } else {
                    if (strb == "") {
                        strb = value.substr(k, lb);
                        k += lb;
                    } else {
                        if (value.substr(k, lb) != strb) {
                            valid = false;
                            break;
                        } else {
                            k += lb;
                        }
                    }
                }
            }

            //cout << "la: " << la << " lb: " << lb << endl;
            //cout << "stra: " << stra << " strb: " << strb << endl << endl;

            if (valid == true)
                return true;
        }

        return false;
    }
};
