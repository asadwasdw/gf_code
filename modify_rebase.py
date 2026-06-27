import sys

todo_file = sys.argv[1]
with open(todo_file, 'r') as f:
    lines = f.readlines()

new_lines = []
for line in lines:
    new_lines.append(line)
    if line.startswith('pick e4eaa90'):
        new_lines.append('exec git commit --amend -m "mac 2026-06-24 00:13:24"\n')
    elif line.startswith('merge -C d2f3623'):
        new_lines.append('exec git commit --amend -m "mac 2026-06-24 00:14:48"\n')

with open(todo_file, 'w') as f:
    f.writelines(new_lines)
