
/* 优先队列最大堆 */
using Pair = pair<int, int>;
struct Cmp{
    bool operator()(pair<int,int>&a,pair<int,int>&b){
        return a.second<b.second;
    }
};
priority_queue<Pair, vector<Pair>, Cmp> pq;

/* istringstream分割句子成单词列表 */

/* 默认分割符号为空格，tab和回车 */
#include <iostream>
#include <sstream>
#include <vector>
 
using namespace std;
 
int main() {
    string str = "hello world sperated by   spaces\tand\nhuiche";
 
    vector<string> arr;
    istringstream ss(str);
    string word;
    while(ss>>word) {
        arr.push_back(word);
    }
 
    for(size_t i=0; i<arr.size(); i++) {
        cout << arr[i] << endl;
    }
     
    return 0;
}
/* 按指定符号分割 */
#include <iostream>
#include <sstream>
#include <vector>
 
using namespace std;
 
int main() {
        std::string data = "1_2_3_4_5_6";
        std::stringstream ss(data);
        std::string item;
        queue<string> q;
        cout << data << endl;
        while (std::getline(ss, item, '_')) 
            cout << item << ' ';  
}

//1_2_3_4_5_6
//1 2 3 4 5 6 



/*lower_bound - 在数组heaters中找到地一个大于等于house[i]第坐标 */
auto larger = lower_bound(heaters.begin(),heaters.end(),houses[i]);
* larger - 取元素
/* upper_bound - [first, last)区间找到第一个大于target的坐标 */



/* pair<int, int>的hash表需要自定义hash函数  */
struct pair_hash
{
    template<class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2>& p) const
    {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1^h2;
    }
};

unordered_set<pair<int, int>, pair_hash> myset;
