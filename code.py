# !/usr/bin/python3
# -*- coding: utf-8 -*-
# @Project : code
# @FileName : code.py
# @Author : convexwf@gmail.com
# @CreateDate : 2022-08-19 20:04
# @UpdateTime : Todo

def split_block(lines):
    res = []
    unlock = True
    for idx, line in enumerate(lines):
        if line.startswith('!'):
            unlock = False
        if line.startswith('#'):
            res.append([idx])
            unlock = True
        if not unlock:
            continue
        if line.startswith('```'):
            res[-1].append(idx)
    return res

def get_content(lines, idx):
    res = []
    res.append(lines[idx[0]].strip().split(' ')[1])
    res.append(lines[idx[0]+2].strip())
    res.append(''.join(lines[idx[0]+4:idx[1]-1]))
    for i in range(1, len(idx), 2):
        res.append(''.join(lines[idx[i]+1:idx[i+1]]))
    return res


if __name__ == '__main__':
    with open("myCode.md", 'r', encoding='utf-8') as fp:
        lines = fp.readlines()
    idx_list = split_block(lines)

    content_list = []
    for idx in idx_list:
        content_list.append(get_content(lines, idx))
    print(','.join([it[0] for it in content_list]))
