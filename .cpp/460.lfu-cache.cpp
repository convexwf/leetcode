/*
 * @lc app=leetcode id=460 lang=cpp
 *
 * [460] LFU Cache
 */

// @lc code=start
// 1. 双哈希表+双向链表
// 2023-11-03 submission
// 25/25 cases passed
// Runtime: 455 ms, faster than 39.47% of cpp online submissions.
// Memory Usage: 182.9 MB, less than 60.1% of cpp online submissions.
struct LinkedNode
{
    int key;
    int value;
    struct LinkedNode* next;
    struct LinkedNode* prev;
    explicit LinkedNode(int key, int value) : key(key), value(value), next(nullptr), prev(nullptr) {
    }
};

class DoublyLinkedList {
public:
    DoublyLinkedList() : dummyHead(new LinkedNode(-1, -1)), dummyTail(new LinkedNode(-1, -1)) {
        dummyHead->next = dummyTail;
        dummyTail->prev = dummyHead;
    }
    ~DoublyLinkedList() {
        LinkedNode* node = dummyHead;
        while (node != nullptr) {
            LinkedNode* next = node->next;
            delete node;
            node = next;
        }
    }

    bool empty() const {
        return dummyHead->next == dummyTail;
    }

    LinkedNode* getTail() const {
        return dummyTail->prev;
    }

    void addNodeToHead(LinkedNode* node) {
        if (node == nullptr) {
            return;
        }
        node->next = dummyHead->next;
        dummyHead->next = node;
        node->prev = dummyHead;
        node->next->prev = node;
    }

    void removeNodeFromList(LinkedNode* node) {
        if (node == nullptr) {
            return;
        }
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }

private:
    LinkedNode* dummyHead;
    LinkedNode* dummyTail;
};

class LFUCache {
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if (!keyToNode.count(key)) {
            return -1;
        }
        LinkedNode* node = keyToNode[key];
        updateNode(node);
        return node->value;
    }

    void put(int key, int value) {
        if (capacity == 0) {
            return;
        }
        if (!keyToNode.count(key)) {
            if (keyToNode.size() == capacity) {
                removeMinFreqNode();
            }
            LinkedNode* node = new LinkedNode(key, value);
            updateNode(node);
            keyToNode[key] = node;
            minFreq = 1;
        }
        else {
            LinkedNode* node = keyToNode[key];
            node->value = value;
            updateNode(node);
        }
    }

private:
    int capacity;
    int minFreq;
    unordered_map<int, LinkedNode*> keyToNode;
    unordered_map<int, int> keyToFreq;
    unordered_map<int, unique_ptr<DoublyLinkedList>> freqToNodes;

    // update node's freq and move it to the front of the list
    void updateNode(LinkedNode* node) {
        int freq = keyToFreq[node->key];
        // remove node from the old freq list
        if (freqToNodes.count(freq)) {
            freqToNodes[freq]->removeNodeFromList(node);
            if (freqToNodes[freq]->empty()) {
                freqToNodes.erase(freq);
                if (freq == minFreq) {
                    ++minFreq;
                }
            }
        }
        // add node to the new freq list
        ++freq;
        if (!freqToNodes.count(freq)) {
            freqToNodes[freq] = make_unique<DoublyLinkedList>();
        }
        freqToNodes[freq]->addNodeToHead(node);
        keyToFreq[node->key] = freq;
    }

    // remove the node with min freq
    void removeMinFreqNode() {
        if (!freqToNodes.count(minFreq)) {
            return;
        }
        LinkedNode* node = freqToNodes[minFreq]->getTail();
        keyToNode.erase(node->key);
        keyToFreq.erase(node->key);
        freqToNodes[minFreq]->removeNodeFromList(node);
        delete node;
        if (freqToNodes[minFreq]->empty()) {
            freqToNodes.erase(minFreq);
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
