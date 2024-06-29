/*
 * @lc app=leetcode id=353 lang=cpp
 *
 * [353] Design Snake Game
 */

// @lc code=start
// 1. 队列+哈希表
class SnakeGame {
public:
    int width, height;
    vector<vector<int>> food;
    int foodIndex;
    int score;
    queue<pair<int, int>> snake;
    unordered_set<int> snakeSet;

    SnakeGame(int width, int height, vector<vector<int>> &food) {
        this->width = width;
        this->height = height;
        this->food = food;
        this->foodIndex = 0;
        this->score = 0;
        this->snake.push({0, 0});
        this->snakeSet.insert(0);
    }

    int move(string direction) {
        // get increment of x and y
        int dx = 0, dy = 0;
        if (direction == "U")
            dx = -1;
        else if (direction == "D")
            dx = 1;
        else if (direction == "L")
            dy = -1;
        else if (direction == "R")
            dy = 1;

        // get new head
        pair<int, int> &head = snake.front();
        int x = head.first + dx, y = head.second + dy;
        int newHead = x * width + y;

        // check if new head is valid
        if (x < 0 || x >= height || y < 0 || y >= width || snakeSet.count(newHead)) {
            return -1;
        }

        // check if new head is food
        // if it is, add score and increase snake length
        if (foodIndex < food.size() && x == food[foodIndex][0] && y == food[foodIndex][1]) {
            score++;
            foodIndex++;
        }
        else { // if not, remove tail
            pair<int, int> &tail = snake.back();
            snakeSet.erase(tail.first * width + tail.second);
            snake.pop();
        }

        // add new head
        snake.push({x, y});
        snakeSet.insert(newHead);
        return score;
    }
};
// @lc code=end
