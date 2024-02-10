
## 494. Target Sum

给定一个非负整数数组和一个目标值，给数组中每个数字加上正号或负号，然后求和要和目标值相等。

1. BFS
2. 背包问题
   - `Sum(positive) - Sum(negative) = S`，`Sum(positive)+Sum(negative)=total`，两式相加得 `2 * Sum(positive) = (S+total)`
   - 题目等价于从 nums 里任取若干使其和为（S+total) / 2

```cpp
// 2021-03-21 submission
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        unordered_map<int, int> m;
        vector<pair<int, int>> can;
        m[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (auto it : m) {
                if (it.second > 0) {
                    can.push_back(make_pair(it.first+nums[i], it.second));
                    can.push_back(make_pair(it.first-nums[i], it.second));
                    m[it.first] = 0;
                }
            }
            for (auto it : can) {
                m[it.first] += it.second;
            }
            can.clear();
        }
        return m[S];
    }
};
```

```cpp
class Solution {
public:
    int findTargetSumWays(vector & nums, int sum)
    {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (sum > total || sum < -total) return 0;
        if ((total + sum) & 1 != 0) return 0; // S, total 奇偶性必须相同
        int target = (total + sum) / 2;
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int n : nums)
        {
            int k0 = static_cast<int>(dp.size()) - 1 - n;
            for (int k = k0; k >= 0; --k) {
                dp[k + n] += dp[k];
            }
        }
        return dp.back();
    }
};
```

## 912. Sort an Array

数组排序。

1. 归并排序
2. 堆排序
   - 注意从 n/2-1 开始进行 siftdown
   - siftdown 比较值是让最开始的 parent 值和 child 值做比较
3. 快速排序
   - 快排在有序数组排序时，复杂度会退化到 O(n^2)
4.
5. 计数排序

**边界条件**

1. 完全有序的数组
2. 数组中的元素完全相等

## 935. Knight Dialer

