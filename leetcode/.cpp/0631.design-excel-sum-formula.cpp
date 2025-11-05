/*
 * @lc app=leetcode id=631 lang=cpp
 *
 * [631] Design Excel Sum Formula
 */

// @lc code=start
// 1. 模拟
class Excel {
private:
    int height;
    int width;
    vector<int> mat;
    unordered_map<int, vector<pair<int, int>>> sumMap;

    int getIdx(int row, char column) {
        return (row - 1) * width + (column - 'A');
    }

    void updateSum(int idx, int diff) {
        for (const auto& [target, range] : sumMap) {
            for (const auto& [left_top, right_bottom] : range) {
                int left = left_top % width;
                int top = left_top / width;
                int right = right_bottom % width;
                int bottom = right_bottom / width;
                if (left <= idx % width && idx % width <= right && top <= idx / width &&
                    idx / width <= bottom) {
                    mat[target] += diff;
                }
            }
        }
    }

public:
    Excel(int height, char width)
        : height(height),
          width(width - 'A' + 1),
          mat(height * (width - 'A' + 1), 0) {
    }

    void set(int row, char column, int val) {
        int idx = getIdx(row, column);
        updateSum(idx, val - mat[idx]);
        mat[idx] = val;
    }

    int get(int row, char column) {
        int idx = getIdx(row, column);
        return mat[idx];
    }

    int sum(int row, char column, vector<string> numbers) {
        int idx = getIdx(row, column);
        int src = mat[idx];

        int sum = 0;
        for (const auto& number : numbers) {
            int colon = number.find(':');
            if (colon == string::npos) {
                int row = stoi(number.substr(1));
                char column = number[0];
                int idx = getIdx(row, column);
                sumMap[idx].emplace_back({idx, idx});
                sum += mat[idx];
            }
            else {
                int row1 = stoi(number.substr(1, colon - 1));
                char column1 = number[0];
                int row2 = stoi(number.substr(colon + 2, number.size() - colon - 2));
                char column2 = number[colon + 1];
                int left_top = getIdx(row1, column1);
                int right_bottom = getIdx(row2, column2);
                for (int i = row1; i <= row2; ++i) {
                    for (char j = column1; j <= column2; ++j) {
                        int idx = getIdx(i, j);
                        sum += mat[idx];
                    }
                }
                sumMap[left_top].emplace_back({left_top, right_bottom});
            }
        }
        updateSum(idx, sum - src);
    }
};
// @lc code=end
