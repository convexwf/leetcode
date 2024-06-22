/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start
// 1. 双向链表+哈希表
// 2020-09-18 submission
// 22/22 cases passed
// Runtime: 483 ms, faster than 66.16% of cpp online submissions.
// Memory Usage: 165 MB, less than 82.01% of cpp online submissions.
struct LinkedNode
{
    int key;
    int value;
    struct LinkedNode* next;
    struct LinkedNode* prev;
    explicit LinkedNode(int key, int value) : key(key), value(value), next(nullptr), prev(nullptr) {
    }
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
        if (!cache.count(key))
            return -1;
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
