/*
 * @lc app=leetcode id=281 lang=cpp
 *
 * [281] Zigzag Iterator
 */

// @lc code=start
// 1. 模拟
class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        p1 = 0;
        p2 = 0;
        this->v1 = v1;
        this->v2 = v2;
        flag = 0;
    }

    int next() {
        if (p1 == v1.size()) {
            return v2[p2++];
        }
        if (p2 == v2.size()) {
            return v1[p1++];
        }
        if (flag == 0) {
            flag = 1;
            return v1[p1++];
        }
        else {
            flag = 0;
            return v2[p2++];
        }
    }

    bool hasNext() {
        return p1 < v1.size() || p2 < v2.size();
    }

private:
    int p1, p2;
    vector<int> v1, v2;
    int flag;
};
// @lc code=end
