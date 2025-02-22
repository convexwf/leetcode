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
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        int n = trees.size();
        if (n <= 3) return trees;

        vector<Point> points;
        for (const vector<int>& tree : trees) {
            points.push_back(Point(tree[0], tree[1]));
        }

        // 1. Find the bottom-left point
        int pivotIndex = 0;
        for (int i = 0; i < n; i++) {
            const Point& p = points[i];
            if (p.x < points[pivotIndex].x ||
                (p.x == points[pivotIndex].x && p.y < points[pivotIndex].y)) {
                pivotIndex = i;
            }
        }
        swap(points[0], points[pivotIndex]);

        // 2. Sort points by polar angle
        const Point& pivot = points[0];
        function<int(const Point&, const Point&, const Point&)> crossProduct =
            [&](const Point& pivot, const Point& a, const Point& b) {
                return (a.x - pivot.x) * (b.y - pivot.y) - (b.x - pivot.x) * (a.y - pivot.y);
            };
        sort(points.begin() + 1, points.end(), [&](const Point& a, const Point& b) {
            int cross = crossProduct(pivot, a, b);
            if (cross == 0) {
                return (a.x - pivot.x) * (a.x - pivot.x) + (a.y - pivot.y) * (a.y - pivot.y) <
                       (b.x - pivot.x) * (b.x - pivot.x) + (b.y - pivot.y) * (b.y - pivot.y);
            }
            return cross > 0;
        });

        // 3. Build the convex hull
        stack<Point> hull;
        hull.push(points[0]);
        hull.push(points[1]);
        for (int i = 2; i < n; i++) {
            Point top = hull.top();
            hull.pop();
            while (crossProduct(hull.top(), top, points[i]) < 0) {
                top = hull.top();
                hull.pop();
            }
            hull.push(top);
            hull.push(points[i]);
        }

        // 4. Format the output
        vector<vector<int>> res;
        while (!hull.empty()) {
            Point p = hull.top();
            hull.pop();
            res.push_back({p.x, p.y});
        }
        return res;
    }
};
// @lc code=end
