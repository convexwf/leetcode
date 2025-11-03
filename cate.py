# !/usr/bin/python3
# -*- coding: utf-8 -*-
# @Project : algo-solution
# @FileName : cate.py
# @Author : convexwf@gmail.com
# @CreateDate : 2025-11-03 09:09
# @UpdateTime : 2025-11-03 09:09

# | [0001.Two Sum](.doc/0001.two-sum.md) | Easy (52.31%) | array, hash-table, sort | [cpp](.cpp/0001.two-sum.cpp), [rust](.rust/0001.two-sum.rs) |
# | [0002.Add Two Numbers](.doc/0002.add-two-numbers.md) | Medium (42.66%) | linked-list, arithmetic | [cpp](.cpp/0002.add-two-numbers.cpp) |
# | [0003.Longest Substring Without Repeating Characters](.doc/0003.longest-substring-without-repeating-characters.md) | Medium (34.70%) | hash-table, sliding-window | [cpp](.cpp/0003.longest-substring-without-repeating-characters.cpp) |

if __name__ == "__main__":
    selected_category = "linked-list"
    selected_title_list = []
    filename = "convex-notes/CS-notes/leetcode/category.md"
    with open(filename, "r", encoding="utf-8") as fp:
        lines = fp.readlines()
    for line in lines:
        params = line.strip().split("|")
        title_link = params[1].strip()
        # | 0156.Binary Tree Upside Down 🔒 | Medium (62.71%) | binary-tree | [cpp](.cpp/0156.binary-tree-upside-down.cpp) |
        if "🔒" in title_link:
            title = title_link.strip()
        # [0002.Add Two Numbers](.doc/0002.add-two-numbers.md) -> 0002.Add Two Numbers
        else:
            title = title_link[1 : title_link.index("]")].strip()
        category_list = params[3].strip().split(", ")

        if selected_category in category_list or selected_category in title.lower():
            selected_title_list.append(title)
    for title in selected_title_list:
        print(title)
