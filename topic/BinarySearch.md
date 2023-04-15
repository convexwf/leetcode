# Binary Search

## Find the target Value in the Sorted Array
Description: 在有序数组中找到指定值
Tips: 范围为$[a, b)$,mid为$(a+b)/2$
```C++
int find(vector<int>& nums, int target) {
    int left = 0, right = nums.size();
    while (left < right) {
        int mid = (left + right) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) left = mid + 1;
        else right = mid;
    }
    return -1;
}
```

## Find the minimum(maximun) value that is close to target value
Description: 在有序数组中找到第一个不小于目标值的数，或者查找最后一个小于目标值的数

```C++

int find(vector<int>& nums, int target) {
    int left = 0, right = nums.size();
    while (left < right) {
        int mid = (left + right) / 2;
        if (nums[mid] < target) left = mid + 1;
        else right = mid;
    }
    return right;
}
```

```C++
// 有序数组中找到最后一个不大于目标值的数
int find(vector<int>& nums, int target) {
    int left = 0, right = nums.size();
    while (left < right) {
        int mid = (left + right) / 2;
        if (nums[mid] <= target) left = mid + 1;
        else right = mid;
    }
    return right;
}
```
