/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 *
 * https://leetcode.com/problems/lru-cache/description/
 *
 * algorithms
 * Medium (40.40%)
 * Likes:    14506
 * Dislikes: 577
 * Total Accepted:    1.1M
 * Total Submissions: 2.8M
 * Testcase Example:  '["LRUCache","put","put","get","put","get","put","get","get","get"]\n' +
  '[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
 *
 * Design a data structure that follows the constraints of a Least Recently
 * Used (LRU) cache.
 *
 * Implement the LRUCache class:
 *
 *
 * LRUCache(int capacity) Initialize the LRU cache with positive size
 * capacity.
 * int get(int key) Return the value of the key if the key exists, otherwise
 * return -1.
 * void put(int key, int value) Update the value of the key if the key exists.
 * Otherwise, add the key-value pair to the cache. If the number of keys
 * exceeds the capacity from this operation, evict the least recently used
 * key.
 *
 *
 * The functions get and put must each run in O(1) average time complexity.
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
 * [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
 * Output
 * [null, null, null, 1, null, -1, null, -1, 3, 4]
 *
 * Explanation
 * LRUCache lRUCache = new LRUCache(2);
 * lRUCache.put(1, 1); // cache is {1=1}
 * lRUCache.put(2, 2); // cache is {1=1, 2=2}
 * lRUCache.get(1);    // return 1
 * lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
 * lRUCache.get(2);    // returns -1 (not found)
 * lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
 * lRUCache.get(1);    // return -1 (not found)
 * lRUCache.get(3);    // return 3
 * lRUCache.get(4);    // return 4
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= capacity <= 3000
 * 0 <= key <= 10^4
 * 0 <= value <= 10^5
 * At most 2 * 10^5 calls will be made to get and put.
 *
 *
 */

// @lc code=start
// 2020-09-18 submission
// 22/22 cases passed
// Runtime: 483 ms, faster than 66.16% of C++ online submissions.
// Memory Usage: 165 MB, less than 82.01% of C++ online submissions.
struct LinkedNode
{
    int key;
    int value;
    struct LinkedNode* next;
    struct LinkedNode* prev;
    explicit LinkedNode(int key, int value) : key(key), value(value), next(nullptr), prev(nullptr){}
};

class LRUCache {
public:

    LRUCache(int capacity) {
        this->size = 0;
        this->capacity = capacity;
        this->dummyHead = new LinkedNode(0, 0);
        this->dummyTail = new LinkedNode(0, 0);
        this->dummyHead->next = this->dummyTail;
        this->dummyTail->prev = this->dummyHead;
    }

    int get(int key) {
        if (!cache.count(key)) return -1;
        else {
            LinkedNode* node = cache[key];
            this->moveNodeToHead(node);
            return node->value;
        }
    }

    void put(int key, int value) {
        if (cache.count(key)) {
            cache[key]->value = value;
            this->moveNodeToHead(cache[key]);
        }
        else {
            LinkedNode* node = new LinkedNode(key, value);
            this->addNodeToHead(node);
            cache[key] = node;
            ++size;
            while (capacity < size) {
                LinkedNode* tailNode = this->dummyTail->prev;
                cache.erase(tailNode->key);
                this->removeNodeFromList(tailNode);
                --size;
            }
        }
    }

private:
    int addNodeToHead(LinkedNode* node) {
        if (node == nullptr) {
            return -1;
        }
        node->next = this->dummyHead->next;
        this->dummyHead->next = node;
        node->prev = this->dummyHead;
        node->next->prev = node;
        return 0;
    }

    int moveNodeToHead(LinkedNode* node) {
        if (node == nullptr) {
            return -1;
        }
        node->next->prev = node->prev;
        node->prev->next = node->next;
        return addNodeToHead(node);
    }

    int removeNodeFromList(LinkedNode* node) {
        if (node == nullptr) {
            return -1;
        }
        node->next->prev = node->prev;
        node->prev->next = node->next;
        delete node;
        return 0;
    }

private:
    uint32_t size;
    uint32_t capacity;
    struct LinkedNode* dummyHead;
    struct LinkedNode* dummyTail;
    std::unordered_map<int, struct LinkedNode*> cache;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
