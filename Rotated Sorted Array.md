# Rotated Sorted Array

## 33. Search in Rotated Sorted Array

```C++
// 2021-03-18 submission
// Runtime: 4 ms, faster than 80.83% of C++ online submissions for Search in Rotated Sorted Array.
// Memory Usage: 11.2 MB, less than 51.31% of C++ online submissions for Search in Rotated Sorted Array.
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size(), mid = 0;
        while (l < r) {
            mid = l + (r - l) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[l] < nums[mid]) {
                if (nums[l] <= target && target < nums[mid]) r = mid;
                else l = mid + 1;
            }
            else {
                if (nums[mid] < target && target <= nums[r - 1]) l = mid + 1;
                else r = mid;
            }
        }
        return -1;
    }
};
```

## 81. Search in Rotated Sorted Array II

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

## 153. Find Minimum in Rotated Sorted Array

解题思路

1. 这里用中间的值 nums[mid] 和右边界值 nums[right] 进行比较，若数组没有旋转或者旋转点在左半段的时候，中间值是一定小于右边界值的，所以要去左半边继续搜索，反之则去右半段查找，最终返回 nums[right] 即可

```C++
// 2021-03-18 submission
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Find Minimum in Rotated Sorted Array.
// Memory Usage: 10.2 MB, less than 43.53% of C++ online submissions for Find Minimum in Rotated Sorted Array.
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

```C++
// 2021-03-18 submission
// Runtime: 4 ms, faster than 94.90% of C++ online submissions for Find Minimum in Rotated Sorted Array II.
// Memory Usage: 12.2 MB, less than 93.44% of C++ online submissions for Find Minimum in Rotated Sorted Array II.
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
