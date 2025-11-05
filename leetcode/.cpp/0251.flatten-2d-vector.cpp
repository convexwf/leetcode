/*
 * @lc app=leetcode id=251 lang=cpp
 *
 * [251] Flatten 2D Vector
 */

// @lc code=start
// 1. 双指针
class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec) {
        data = vec;
        row = 0;
        col = 0;
    }

    int next() {
        if (!hasNext()) {
            return -1;
        }
        return data[row][col++];
    }

    bool hasNext() {
        while (row < data.size() && col >= data[row].size()) {
            ++row;
            col = 0;
        }
        return row < data.size();
    }

private:
    vector<vector<int>> data;
    int row;
    int col;
};
// @lc code=end

// @lc code=start
// 2. iterator
class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec) {
        for (auto& v : vec) {
            if (!v.empty()) {
                iters.push_back(v.begin());
                ends.push_back(v.end());
            }
        }
        it = iters.begin();
    }

    int next() {
        return *it++;
    }

    bool hasNext() {
        while (it != iters.end() && *it == *ends) {
            ++it;
        }
        return it != iters.end();
    }

private:
    vector<vector<int>::iterator> iters, ends;
    vector<vector<int>::iterator> it;
};
// @lc code=end
