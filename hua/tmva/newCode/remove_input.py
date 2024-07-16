import os

# 文件目录
directory = '/afs/ihep.ac.cn/users/t/turuobing/CMSSW_10_6_20/src/FourTop/hua/tmva/newCode/BDTTrain/v1VLLM600/variableListv0/'  # 请根据实际情况修改

# 要删除的文件序号
files_to_remove = [10, 13, 14, 15, 20, 21, 23, 24, 26, 30, 32, 34, 36, 38, 39, 40, 42, 43, 44, 45, 47, 48, 50, 51]
N = 51

def read_file(filename):
    with open(filename, 'r') as file:
        return file.read().splitlines()


def find_new_strings(file1_contents, file2_contents):
    return list(set(file2_contents) - set(file1_contents))


all_files_contents = []
for i in range(1, N+1):
    filename = os.path.join(directory, f'varibleList_{i}.csv')
    all_files_contents.append(read_file(filename))
print(len(all_files_contents))

new_strings = {}
for i in range(1, N):
    new_strings[i+1] = find_new_strings(all_files_contents[i-1], all_files_contents[i])


strings_to_remove = []
for file_index in files_to_remove:
    strings_to_remove.extend(new_strings[file_index])


final_file_contents = all_files_contents[N-1]
final_file_contents = [line for line in final_file_contents if line not in strings_to_remove]


output_filename = os.path.join(directory, 'varibleList_64_modified.csv')
with open(output_filename, 'w') as file:
    file.write('\n'.join(final_file_contents))

print(f'Modified file saved as {output_filename}')

