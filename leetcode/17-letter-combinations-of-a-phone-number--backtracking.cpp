

class Solution {
public:
    vector<string> board;
    vector<string> ans;
    string temp;

    void dfs(string &digits, int size, int start) {
        //cout << size << " " << start << endl;
        if (start == size) {
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < board[digits[start] - '0'- 2].length(); i++) {

            temp.push_back(board[digits[start] - '0' - 2][i]);
            dfs(digits, size, start + 1);
            temp.pop_back();
        }
    }

    void prepareboard()
    {
        board.push_back("abc");
        board.push_back("def");
        board.push_back("ghi");
        board.push_back("jkl");
        board.push_back("mno");
        board.push_back("pqrs");
        board.push_back("tuv");
        board.push_back("wxyz");
    }

    vector<string> letterCombinations(string digits) {
        /* 回溯算法 */
        int len =digits.length();
        if (len == 0)
            return ans;

        prepareboard();
        dfs(digits, len, 0);
        return ans;
    }
};
