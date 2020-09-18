

class Solution {
public:
    int add(int a, int b) {
        /* ^ - 无进位加法，&进位 */
        while (b) {
	    /* unsigned int - int的话carrier移位会溢出 */
            unsigned int carrier = a & b;
            a = a ^ b;
            b = carrier << 1;
        }

        return a;
    }
};
