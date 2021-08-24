## 121. Best Time to Buy and Sell Stock ##
+ 解题思路：
    1. 题目描述：买进前必须卖出手头已有的；只允许一次交易
    2. 遍历每天的股价，存储遍历到当前位置的最小值，然后用当前值减去最小值即可得到如果当天卖出得到最大的利润。
    3. 注意利润值可能为负数，这时候可以不交易保证不亏本（即返回最小为0）

```C++
// 2020-01-01 submission
// Runtime: 8 ms, faster than 97.15% of C++ online submissions for Best Time to Buy and Sell Stock.
// Memory Usage: 13.3 MB, less than 11.11% of C++ online submissions for Best Time to Buy and Sell Stock.
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int minPrice = prices[0];
        int maxPro = INT_MIN;
        for(int i = 1; i < prices.size(); i++) {
            maxPro = max(maxPro, prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }
        return maxPro > 0 ? maxPro : 0;
    }
};
```

## 122. Best Time to Buy and Sell Stock II ##
+ 解题思路：
    1. 题目描述：买进前必须卖出手头已有的；允许无数次交易
    2. 只要前后两数呈递增关系，则可以进行交易。

```C++
// 2020-01-01 submission
// Runtime: 12 ms, faster than 76.16% of C++ online submissions for Best Time to Buy and Sell Stock II.
// Memory Usage: 13.1 MB, less than 63.22% of C++ online submissions for Best Time to Buy and Sell Stock II.
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxValue = 0;
        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] > prices[i-1])
                maxValue += (prices[i]-prices[i-1]);
        }
        return maxValue;
    }
};
```

## 123. Best Time to Buy and Sell Stock III ##
+ 解题思路：
    1. 题目描述：买进前必须卖出手头已有的；允许最多两次交易
    2. 在数组中间画条线，在左边进行第一次交易，在右边进行第二次交易，来计算两次交易的最大收益和。这样，就将问题简化为只进行一次交易的问题了。
    3. 维护两个数组，分别存储截止到第$x$日交易的最大利润和第$x$日之后交易的最大利润。

```C++
// 2020-07-23 submission
// Runtime: 24 ms, faster than 23.09% of C++ online submissions for Best Time to Buy and Sell Stock III.
// Memory Usage: 13.5 MB, less than 31.24% of C++ online submissions for Best Time to Buy and Sell Stock III.
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int days = prices.size();
        vector<int> front(days, 0), latter(days, 0);
        
        int min_price = prices[0], max_price = prices[days-1];
        for (int i = 1; i < days; i++) {
            min_price = min(min_price, prices[i]);
            front[i] = max(front[i-1], prices[i]-min_price);
            // cout << "front " << prices[i] << " " << front[i] << endl;
        }
        for (int i = days - 2; i >= 0; i--) {
            max_price = max(max_price, prices[i]);
            latter[i] = max(latter[i+1], max_price-prices[i]);
            // cout << "latter " << prices[i] << " " << latter[i] << endl;
        }
        
        int max_profit = 0;
        for (int pivot = 0; pivot < days; pivot++) {
            max_profit = max(max_profit, front[pivot]+latter[pivot]);
        }
        return max_profit;

    }
};
```

## $\color{red}188$. Best Time to Buy and Sell Stock IV ##

+ 解题思路：
    1. 题目描述：买进前必须卖出手头已有的；允许最多$k$次交易
    2. 维护两个变量：全局最优 ***global*** 和局部最优 ***local***。定义局部最优$\it{local}[i][j]$为在到达第$i$天时最多可进行$j$次交易并且最后一次交易在最后一天卖出的最大利润,全局最优$\it{global}[i][j]$为在到达第$i$天时最多可进行$j$次交易的最大利润。
    3. 递推式为 
     $$local[i][j] = max(global[i - 1][j - 1] + max(\it{diff}, 0), local[i - 1][j] + \it{diff})$$ $$global[i][j] = max(local[i][j], global[i - 1][j])$$ 其中局部最优值是比较前一天并少交易一次的全局最优加上大于0的差值，和前一天的局部最优加上差值后相比，两者之中取较大值，而全局最优比较局部最优和前一天的全局最优。
    4. 上面的算法中对于天数需要一次扫描，而每次要对交易次数进行递推式求解，所以时间复杂度是$O(n*k)$，如果是最多进行两次交易，那么复杂度还是$O(n)$。空间上只需要维护当天数据皆可以，所以是$O(k)$，当k=2，则是$O(1)$。
    5. 为了减少运算次数，当$k$远大于天数时，按照**122. Best Time to Buy and Sell Stock II**中无限次数交易的方法求解。
    6. 参见
    + Best Time to Buy and Sell Stock III -- LeetCode_Code Ganker-CSDN博客_best time to buy and sell stock iii https://blog.csdn.net/linhuanmars/article/details/23236995
    + [LeetCode] Best Time to Buy and Sell Stock IV 买卖股票的最佳时间之四 - Grandyang - 博客园 https://www.cnblogs.com/grandyang/p/4295761.html
+ 不明白的事情
    1. 为什么要j从k遍历到1，而不是1遍历到k
    2. 为什么局部最优第二个加项里面可以直接加diff

```C++
// 2020-07-24 submission
// Runtime: 4 ms, faster than 99.86% of C++ online submissions for Best Time to Buy and Sell Stock IV.
// Memory Usage: 12 MB, less than 87.45% of C++ online submissions for Best Time to Buy and Sell Stock IV.
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty()) return 0;
        if (k > prices.size()) return maxProfit_largetrades(prices);
        vector<int> local(k+1, 0), global(k+1, 0);
        for (int day = 1; day < prices.size(); day++) {
            int diff = prices[day] - prices[day-1];
            for (int j = k; j >= 1; j--) {
                local[j] = max(global[j-1]+max(diff, 0), local[j]+diff);
                global[j] = max(local[j], global[j]);
                // cout << "day:" << day << " j:" << j << " local:"<<local[j] << " global:" << global[j] << endl;
            }
        }
        return global[k];
    }
    
    int maxProfit_largetrades(vector<int>& prices) {
        int maxValue = 0;
        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] > prices[i-1])
                maxValue += (prices[i]-prices[i-1]);
        }
        return maxValue;
    }
};
```