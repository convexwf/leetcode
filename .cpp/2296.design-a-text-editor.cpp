/*
 * @lc app=leetcode id=2296 lang=cpp
 *
 * [2296] Design a Text Editor
 */

// @lc code=start
struct DoublyLinkedNode
{
    char val;
    DoublyLinkedNode *prev;
    DoublyLinkedNode *next;
    DoublyLinkedNode(char _val) : val(_val), prev(nullptr), next(nullptr) {
    }
};

class TextEditor {
private:
    DoublyLinkedNode *dummyHead;
    DoublyLinkedNode *dummyTail;
    DoublyLinkedNode *cursor;
    int size;

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

// @lc code=start
// 2. 栈/字符串
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
        left = left.substr(0, n - k);
        return k;
    }

    string cursorLeft(int k) {
        int n = left.size();
        k = min(k, n);
        right = left.substr(n - k) + right;
        left = left.substr(0, n - k);
        return left.substr(max(0, n - 10));
    }

    string cursorRight(int k) {
        int n = right.size();
        k = min(k, n);
        left += right.substr(0, k);
        right = right.substr(k);
        return left.substr(max(0, n - 10));
    }

private:
    string left, right;
};
// @lc code=end
