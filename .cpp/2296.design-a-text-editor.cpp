/*
 * @lc app=leetcode id=2296 lang=cpp
 *
 * [2296] Design a Text Editor
 */

// @lc code=start
// 1. 栈/字符串
// 2025-03-18 submission
// 45/45 cases passed
// Runtime: 52 ms, faster than 87.22% of cpp online submissions.
// Memory Usage: 124.2 MB, less than 49.32% of cpp online submissions.
class TextEditor {
public:
    TextEditor() {
        left = right = "";
    }

    void addText(string text) {
        left += text;
    }

    int deleteText(int k) {
        int n = left.size();
        k = min(k, n);
        left.resize(n - k);
        return k;
    }

    string cursorLeft(int k) {
        int n = left.size();
        k = min(k, n);
        for (int i = 0; i < k; i++) {
            right += left.back();
            left.pop_back();
        }
        return seekLeft(10);
    }

    string cursorRight(int k) {
        int n = right.size();
        k = min(k, n);
        for (int i = 0; i < k; i++) {
            left += right.back();
            right.pop_back();
        }
        return seekLeft(10);
    }

    string seekLeft(int k) {
        int n = left.size();
        return left.substr(max(0, n - k));
    }

private:
    string left, right;
};
// @lc code=end

// @lc code=start
// 2. 双向链表
// 2025-03-18 submission
// 45/45 cases passed
// Runtime: 415 ms, faster than 13.70% of cpp online submissions.
// Memory Usage: 289.78 MB, less than 28.77% of cpp online submissions.
class TextEditor {
public:
    TextEditor() {
        dummyHead = new DoublyLinkedNode('#');
        dummyTail = new DoublyLinkedNode('#');
        dummyHead->next = dummyTail;
        dummyTail->prev = dummyHead;
        cursor = dummyTail;
        size = 0;
    }

    void addText(string text) {
        for (char c : text) {
            DoublyLinkedNode *node = new DoublyLinkedNode(c);
            node->prev = cursor->prev;
            node->next = cursor;
            cursor->prev->next = node;
            cursor->prev = node;
            size++;
        }
    }

    int deleteText(int k) {
        int cnt = 0;
        while (k-- && cursor->prev != dummyHead) {
            DoublyLinkedNode *node = cursor->prev;
            node->prev->next = cursor;
            cursor->prev = node->prev;
            delete node;
            cnt++;
            size--;
        }
        return cnt;
    }

    string seekLeft(int k) {
        string res;
        DoublyLinkedNode *node = cursor;
        for (int i = 0; i < min(10, size); i++) {
            if (node->prev == dummyHead) {
                break;
            }
            res = node->prev->val + res;
            node = node->prev;
        }
        return res;
    }

    string cursorLeft(int k) {
        string res;
        while (k-- && cursor->prev != dummyHead) {
            cursor = cursor->prev;
        }
        return seekLeft(10);
    }

    string cursorRight(int k) {
        string res;
        while (k-- && cursor != dummyTail) {
            cursor = cursor->next;
        }
        return seekLeft(10);
    }

private:
    struct DoublyLinkedNode
    {
        char val;
        DoublyLinkedNode *prev;
        DoublyLinkedNode *next;
        DoublyLinkedNode(char _val) : val(_val), prev(nullptr), next(nullptr) {
        }
    };
    DoublyLinkedNode *dummyHead;
    DoublyLinkedNode *dummyTail;
    DoublyLinkedNode *cursor;
    int size;
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */
// @lc code=end
