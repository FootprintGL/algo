






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
