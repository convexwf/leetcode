/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
// 1. 最大堆
// 2023-02-10 submission
// 51/51 cases passed
// Runtime: 66 ms, faster than 20.28% of cpp online submissions.
// Memory Usage: 153.1 MB, less than 20.64% of cpp online submissions.
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> q;
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            while (!q.empty() && q.top().second <= i - k) {
                q.pop();
            }
            q.push({nums[i], i});
            if (i >= k - 1) {
                res.push_back(q.top().first);
            }
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2. 多重有序集合
// 2020-11-24 submission
// 51/51 cases passed
// Runtime: 745 ms, faster than 12.41% of cpp online submissions.
// Memory Usage: 211.9 MB, less than 8.42% of cpp online submissions.
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        multiset<int> st;
        for (int i = 0; i < nums.size(); i++) {
            if (i >= k) {
                st.erase(st.find(nums[i - k]));
            }
            st.insert(nums[i]);
            if (i + 1 >= k) {
                res.push_back(*st.rbegin());
            }
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 3. 单调队列
// 2020-11-24 submission
// 51/51 cases passed
// Runtime: 281 ms, faster than 92.4% of cpp online submissions.
// Memory Usage: 134.8 MB, less than 66.21% of cpp online submissions.
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> q;
        for (int i = 0; i < nums.size(); ++i) {
            if (!q.empty() && q.front() == i - k) {
                q.pop_front();
            }
            while (!q.empty() && nums[q.back()] < nums[i]) {
                q.pop_back();
            }
            q.push_back(i);
            if (i >= k - 1) {
                res.push_back(nums[q.front()]);
            }
        }
        return res;
    }
};
// @lc code=end
