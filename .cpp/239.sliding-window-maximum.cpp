/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
// 2020-11-24 submission (multiset)
// 51/51 cases passed
// Runtime: 745 ms, faster than 12.41% of C++ online submissions.
// Memory Usage: 211.9 MB, less than 8.42% of C++ online submissions.
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        multiset<int> st;
        for (int i = 0; i < nums.size(); i++) {
            if (i >= k) st.erase(st.find(nums[i-k]));
            st.insert(nums[i]);
            if (i + 1 >= k) res.push_back(*st.rbegin());
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2023-02-10 submission (priority queue)
// 51/51 cases passed
// Runtime: 398 ms, faster than 38.56% of C++ online submissions.
// Memory Usage: 148.9 MB, less than 26.74% of C++ online submissions.
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < nums.size(); ++i) {
            while (!q.empty() && q.top().second <= i - k) q.pop();
            q.push({nums[i], i});
            if (i >= k - 1) res.push_back(q.top().first);
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2020-11-24 submission (deque)
// 51/51 cases passed
// Runtime: 281 ms, faster than 92.4% of C++ online submissions.
// Memory Usage: 134.8 MB, less than 66.21% of C++ online submissions.
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> q;
        for (int i = 0; i < nums.size(); i++) {
            if (!q.empty() && q.front()==i-k) q.pop_front();
            while(!q.empty() && nums[q.back()] <= nums[i]) q.pop_back();
            q.push_back(i);
            if (i + 1 >= k) res.push_back(nums[q.front()]);
        }
        return res;
    }
};
// @lc code=end
