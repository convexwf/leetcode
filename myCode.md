## 646. Maximum Length of Pair Chain

给定一些链对，规定了如果后面链对的首元素大于前链对的末元素，那么这两个链对就可以链起来，问最大能链多少个。

1. 排序 + 贪心算法
   - 按链对的尾元素进行排序，小的放前面。
   - 用一个变量 end 来记录当前比较到的尾元素的值，初始化为最小值，然后遍历的时候，如果当前链对的首元素大于 end，那么结果 res 自增 1，end 更新为当前链对的尾元素

```cpp
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int res = 0, end = INT_MIN;
        sort(pairs.begin(), pairs.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        for (auto pair : pairs) {
            if (pair[0] > end) {
                ++res;
                end = pair[1];
            }
        }
        return res;
    }
};
```
