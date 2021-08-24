# Math

## 50. Pow(x, n)

解题思路

1. 递归回溯

```C++
// 2018-07-24 submission
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Pow(x, n).
// Memory Usage: 6.2 MB, less than 63.60% of C++ online submissions for Pow(x, n).
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        if(n == 1) return x;
        if(n == -1) return 1 / x;
        double temp = myPow(x, n/2);
        if(n % 2 != 0) return temp * temp * myPow(x, n%2);
        else return temp * temp;
    }
};
```
