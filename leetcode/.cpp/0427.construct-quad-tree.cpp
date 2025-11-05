/*
 * @lc app=leetcode id=427 lang=cpp
 *
 * [427] Construct Quad Tree
 */

// @lc code=start
// 1. dfs
// 2024-01-09 submission
// 22/22 cases passed
// Runtime: 17 ms, faster than 39.33% of cpp online submissions.
// Memory Usage: 24.6 MB, less than 9.2% of cpp online submissions.
/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node*
_bottomRight) { val = _val; isLeaf = _isLeaf; topLeft = _topLeft; topRight = _topRight; bottomLeft =
_bottomLeft; bottomRight = _bottomRight;
    }
};
*/
class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return dfs(grid, 0, 0, grid.size());
    }

private:
    Node* dfs(vector<vector<int>>& grid, int x, int y, int len) {
        if (len == 1) {
            return new Node(grid[x][y], true, nullptr, nullptr, nullptr, nullptr);
        }
        Node* root = new Node();
        Node* topLeft = dfs(grid, x, y, len / 2);
        Node* topRight = dfs(grid, x, y + len / 2, len / 2);
        Node* bottomLeft = dfs(grid, x + len / 2, y, len / 2);
        Node* bottomRight = dfs(grid, x + len / 2, y + len / 2, len / 2);
        if (topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf && bottomRight->isLeaf &&
            topLeft->val == topRight->val && topLeft->val == bottomLeft->val &&
            topLeft->val == bottomRight->val) {
            root->isLeaf = true;
            root->val = topLeft->val;
            delete topLeft;
            delete topRight;
            delete bottomLeft;
            delete bottomRight;
        }
        else {
            root->isLeaf = false;
            root->topLeft = topLeft;
            root->topRight = topRight;
            root->bottomLeft = bottomLeft;
            root->bottomRight = bottomRight;
        }
        return root;
    }
};
// @lc code=end
