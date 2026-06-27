import os
import re
import platform

# 自动根据操作系统判断路径
if platform.system() == "Windows":
    template_path = r"d:\\acm\\C++\\code\\mybz.cpp"
    base_dir = r"d:\acm\C++\code"
else:
    template_path = "/Users/gaofeng/Desktop/acm/C++/code/mybz.cpp"
    base_dir = "/Users/gaofeng/Desktop/acm/C++/code"

count = 0
for root, dirs, files in os.walk(base_dir):
    for file in files:
        if file == "settings.json":
            filepath = os.path.join(root, file)
            try:
                with open(filepath, 'r', encoding='utf-8') as f:
                    content = f.read()
                
                new_content = re.sub(
                    r'("cph\.general\.defaultLanguageTemplateFileLocation"\s*:\s*)"[^"]+"',
                    fr'\1"{template_path}"',
                    content
                )
                
                if new_content != content:
                    with open(filepath, 'w', encoding='utf-8') as f:
                        f.write(new_content)
                    count += 1
            except Exception as e:
                pass
print(f"Updated {count} files")
