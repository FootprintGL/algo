
//int m;

class Solution {
public:
    void dump(vector<int> &arr) {
        for (auto &t : arr)
            cout << t << " ";
        cout << endl;
    }

    vector<int> getStrongest(vector<int>& arr, int k) {
        vector<int> res;
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int m = arr[(n - 1) / 2];
        //cout << m << endl;
        //dump(arr);
        sort(arr.begin(), arr.end(), [&](int &a, int &b){
            return abs(a - m) == abs(b - m) ? a > b : abs(a - m) > abs(b - m);
        });
        //dump(arr);
        for (int i = 0; i < k; i++)
            res.push_back(arr[i]);

        return res;
    }
};



int m;

class Solution {
public:
    void dump(vector<int> &arr) {
        for (auto &t : arr)
            cout << t << " ";
        cout << endl;
    }

    vector<int> getStrongest(vector<int>& arr, int k) {
        vector<int> res;
        sort(arr.begin(), arr.end());
        int n = arr.size();
        m = arr[(n - 1) / 2];
        //cout << m << endl;
        //dump(arr);
        sort(arr.begin(), arr.end(), [](int &a, int &b){
            return abs(a - m) == abs(b - m) ? a > b : abs(a - m) > abs(b - m);
        });
        //dump(arr);
        for (int i = 0; i < k; i++)
            res.push_back(arr[i]);

        return res;
    }
};
