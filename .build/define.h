#ifndef __DEFINE_H__
#define __DEFINE_H__

#include <stdio.h>
#include <numeric>
#include <limits.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <vector>
#include <queue>
#include <regex>
#include <random>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr)
    {
    }
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

static void split(const string &s, vector<string> &tokens, const string &delimiters = " ")
{
    string::size_type lastPos = s.find_first_not_of(delimiters, 0);
    string::size_type pos = s.find_first_of(delimiters, lastPos);
    while (string::npos != pos || string::npos != lastPos)
    {
        tokens.push_back(s.substr(lastPos, pos - lastPos));
        lastPos = s.find_first_not_of(delimiters, pos);
        pos = s.find_first_of(delimiters, lastPos);
    }
}

vector<int> string_to_vector(const string &s)
{
    vector<int> res;
    vector<string> tokens;
    string delim = "[] ,";
    split(s, tokens, delim);
    for (string token : tokens)
        res.push_back(stoi(token));
    return res;
}

string vector_to_string(const vector<int> &v)
{
    string res = "[";
    for (int i = 0; i < int(v.size()); i++)
    {
        res = res + to_string(v[i]) + ",";
    }
    if (res.length() > 1)
        res.back() = ']';
    else
        res += "]";
    return res;
}

vector<vector<int>> string_to_vector_2D(const string &s)
{
    vector<vector<int>> res;
    vector<string> tokens;
    string delim = "[]";
    split(s, tokens, delim);
    for (string token : tokens)
    {
        if (token == ",")
            continue;
        res.push_back(string_to_vector(token));
    }
    return res;
}

string vector_to_string_2D(const vector<vector<int>> &v)
{
    string res = "[";
    for (int i = 0; i < int(v.size()); i++)
    {
        res = res + vector_to_string(v[i]) + ",";
    }
    if (res.length() > 1)
        res.back() = ']';
    else
        res += "]";
    return res;
}

ListNode *string_to_list(const string &s)
{
    vector<int> arr = string_to_vector(s);
    if (arr.empty())
        return nullptr;
    else
    {
        ListNode *head = new ListNode(arr[0]), *cur = head;
        for (int i = 1; i < int(arr.size()); i++)
        {
            cur->next = new ListNode(arr[i]);
            cur = cur->next;
        }
        return head;
    }
}

string list_to_string(const ListNode *head)
{
    string res = "[";
    while (head)
    {
        res = res + to_string(head->val) + ",";
        head = head->next;
    }
    if (res.length() > 1)
        res.back() = ']';
    else
        res += "]";
    return res;
}

TreeNode *string_to_tree(const string &s)
{
    vector<string> tokens;
    vector<TreeNode *> nodes;
    split(s.substr(1, s.length() - 2), tokens, ",");
    for (string token : tokens)
    {
        if (token == "#")
            nodes.push_back(nullptr);
        else
            nodes.push_back(new TreeNode(stoi(token)));
    }
    int pi = 0, ci = 1;
    while (ci < int(nodes.size()))
    {
        if (!nodes[pi])
        {
            pi += 1;
            ci += 2;
        }
        else
        {
            nodes[pi]->left = nodes[ci++];
            if (ci < int(nodes.size()))
                nodes[pi]->right = nodes[ci++];
            ++pi;
        }
    }
    return nodes.empty() ? nullptr : nodes[0];
}

template<typename T>
ostream &operator<<(ostream &out, vector<T> &_vec)
{
    out << "[";
    for (int i = 0; i < _vec.size(); ++i) {
        out << _vec[i];
        if (i != _vec.size() - 1) out << ",";
    }
    out << "]";
    return out;
}

template<typename T>
ostream &operator<<(ostream &out, vector<vector<T> > &_vec)
{
    out << "[";
    for (int i = 0; i < _vec.size(); ++i) {
        out << _vec[i];
        if (i != _vec.size() - 1) out << ",";
    }
    out << "]";
    return out;
}

// string tree_to_string(TreeNode *t)
// {
//       string res = "[";
//       queue<TreeNode *> q;
//       int cnt = (t == nullptr) ? 0 : 1;
//       if (t)
//             q.push(t);
//       while (!q.empty() && cnt > 0)
//       {
//             if (q.front() != nullptr)
//             {
//                   --cnt;
//                   res += to_string(q.front()->val);
//                   q.push(q.front()->left);
//                   q.push(q.front()->right);
//                   cnt += (int(q.front()->left != nullptr) + int(q.front()->right != nullptr));
//             }
//             else
//             {
//                   res += "#";
//                   q.push(nullptr);
//                   q.push(nullptr);
//             }
//             res += ",";
//             q.pop();
//       }
//       if (res.length() > 1)
//             res.back() = ']';
//       else
//             res += "]";
//       return res;
// }

#endif