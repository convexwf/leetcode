# 单调栈

[LeetCode Monotone Stack Summary 单调栈小结 - Grandyang - 博客园](https://www.cnblogs.com/grandyang/p/8887985.html)

## 常用用法

比当前元素更大的下一个元素，使用单调递减栈（非严格）。栈中存放的是元素的索引。

```cpp
vector<int> nextGreaterElement(vector<int>& nums) {
    vector<int> res(nums.size(), -1);
    stack<int> st;
    for (int i = 0; i < nums.size(); ++i) {
        while (!st.empty() && nums[st.top()] < nums[i]) {
            res[st.top()] = nums[i];
            st.pop();
        }
        st.push(i);
    }
    return res;
}
```

变形：大于等于当前元素的下一个元素，使用单调递减栈（严格），而且出栈条件需要修改。

```cpp
vector<int> nextGreaterEqualElement(vector<int>& nums) {
    vector<int> res(nums.size(), -1);
    stack<int> st;
    for (int i = 0; i < nums.size(); ++i) {
        while (!st.empty() && nums[st.top()] <= nums[i]) {
            res[st.top()] = nums[i];
            st.pop();
        }
        st.push(i);
    }
    return res;
}
```

小于当前元素的下一个元素，使用单调递增栈（非严格）。

```cpp
vector<int> nextLessElement(vector<int>& nums) {
    vector<int> res(nums.size(), -1);
    stack<int> st;
    for (int i = 0; i < nums.size(); ++i) {
        while (!st.empty() && nums[st.top()] > nums[i]) {
            res[st.top()] = nums[i];
            st.pop();
        }
        st.push(i);
    }
    return res;
}
```

大于当前元素的前一个元素，使用单调递减栈（非严格）。注意遍历顺序。

```cpp
vector<int> prevGreaterElement(vector<int>& nums) {
    vector<int> res(nums.size(), -1);
    stack<int> st;
    for (int i = nums.size() - 1; i >= 0; --i) {
        while (!st.empty() && nums[st.top()] < nums[i]) {
            res[st.top()] = nums[i];
            st.pop();
        }
        st.push(i);
    }
    return res;
}
```

小于当前元素的前一个元素，使用单调递增栈（非严格）。注意遍历顺序。

```cpp
vector<int> prevLessElement(vector<int>& nums) {
    vector<int> res(nums.size(), -1);
    stack<int> st;
    for (int i = nums.size() - 1; i >= 0; --i) {
        while (!st.empty() && nums[st.top()] > nums[i]) {
            res[st.top()] = nums[i];
            st.pop();
        }
        st.push(i);
    }
    return res;
}
```
