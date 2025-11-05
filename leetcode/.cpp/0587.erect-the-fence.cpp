/*
 * @lc app=leetcode id=587 lang=cpp
 *
 * [587] Erect the Fence
 */

// @lc code=start
// 1. Graham 扫描法
class Solution {
private:
    struct Point
    {
        int x, y;
        Point(int x, int y) : x(x), y(y) {
        }
    };

public:
    vector<vector<int>> outerTrees(vector<vector<int>> &trees) {
        int n = trees.size();
        if (n <= 3) return trees;

        vector<Point> points;
        for (const vector<int> &tree : trees) {
            points.push_back(Point(tree[0], tree[1]));
        }

        // 1. Find the bottom-left point
        int pivotIndex = 0;
        for (int i = 0; i < n; i++) {
            const Point &p = points[i];
            if (p.y < points[pivotIndex].y ||
                (p.y == points[pivotIndex].y && p.x < points[pivotIndex].x)) {
                pivotIndex = i;
            }
        }

        // 2. Sort points by polar angle
        const Point pivot = points[pivotIndex];
        function<int(const Point &, const Point &, const Point &)> crossProduct =
            [&](const Point &p, const Point &a, const Point &b) {
                return (a.x - p.x) * (b.y - p.y) - (b.x - p.x) * (a.y - p.y);
            };
        sort(points.begin(), points.end(), [&](const Point &a, const Point &b) {
            int cross = crossProduct(pivot, a, b);
            if (cross == 0) {
                return (a.x - pivot.x) * (a.x - pivot.x) + (a.y - pivot.y) * (a.y - pivot.y) <
                       (b.x - pivot.x) * (b.x - pivot.x) + (b.y - pivot.y) * (b.y - pivot.y);
            }
            return cross < 0;
        });

        // 3. Build the convex hull
        vector<Point> hull;
        for (int i = 0; i < n; i++) {
            while (hull.size() >= 2 &&
                   crossProduct(hull[hull.size() - 2], hull[hull.size() - 1], points[i]) > 0) {
                hull.pop_back();
            }
            hull.push_back(points[i]);
        }

        // 4. Format the output
        vector<vector<int>> res;
        for (const Point &p : hull) {
            res.push_back({p.x, p.y});
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2. Andrew 算法
// 2025-02-27 submission
// 88/88 cases passed
// Runtime: 7 ms, faster than 87.11% of cpp online submissions.
// Memory Usage: 25.1 MB, less than 75.96% of cpp online submissions.
class Solution {
private:
    struct Point
    {
        int x, y;
        Point(int x, int y) : x(x), y(y) {
        }
    };

    int crossProduct(const Point &a, const Point &b, const Point &c) {
        return (a.x - b.x) * (c.y - b.y) - (c.x - b.x) * (a.y - b.y);
    }

    vector<Point> buildConvexHull(vector<Point> &points) {
        sort(points.begin(), points.end(),
             [](const Point &a, const Point &b) { return a.x == b.x ? a.y < b.y : a.x < b.x; });

        vector<Point> hull;
        // find the lower hull
        for (int i = 0; i < points.size(); i++) {
            while (hull.size() >= 2 &&
                   crossProduct(hull[hull.size() - 2], hull[hull.size() - 1], points[i]) < 0) {
                hull.pop_back();
            }
            hull.push_back(points[i]);
        }
        // find the upper hull
        for (int i = points.size() - 2, t = hull.size() + 1; i >= 0; i--) {
            while (hull.size() >= t &&
                   crossProduct(hull[hull.size() - 2], hull[hull.size() - 1], points[i]) < 0) {
                hull.pop_back();
            }
            hull.push_back(points[i]);
        }

        hull.pop_back();
        return hull;
    }

public:
    vector<vector<int>> outerTrees(vector<vector<int>> &trees) {
        int n = trees.size();
        if (n <= 3) return trees;

        // Check if all points are collinear
        bool collinear = true;
        int x0 = trees[0][0], y0 = trees[0][1];
        for (int i = 1; i < n; i++) {
            if (trees[i][0] != x0 && trees[i][1] != y0) {
                collinear = false;
                break;
            }
        }
        if (collinear) {
            return trees;
        }

        vector<Point> points;
        for (const vector<int> &tree : trees) {
            points.push_back(Point(tree[0], tree[1]));
        }

        vector<Point> hull = buildConvexHull(points);

        vector<vector<int>> res;
        for (const Point &p : hull) {
            res.push_back({p.x, p.y});
        }
        return res;
    }
};
// @lc code=end
