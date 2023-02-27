# !/usr/bin/python3
# -*- coding: utf-8 -*-
# @Project : code
# @FileName : code.py
# @Author : convexwf@gmail.com
# @CreateDate : 2022-08-19 20:04
# @UpdateTime : Todo

import os


def split_block(lines):
    res = []
    unlock = True
    iscode = False
    for idx, line in enumerate(lines):
        if line.startswith('!!!'):
            unlock = False
        if line.startswith('#'):
            res.append([idx])
            unlock = True
        if not unlock:
            continue
        if line.startswith('```cpp'):
            iscode = True
            res[-1].append(idx)
        elif iscode and line.startswith('```'):
            iscode = False
            res[-1].append(idx)
    return res


def get_content(lines, idx):
    print(idx)
    res = []
    res.append(lines[idx[0]].replace('.', ' ').strip().split(' ')[1])
    res.append(lines[idx[0]+2].strip())
    res.append(''.join(lines[idx[0]+4:idx[1]-1]))
    for i in range(1, len(idx), 2):
        res.append(''.join(lines[idx[i]+1:idx[i+1]]))
    return res


def instead_content(content):
    found = False
    content_id = content[0]
    content_desc = content[1]
    content_solution = content[2]
    for code_file in os.listdir('.doc'):
        if code_file.startswith(f'{content_id}.'):
            # print(content_id, code_file)
            with open(f'.doc/{code_file}', 'r', encoding='utf-8') as fp:
                lines = fp.readlines()
            for i, line in enumerate(lines):
                if line.startswith('**题目描述**: undefined'):
                    lines[i] = f'**题目描述**: {content_desc}\n'
                if line.startswith('**解题思路**: undefined'):
                    lines[i] = f'**解题思路**\n\n{content_solution}'
            with open(f'.doc/{code_file}', 'w+', encoding='utf-8', newline='\n') as fp:
                fp.writelines(lines)
            found = True

            break
    return found


def instead_code(content):
    found = False
    content_id = content[0]
    for code_file in os.listdir('.code'):
        if code_file.startswith(f'{content_id}.'):
            with open(f'.code/{code_file}', 'r', encoding='utf-8') as fp:
                lines = fp.readlines()
            start = 0
            end = 0
            end2 = 0
            for i, line in enumerate(lines):
                if line.startswith('class'):
                    start = i
                if line.startswith('};'):
                    end = i
                if line.startswith('// @lc code=end'):
                    end2 = i
            if start > 0:
                lines = lines[:start] + [f'{content[3]}'] + \
                    lines[end+1:end2] + ["// @lc code=end\n"]
                start = 4
            else:
                start = 3
            for code in content[start:]:
                lines.append(f'\n// @lc code=start\n{code}// @lc code=end\n')
            with open(f'.code/{code_file}', 'w+', encoding='utf-8', newline='\n') as fp:
                fp.writelines(lines)
            found = True
    return found


if __name__ == '__main__':

    mode = True

    with open("myCode.md", 'r', encoding='utf-8') as fp:
        lines = fp.readlines()
    idx_list = split_block(lines)

    content_list = []
    for idx in idx_list:
        content_list.append(get_content(lines, idx))
    id_list = [it[0] for it in content_list]
    id_list.sort()
    print(f'All({len(id_list)}): ', ','.join(id_list))

    invalid_id_list = []
    for content_id in id_list:
        exist_flag = False
        for code_file in os.listdir('.code'):
            if code_file.startswith(f'{content_id}.'):
                exist_flag = True
                break
        if not exist_flag:
            invalid_id_list.append(content_id)
    print(f'Invalid({len(invalid_id_list)}): ', ','.join(invalid_id_list))

    if mode:
        for content in content_list:
            result = instead_content(content)
            result = result and instead_code(content)
            if not result:
                print(f'Error: {content[0]}')