![chess knight](https://gitlab.com/convexwf/convex-resource/-/raw/master/convex-notes/leetcode-chess_knight.png)

![phone pad](https://gitlab.com/convexwf/convex-resource/-/raw/master/convex-notes/leetcode-phone_pad.png)

将骑士放在电话拨号盘的任意数字键上，接下来，骑士将会跳 N-1 步。每一步必须是从一个数字键跳到另一个数字键。每当它落在一个键上（包括骑士的初始位置），都会拨出键所对应的数字，总共按下 N 位数字。能用这种方式拨出多少个不同的号码？

```txt
0 -> 4, 6
1 -> 6, 8
2 -> 7, 9
3 -> 4, 8
4 -> 3, 9, 0
5 ->
6 -> 1, 7, 0
7 -> 2, 6
8 -> 1, 3
9 -> 4, 2
```

1. 动态规划
2. 矩阵相乘：[yiduobo的每日leetcode 935.骑士拨号器 - 知乎](https://zhuanlan.zhihu.com/p/357643959)

## 149. Max Points on a Line

给了一堆二维点，求最大的共线点的个数。

判断三点共线的方法：A(ax,ay), B(bx,by), C(cx,cy)

(1) 斜率解法：判断 `(ay-by)/(ax-bx) == (cy-by)/(cx-bx)`
  当 `ax == bx` 或 `cx == bx` 时需要特殊判断，注意使用 gcd 化简分子分母比较，不要使用浮点结果比较，可能会有误差
(2) 周长判断解法：排序周长 `AC > AB > BC`，判断 `AC == AB + BC`
  由于 sqrt 开方运算会导致结果不准确，不稳定，在三角形接近扁平时，结果有误差。
(3) 最优解法：面积判断，判断 `area(ABC) == 0`
  `area(ABC) = 1/2 * ( AC X BC )  = 1/2 *((ax-cx)*(by-cy)-(bx-cx)*(ay-cy))`
  判断 `(ax-cx)*(by-cy) == (bx-cx)*(ay-cy)` 即可

1. 暴力解法 O(n^3)：
2. 斜率计算
   -
   - 通过斜率来判断共线需要用到除法，为了更加精确无误的计算共线，应当避免除法，这里把除数和被除数都保存下来，不做除法，但是要让这两数分别除以它们的最大公约数

**边界条件**

1. 当两个点重合时，无法确定一条直线，但这也是共线的情况
2. 斜率不存在的情况，由于两个点 (x1, y1) 和 (x2, y2) 的斜率k表示为 (y2 - y1) / (x2 - x1)，那么当 x1 = x2 时斜率不存在。


```cpp
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int res = 0;
        for (int i = 0; i < points.size(); ++i) {
            int duplicate = 1;
            for (int j = i + 1; j < points.size(); ++j) {
                int cnt = 0;
                long long x1 = points[i][0], y1 = points[i][1];
                long long x2 = points[j][0], y2 = points[j][1];
                if (x1 == x2 && y1 == y2) {++duplicate; continue;}
                for (int k = 0; k < points.size(); ++k) {
                    int x3 = points[k][0], y3 = points[k][1];
                    if (x1 * y2 + x2 * y3 + x3 * y1 - x3 * y2 - x2 * y1 - x1 * y3 == 0) {
                        ++cnt;
                    }
                }
                res = max(res, cnt);
            }
            res = max(res, duplicate);
        }
        return res;
    }
};
```

```cpp
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int res = 0;
        for (int i = 0; i < points.size(); ++i) {
            map<pair<int, int>, int> m;
            int duplicate = 1;
            for (int j = i + 1; j < points.size(); ++j) {
                if (points[i][0] == points[j][0] && points[i][1] == points[j][1]) {
                    ++duplicate;
                    continue;
                }
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                int d = gcd(dx, dy);
                ++m[{dx / d, dy / d}];
            }
            res = max(res, duplicate);
            for (auto it = m.begin(); it != m.end(); ++it) {
                res = max(res, it->second + duplicate);
            }
        }
        return res;
    }
    int gcd(int a, int b) { // a == 0 or b == 0, return max(a, b)
        return (b == 0) ? a : gcd(b, a % b);
    }
};
```

```cpp
// 2020-07-19 submission
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if (points.empty()) return 0;
        int max_num = 0;
        for (int i = 0; i < points.size(); i++) {
            map<pair<int, int>, int> collect;
            int max_cur = 0;
            for (int j = 0; j < points.size(); j++) {
                max_cur = max(max_cur, gcd(points[i][0]-points[j][0], points[i][1]-points[j][1], collect));
            }
            max_num = max(max_num, max_cur + collect[pair<int, int>{0, 0}]);
            // cout << max_num <<endl;
        }
        return max_num;
    }

    int gcd(int x, int y, map<pair<int, int>, int>& collect) {
        int cnt = 0;
        if ( x == 0 && y == 0) {
            ++collect[pair<int, int>{0, 0}];
        }
        else if (x == 0) {
            cnt = ++collect[pair<int, int>{0, 1}];
        }
        else if (y == 0) {
            cnt = ++collect[pair<int, int>{1, 0}];
        }
        else {
            int t = 0;
            int a = abs(x), b = abs(y), op = abs(x)/x*abs(y)/y;
            while(b > 0) {
                t = a % b;
                a = b;
                b = t;
            }
            cnt = ++collect[pair<int, int>{abs(x)/a*op, abs(y)/a}];
        }
        return cnt;
    }
};
```


## 87. Scramble String

使用下面描述的算法可以扰乱字符串 s 得到字符串 t ：

- 如果字符串的长度为 1 ，算法停止
- 如果字符串的长度 > 1 ，执行下述步骤：
  - 在一个随机下标处将字符串分割成两个非空的子字符串。即，如果已知字符串 s ，则可以将其分成两个子字符串 x 和 y ，且满足 s = x + y 。
  - 随机 决定是要「交换两个子字符串」还是要「保持这两个子字符串的顺序不变」。即，在执行这一步骤之后，s 可能是 s = x + y 或者 s = y + x 。
  - 在 x 和 y 这两个子字符串上继续从步骤 1 开始递归执行此算法。
  - 给定两个 长度相等 的字符串 s1 和 s2，判断 s2 是否是 s1 的扰乱字符串。如果是，返回 true ；否则，返回 false 。

s1 和 s2 是 scramble 的话，那么必然存在一个在 s1 上的长度 l1，将 s1 分成 s11 和 s12 两段，同样有 s21 和 s22，那么要么 s11 和 s21 是 scramble 的并且 s12 和 s22 是 scramble 的；要么 s11 和 s22 是 scramble 的并且 s12 和 s21 是 scramble 的。

1. 递归
   - 将字符串按照不同长度进行切割，然后让子递归函数判断是否成立。注意一个词和它自身是 scramble 的。
   - 为了减少复杂度，每次切割前可以采用排序或者统计字母频率等。

TODO：https://github.com/grandyang/leetcode/issues/87

```cpp
// 2020-07-16 submission
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        if(s1 == s2) return true;
        int len = s1.length();

        int freq[26] = {0};
        for (int i = 0; i < len; i++) {
            ++freq[s1[i]-'a'];
            --freq[s2[i]-'a'];
        }
        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0) return false;
        }

        for (int i = 1; i < len; i++) {
            string s11 = s1.substr(0, i);
            string s12 = s1.substr(i);
            string s21 = s2.substr(0, i);
            string s22 = s2.substr(i);
            if (isScramble(s11, s21) && isScramble(s12, s22)) return true;

            s21 = s2.substr(0, len - i);
            s22 = s2.substr(len - i);
            if (isScramble(s11, s22) && isScramble(s12, s21)) return true;
        }
        return false;
    }
};
```

## 327. Count of Range Sum

求数组中，值位于范围 [lower, upper] (包含lower 和upper) 之内的区间和的个数。

1. multiset
   - 首先计算出一个累计和数组 accum，`accum[i]=accum[i-1]+nums[i]` 那问题可以转化为求解所有的区间 (j, i]，满足 `lower <= accum[i]-accum[j] <= upper`，亦可写成 `accum[i]-upper <= accum[j] <= accum[i]-lower`。
   - lower_bound() 是找数组中第一个不小于给定值的数(包括等于情况)，而 upper_bound() 是找数组中第一个大于给定值的数，distance() 方法返回两个迭代器之间的距离。
2. 归并排序(TODO)

**边界条件**

1. 出现 INT_MIN 和 INT_MAX

```cpp
// 2020-11-26 submission
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        if (nums.empty()) return 0;
        multiset<long long> st{0};
        long long cur_sum = 0; // 后续有减法操作避免溢出
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            cur_sum += nums[i];
            res += distance(st.lower_bound(cur_sum-upper), st.upper_bound(cur_sum-lower));
            st.insert(cur_sum); // why this expression after
        }
        return res;
    }
};
```

```cpp
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long> sums(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); ++i) {
            sums[i + 1] = sums[i] + nums[i];
        }
        return countAndMergeSort(sums, 0, sums.size(), lower, upper);
    }
    int countAndMergeSort(vector<long>& sums, int start, int end, int lower, int upper) {
        if (end - start <= 1) return 0;
        int mid = start + (end - start) / 2;
        int cnt = countAndMergeSort(sums, start, mid, lower, upper) + countAndMergeSort(sums, mid, end, lower, upper);
        int j = mid, k = mid, t = mid;
        vector<int> cache(end - start, 0);
        for (int i = start, r = 0; i < mid; ++i, ++r) {
            while (k < end && sums[k] - sums[i] < lower) ++k;
            while (j < end && sums[j] - sums[i] <= upper) ++j;
            while (t < end && sums[t] < sums[i]) cache[r++] = sums[t++];
            cache[r] = sums[i];
            cnt += j - k;
        }
        copy(cache.begin(), cache.begin() + t - start, sums.begin() + start);
        return cnt;
    }
};
```


## 307. Range Sum Query - Mutable

```cpp
class NumArray {
public:
    NumArray(vector<int> nums) {
        data.resize(nums.size());
        bit.resize(nums.size() + 1);
        for (int i = 0; i < nums.size(); ++i) {
            update(i, nums[i]);
        }
    }

    void update(int i, int val) {
        int diff = val - data[i];
        for (int j = i + 1; j < bit.size(); j += (j & -j)) {
            bit[j] += diff;
        }
        data[i] = val;
    }

    int sumRange(int i, int j) {
        return getSum(j + 1) - getSum(i);
    }

    int getSum(int i) {
        int res = 0;
        for (int j = i; j > 0; j -= (j&-j)) {
            res += bit[j];
        }
        return res;
    }

private:
    vector<int> data, bit;
};
```


## 4. Median of Two Sorted Arrays

求两个有序数组的中位数，限制时间复杂度为 O(log (m+n))

1. 二分法+递归:
   - 假设两个有序数组的长度分别为 m 和 n，找第 $(m+n+1) / 2$ 个，和 $(m+n+2) / 2$ 个，然后求其平均值即可
   - 在两个有序数组中找到第 $K$ 个元素，分别在 nums1 和 nums2 中查找第 $K/2$ 个元素，由于两个数组的长度不定，所以有可能某个数组没有第 $K/2$ 个数字
   - 如果不存在第 K/2 个数字，赋值上一个整型最大值
   - 如果第一个数组的第 K/2 个数字小的话，那么说明要找的数字肯定不在 nums1 中的前 K/2 个数字，可以将其淘汰
   - 当某一个数组的起始位置大于等于其数组长度时，说明其所有数字均已经被淘汰了，相当于一个空数组，那么实际上就变成了在另一个数组中找数字，直接就可以找出来了
   - 如果 $K=1$ 的话，只要比较 nums1 和 nums2 的起始位置 i 和 j 上的数字即可
2. 二分法+迭代
   - 中位数其实就是把一个有序数组分为长度相等的两段，然后取前半段的最大值和后半段的最小值的平均数
   - 使用 L 表示分割点左边的数字，R 表示分割点右边的数字，则对于 [1 3 5 7] 来说，L=3，R=5。对于 [1 3 4 5 7] 来说，L=4，R=4
   - $idx(L)= (N-1)/2$，$idx(R) = N/2$，idx 表示 Index of，对应下标。中位数可以表示为 $(L + R) / 2 = (A[(N - 1) / 2] + A[N / 2]) / 2$
   - 为了统一数组长度为奇数和偶数的情况，在每个数字的两边都加上一个特殊字符 `#`

```cpp
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size(), left = (m + n + 1) / 2, right = (m + n + 2) / 2;
        return (findKth(nums1, 0, nums2, 0, left) + findKth(nums1, 0, nums2, 0, right)) / 2.0;
    }

    int findKth(vector<int>& nums1, int i, vector<int>& nums2, int j, int k) {
        if (i >= nums1.size()) return nums2[j + k - 1];
        if (j >= nums2.size()) return nums1[i + k - 1];
        if (k == 1) return min(nums1[i], nums2[j]);
        int midVal1 = (i + k / 2 - 1 < nums1.size()) ? nums1[i + k / 2 - 1] : INT_MAX;
        int midVal2 = (j + k / 2 - 1 < nums2.size()) ? nums2[j + k / 2 - 1] : INT_MAX;
        if (midVal1 < midVal2) {
            return findKth(nums1, i + k / 2, nums2, j, k - k / 2);
        } else {
            return findKth(nums1, i, nums2, j + k / 2, k - k / 2);
        }
    }
};
```

```cpp
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if (m < n) return findMedianSortedArrays(nums2, nums1);
        if (n == 0) return ((double)nums1[(m - 1) / 2] + (double)nums1[m / 2]) / 2.0;
        int left = 0, right = n * 2;
        while (left <= right) {
            int mid2 = (left + right) / 2;
            int mid1 = m + n - mid2;
            double L1 = mid1 == 0 ? INT_MIN : nums1[(mid1 - 1) / 2];
            double L2 = mid2 == 0 ? INT_MIN : nums2[(mid2 - 1) / 2];
            double R1 = mid1 == m * 2 ? INT_MAX : nums1[mid1 / 2];
            double R2 = mid2 == n * 2 ? INT_MAX : nums2[mid2 / 2];
            if (L1 > R2) left = mid2 + 1;
            else if (L2 > R1) right = mid2 - 1;
            else return (max(L1, L2) + min(R1, R2)) / 2;
        }
        return -1;
    }
};
```

## 321. Create Maximum Number

给定两个无序数组，从两个数组中共挑出 k 个数，数字之间的相对顺序不变，求能组成的最大的数字。

由于k的大小不定，所以有三种可能：

第一种是当k为0时，两个数组中都不取数。

第二种是当k不大于其中任意一个数组的长度时，这种情况下，有可能只从一个数组中取数，或者两个都取一些。

第三种情况是k大于其中任意一个数组的长度，则需要从两个数组中分别取数，至于每个数组中取几个，每种情况都要考虑到，然后每次更结果即可。

为了同时能处理这三种情况，这里假设从数组 nums1 中取i个数，那么就需要从 nums2 中取 k-i 个数。那么i的范围如何确定呢？从情况二中知道，假如k不大于任意一个数组的长度，那么有可能只从其中一个数组中取k个，就是说可以不从 nums1 中取数，所以 i 最小可以取到0。如果是第三种情况，假设k大于 nums2 的长度，就算把 nums2 中所有的数字都取出来，都无法凑个k个，多余的 k-n2 个数字要从 nums1 中来取。所以只要比较 0 和 k-n2 的大小，取较大的为i的起始范围。那么i最大能到多大呢，还是要看 k 和 n1 的大小，如果 k 小于等于 n1，那么只需要取k个就行了，如果k大于 n1，那么只能在 nums1 中取 n1 个，多余的要到 nums2 中取。

好，现在知道了分别要从两个数组中取数字的情况，这里希望从 nums1 中取出的i个数字是最大的组合，同理，从 nums2 中取出的 k-i 个也是最大的数字组合。如何才能取出最大的组合呢？比如当前数组长度为n，需要取出k个数字，定义一个变量 drop = n - k，表示需要丢弃的数字的个数，遍历数组中的数字，进行下列循环，如果此时 drop 为整数，且结果数组长度不为0，结果数组的尾元素小于当前遍历的元素，则去掉结果数组的尾元素，此时 drop 自减1，重复循环直至上述任意条件不满足为止，然后把当前元素加入结果数组中，最后返回结果数组中的前k个元素。

现在分别从 nums1 中取出了i个最大组合的数字，从 nums2 中取出了 k-i 个最大组合的数字，最后一步就是需要将两个取出的数组混合排序成一个数组，小数组中各自的数字之间的相对顺序不变。对于两个数组的混合，要比较了两个数组的大小（按元素比较），然后从当前比较大的数组里取头一个元素，然后删除头元素到下次再接着比较，直到两个数组都为空停止。

```cpp
class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> res;
        for (int i = max(0, k - n2); i <= min(k, n1); ++i) {
            res = max(res, mergeVector(maxVector(nums1, i), maxVector(nums2, k - i)));
        }
        return res;
    }

    vector<int> maxVector(vector<int>& nums, int k) {
        int drop = (int)nums.size() - k;
        vector<int> res;
        for (int num : nums) {
            while (drop > 0 && !res.empty() && res.back() < num) {
                res.pop_back();
                --drop;
            }
            res.push_back(num);
        }
        res.resize(k);
        return res;
    }

    vector<int> mergeVector(vector<int> nums1, vector<int> nums2) {
        vector<int> res;
        while (!nums1.empty() || !nums2.empty()) {
            vector<int> &tmp = (nums1 > nums2) ? nums1 : nums2;
            res.push_back(tmp[0]);
            tmp.erase(tmp.begin());
        }
        return res;
    }
};
```

## 115 (溢出存疑)

## 398 (TLE)

## 332. Reconstruct Itinerary

给定飞机票建立一个行程单，如果有多种方法，取其中字母顺序小的那种方法。本质是有向图的边遍历。

1. 邻接链表+multiset：建图，从节点 JFK 开始遍历，只要当前节点映射的 multiset 里有节点，取出这个节点，将其在 multiset 里删掉，然后继续递归遍历这个节点，由于题目中限定了一定会有解，那么等图中所有的multiset中都没有节点的时候，我们把当前节点存入结果中，然后再一层层回溯回去，将当前节点都存入结果，那么最后我们结果中存的顺序和我们需要的相反的，我们最后再翻转一下即可，参见代码如下：

## 315. Count of Smaller Numbers After Self

返回数组中每个元素右边比他小的元素个数。

1. 二分搜索法：将给定数组从最后一个开始，用二分法插入到一个新的数组，该数字在新数组中的坐标就是原数组中其右边所有较小数字的个数。时间复杂度 O(nlogn)，空间复杂度 O(n)。
2. 二分搜索树：加一个变量 smaller 来记录比当前结点值小的所有结点的个数，每插入一个结点，会判断其和根结点的大小，如果新的结点值小于根结点值，则其会插入到左子树中，此时要增加根结点的 smaller，并继续递归调用左子结点的 insert。如果结点值大于根结点值，则需要递归调用右子结点的 insert 并加上根结点的 smaller，并加 1。

```cpp
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> t, res(nums.size());
        for (int i = nums.size() - 1; i >= 0; --i) {
            int left = 0, right = t.size();
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (t[mid] >= nums[i]) right = mid;
                else left = mid + 1;
            }
            res[i] = right;
            t.insert(t.begin() + right, nums[i]);
        }
        return res;
    }
};
```

```cpp
class Solution {
public:
    struct Node {
        int val, smaller;
        Node *left, *right;
        Node(int v, int s) : val(v), smaller(s), left(NULL), right(NULL) {}
    };
    int insert(Node*& root, int val) {
        if (!root) return (root = new Node(val, 0)), 0;
        if (root->val > val) return root->smaller++, insert(root->left, val);
        return insert(root->right, val) + root->smaller + (root->val < val ? 1 : 0);
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res(nums.size());
        Node *root = NULL;
        for (int i = nums.size() - 1; i >= 0; --i) {
            res[i] = insert(root, nums[i]);
        }
        return res;
    }
};
```
