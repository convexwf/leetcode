# -*- coding : utf-8 -*-
import os

def extract_cpp(file_name):
    lines = open(file_name).read().splitlines()

    problem_info = []

    title = '## ' + lines[3][3:]
    problem_info.append('')
    problem_info.append(title)
    problem_info.append('')

    # 解题思路 （可有可无）
    if '// @lc solution=start' in lines:
        sidx = lines.index('// @lc solution=start')
        eidx = lines.index('// @lc solution=end')
        problem_info.extend(lines[sidx+1:eidx])
        problem_info.append('')

    if '// @lc code=start' not in lines:
        print('Error: {} code not exists'.format(title))

    # 解题代码 （必须有）
    code_start = 0
    while '// @lc code=start' in lines[code_start:]:
        sidx = lines[code_start:].index('// @lc code=start')
        eidx = lines[code_start:].index('// @lc code=end')
        problem_info.append('```C++')
        problem_info.extend(lines[code_start+sidx+1:code_start+eidx])
        problem_info.append('```')
        problem_info.append('')
        code_start += (eidx + 1)

    return '\n'.join(problem_info)

def output(category_name, problems, valid_seq, output_file):
    valid_problems = ['# {}\n'.format(category_name)]
    for problem in problems:
        seq = problem.split('.')[0]
        if int(seq) in valid_seq:
            print(problem)
            problem_info = extract_cpp('./.leetcode/' + problem)
            valid_problems.append(problem_info)

    os.makedirs(os.path.dirname(output_file), exist_ok=True)
    with open(output_file, 'w+', encoding='utf-8') as fp:
        fp.writelines(valid_problems)

if __name__ == '__main__':
    problems = os.listdir('./.leetcode')
    
    filename_dict = {
        'Leetcode' : './001-720.md',
    }
    category_dict = {
        'Leetcode' : list(range(1, 721, 1)),
    }

    for key in filename_dict.keys():
        output(key, problems, category_dict[key], filename_dict[key])
