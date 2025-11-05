/*
 * @lc app=leetcode id=432 lang=cpp
 *
 * [432] All O`one Data Structure
 */

// @lc code=start
// 1. 哈希表+双向链表
// 2023-11-14 submission
// 18/18 cases passed
// Runtime: 108 ms, faster than 100% of cpp online submissions.
// Memory Usage: 56.3 MB, less than 34.68% of cpp online submissions.
struct DoublyLinkedNode
{
    int freq;
    unordered_set<string> strSet;
    DoublyLinkedNode* prev;
    DoublyLinkedNode* next;

    DoublyLinkedNode(int _freq) : freq(_freq), prev(nullptr), next(nullptr) {
    }

    void insert(string str) {
        strSet.insert(str);
    }

    void erase(string str) {
        strSet.erase(str);
    }

    bool empty() {
        return strSet.empty();
    }

    string getAnyStr() {
        return *strSet.begin();
    }
};

class AllOne {
private:
    DoublyLinkedNode* dummyHead;
    DoublyLinkedNode* dummyTail;
    unordered_map<string, DoublyLinkedNode*> strFreq;

public:
    /** Initialize your data structure here. */
    AllOne() {
        dummyHead = new DoublyLinkedNode(-1);
        dummyTail = new DoublyLinkedNode(-1);
        dummyHead->next = dummyTail;
        dummyTail->prev = dummyHead;
    }

    /** Destructor */
    ~AllOne() {
        DoublyLinkedNode* node = dummyHead;
        while (node) {
            DoublyLinkedNode* next = node->next;
            delete node;
            node = next;
        }
    }

    DoublyLinkedNode* insertNode(DoublyLinkedNode* prev, const int freq) {
        DoublyLinkedNode* node = new DoublyLinkedNode(freq);
        prev->next->prev = node;
        node->next = prev->next;
        prev->next = node;
        node->prev = prev;
        return node;
    }

    void removeNode(DoublyLinkedNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
    }

    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if (!strFreq.count(key)) {
            if (dummyHead->next->freq != 1) {
                insertNode(dummyHead, 1);
            }
            dummyHead->next->insert(key);
            strFreq[key] = dummyHead->next;
        }
        else {
            DoublyLinkedNode* oldNode = strFreq[key];
            int freq = oldNode->freq;
            DoublyLinkedNode* nextNode = oldNode->next;
            if (nextNode->freq != freq + 1) {
                nextNode = insertNode(oldNode, freq + 1);
            }
            // update node
            nextNode->insert(key);
            strFreq[key] = nextNode;
            // remove old node if empty
            oldNode->erase(key);
            if (oldNode->empty()) {
                removeNode(oldNode);
            }
        }
    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (!strFreq.count(key)) {
            return;
        }

        DoublyLinkedNode* oldNode = strFreq[key];
        int freq = oldNode->freq;
        // just remove key if freq is 1
        if (freq == 1) {
            strFreq.erase(key);
        }
        else {
            DoublyLinkedNode* prevNode = oldNode->prev;
            if (prevNode->freq != freq - 1) {
                prevNode = insertNode(oldNode->prev, freq - 1);
            }
            // update node
            prevNode->insert(key);
            strFreq[key] = prevNode;
        }
        // remove old node if empty
        oldNode->erase(key);
        if (oldNode->empty()) {
            removeNode(oldNode);
        }
    }

    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if (dummyTail->prev == dummyHead) {
            return "";
        }
        return dummyTail->prev->getAnyStr();
    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if (dummyTail->prev == dummyHead) {
            return "";
        }
        return dummyHead->next->getAnyStr();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
// @lc code=end
