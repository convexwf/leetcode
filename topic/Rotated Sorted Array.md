# Rotated Sorted Array

[LeetCode Binary Search Summary 二分搜索法小结 - Grandyang - 博客园](https://www.cnblogs.com/grandyang/p/6854825.html)

## 33. Search in Rotated Sorted Array

在旋转数组中搜索一个给定值，返回坐标，若不存在返回 -1，数组中*无*重复值。

1. 二分搜索
   - 如果中间的数小于最右边的数，则右半段是有序的，若中间数大于最右边数，则左半段是有序的，
   - 在有序的半段里用首尾两个数来判断目标值是否在这一区域内，这样就可以确定保留哪半边。
   - 为什么一定要用中间的数字跟最右边的比较？能不能和最左边进行比较？
    二分搜索中，nums[mid] 和 nums[left] 有可能相等，比如数组中只有两个元素。由于只有两个数字且 nums[mid] 不等于 target，target 只有可能在右半边出现，最好的方法就是让其无法进入左半段，就需要左半段是有序的，而且由于一定无法同时满足 nums[left] <= target && nums[mid] > target，因为 nums[left] 和 nums[mid] 相等，同一个数不可能同时大于等于 target，又小于 target。由于这个条件不满足，则直接进入右半段继续搜索即可，所以等于的情况要加到 nums[mid] > nums[left] 的情况中，变成大于等于。

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] < nums[right]) {
                if (nums[mid] < target && target <= nums[right]) left = mid + 1;
                else right = mid - 1;
            } else {
                if (nums[left] <= target && target < nums[mid]) right = mid - 1;
                else left = mid + 1;
            }
        }
        return -1;
    }
};
```

## 81. Search in Rotated Sorted Array II

在旋转数组中搜索一个给定值，返回坐标，若不存在返回 -1，数组中*有*重复值。

1. 二分搜索，参见 <33. Search in Rotated Sorted Array>
   - 如果出现重复值，把最右值向左一位即可继续循环，如果还相同则继续移，直到移到不同值为止

```C++
// 2021-03-18 submission
// Runtime: 8 ms, faster than 64.87% of C++ online submissions for Search in Rotated Sorted Array II.
// Memory Usage: 13.8 MB, less than 98.98% of C++ online submissions for Search in Rotated Sorted Array II.
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size(), mid = 0;
        while (l < r) {
            mid = l + (r - l) / 2;
            if (nums[mid] == target) return true;
            while (l < r && nums[l] == nums[mid]) ++l;
            if (l >= mid) continue;
            if (nums[l] < nums[mid]) {
                if (nums[l] <= target && target < nums[mid]) r = mid;
                else l = mid + 1;
            }
            else if (nums[l] > nums[mid]){
                if (nums[mid] < target && target <= nums[r - 1]) l = mid + 1;
                else r = mid;
            }
        }
        return false;
    }
};
```

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] >= nums[left]) {
                if (nums[left] <= target && nums[mid] > target) right = mid - 1;
                else left = mid + 1;
            } else {
                if (nums[mid] < target && nums[right] >= target) left = mid + 1;
                else right = mid - 1;
            }
        }
        return -1;
    }
};
```

## 153. Find Minimum in Rotated Sorted Array

找出旋转数组的最小值，数组中*无*重复值。

1. 二分搜索
   - 用中间的值 nums[mid] 和右边界值 nums[right] 进行比较，若数组没有旋转或者旋转点在左半段的时候，中间值是一定小于右边界值的，所以要去左半边继续搜索，反之则去右半段查找，最终返回 nums[right] 即可

```C++
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, mid = 0;
        while (l < r) {
            mid = l + (r - l) / 2;
            if (nums[mid] > nums[r]) l = mid + 1;
            else r = mid;
        }
        return nums[l];
    }
};
```

## 154. Find Minimum in Rotated Sorted Array II

找出旋转数组的最小值，数组中*有*重复值，如果有多个最小值返回坐标最小的。

1. 二分搜索，参见 <153. Find Minimum in Rotated Sorted Array>
   - 将右指针左移一位（或者将左指针右移一位），略过一个相同数字

```C++
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, mid = 0;
        while (l < r) {
            while (l < r && nums[l] == nums[r]) ++l;
            mid = l + (r - l) / 2;
            if (nums[mid] <= nums[r]) r = mid;
            else l = mid + 1;
        }
        return nums[l];
    }
};
```

```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = (int)nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) left = mid + 1;
            else if (nums[mid] < nums[right]) right = mid;
            else --right;
        }
        return nums[right];
    }
};
```
