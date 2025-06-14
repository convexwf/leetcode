/*
 * @lc app=leetcode id=768 lang=cpp
 *
 * [768] Max Chunks To Make Sorted II
 */

// @lc code=start
// 1. 排序+累计和
// 2025-06-08 submission
// 139/139 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 16.2 MB, less than 55.49% of cpp online submissions.
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> sorted_arr = arr;
        sort(sorted_arr.begin(), sorted_arr.end());

        int count = 0;
        long long prefix_sum = 0, sorted_prefix_sum = 0;

        for (int i = 0; i < arr.size(); ++i) {
            prefix_sum += arr[i];
            sorted_prefix_sum += sorted_arr[i];
            if (prefix_sum == sorted_prefix_sum) {
                count++;
            }
        }

        return count;
    }
};
// @lc code=end

// @lc code=start
// 2. 两次线性遍历
// 2025-06-08 submission
// 139/139 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 16.4 MB, less than 43.77% of cpp online submissions.
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> max_left(n), min_right(n);

        max_left[0] = arr[0];
        for (int i = 1; i < n; ++i) {
            max_left[i] = max(max_left[i - 1], arr[i]);
        }

        min_right[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            min_right[i] = min(min_right[i + 1], arr[i]);
        }

        int chunks = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (max_left[i] <= min_right[i + 1]) {
                ++chunks;
            }
        }

        return chunks + 1; // +1 for the last chunk
    }
};
// @lc code=end

// @lc code=start
// 3. 单调递增栈
// 2025-06-08 submission
// 139/139 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 16.3 MB, less than 55.49% of cpp online submissions.
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> st;
        for (int num : arr) {
            if (st.empty() || st.top() <= num) {
                st.push(num);
            }
            else {
                int max_val = st.top();
                st.pop();
                while (!st.empty() && st.top() > num) {
                    max_val = max(max_val, st.top());
                    st.pop();
                }
                st.push(max_val);
            }
        }
        return st.size();
    }
};
// @lc code=end
