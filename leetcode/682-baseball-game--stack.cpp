
class Solution {
public:
    int calPoints(vector<string>& ops) {
        int res = 0;
        int n = ops.size(), tmp;
        stack<int> scores;

        /* 栈模拟 */
        for (auto &str : ops) {
            if (str == "+") {
                int top = scores.top();
                scores.pop();
                int newtop = top + scores.top();
                scores.push(top);
                scores.push(newtop);
            } else if (str == "D") {
                scores.push(2 * scores.top());
            } else if (str == "C") {
                    scores.pop();
            } else {
                scores.push(stoi(str, 0, 10));
            }
        }

        while (!scores.empty()) {
            res += scores.top();
            scores.pop();
        }
        
        return res;
    }
};



class Solution {
public:
    int calPoints(vector<string>& ops) {
        int res = 0;
        int n = ops.size(), tmp;
        vector<int> scores;

        for (auto &str : ops) {
            //cout << str << " " << scores.size() << endl;
            tmp = 0;
            if (str == "+") {
                if (scores.size() == 1)
                    tmp += scores.back();
                else if (scores.size() > 1)
                    tmp += scores.back() + scores[scores.size() - 2];
                //cout << "push-+ " << tmp << endl;
                scores.push_back(tmp);
            } else if (str == "D") {
                if (!scores.empty())
                   tmp = 2 * scores.back();
                scores.push_back(tmp);
                //cout << "push-D " << tmp << endl;
            } else if (str == "C") {
                if (!scores.empty()) {
                    //cout << "pop-C " << scores.back() << endl;
                    scores.pop_back();
                }

            } else {
                tmp = stoi(str, 0, 10);

                //cout << "push-Dig " << tmp << endl;
                scores.push_back(tmp);
            }
        }

        for (auto &score : scores) {
            res += score;
            //cout << score << " ";
        }
        //cout << endl;

        return res;
    }
};
