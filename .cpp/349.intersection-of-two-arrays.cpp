/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 */

// @lc code=start
// 2023-01-31 submission
// 55/55 cases passed
// Runtime: 6 ms, faster than 74.78% of C++ online submissions.
// Memory Usage: 10.5 MB, less than 36.47% of C++ online submissions.
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st(nums1.begin(), nums1.end()), res;
        for (auto a : nums2) {
            if (st.count(a)) res.insert(a);
        }
        return vector<int>(res.begin(), res.end());
    }
};
// @lc code=end

// @lc code=start
// 2023-01-31 submission
// 55/55 cases passed
// Runtime: 7 ms, faster than 71.54% of C++ online submissions.
// Memory Usage: 10 MB, less than 79.98% of C++ online submissions.
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        int i = 0, j = 0;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) ++i;
            else if (nums1[i] > nums2[j]) ++j;
            else {
                if (res.empty() || res.back() != nums1[i]) {
                    res.push_back(nums1[i]);
                }
                ++i; ++j;
            }
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2023-01-31 submission
// 55/55 cases passed
// Runtime: 3 ms, faster than 95.79% of C++ online submissions.
// Memory Usage: 10.1 MB, less than 79.98% of C++ online submissions.
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> res;
        sort(nums2.begin(), nums2.end());
        for (auto a : nums1) {
            if (binarySearch(nums2, a)) {
                res.insert(a);
            }
        }
        return vector<int>(res.begin(), res.end());
    }
    bool binarySearch(vector<int> &nums, int target) {
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return true;
            else if (nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        return false;
    }
};
// @lc code=end

// @lc code=start
// 2023-01-31 submission
// 55/55 cases passed
// Runtime: 10 ms, faster than 46.82% of C++ online submissions.
// Memory Usage: 11.3 MB, less than 6.39% of C++ online submissions.
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1(nums1.begin(), nums1.end()), s2(nums2.begin(), nums2.end()), res;
        set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(res, res.begin()));
        return vector<int>(res.begin(), res.end());
    }
};
// @lc code=end